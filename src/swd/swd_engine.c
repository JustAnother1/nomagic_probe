/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 */

#include "swd_engine.h"
#include "probe_api/swd.h"
#include "probe_api/result.h"
#include "probe_api/debug_log.h"
#include "swd_protocol.h"
#include <stddef.h>
#include "swd_packets.h"
#include "hal/time_base.h"
#include "swd_packet_bits.h"

#define CMD_QUEUE_LENGTH       5
// comparing against < 0xffffffff is always true -> we want to avoid 0xffffffff as end time of timeout
#define MAX_SAFE_COUNT         0xfffffff0
#define ORDER_TIMEOUT_TIME_MS  100

static void handle_order(void);
static void start_timeout(void);
static bool check_timeout(void);
static void finished_order(void);
static uint32_t next_cmd_result_slot(void);

static volatile uint32_t cmdq_read;
static volatile uint32_t cmdq_write;
static volatile uint32_t cmd_result_data_write;
static command_typ cmd_queue[CMD_QUEUE_LENGTH];
uint32_t cmd_result_data[CMD_QUEUE_LENGTH];
bool cmd_result_data_available[CMD_QUEUE_LENGTH];
static const order_handler order_look_up[NUM_ORDERS] = {
        connect_handler,
        read_handler,
        write_handler,
};

#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
static const char* order_names[NUM_ORDERS] = {
        "connect",
        "read",
        "write",
};
#endif

static order_handler cur_order;
static uint32_t timeout_time;
static bool wait_for_wrap_around;

void swd_init(void)
{
    cmdq_read = 0;
    cmdq_write = 0;
    cmd_result_data_write = 0;
    cur_order = NULL;
    swd_protocol_init();
}

void swd_tick(void)
{
    swd_packet_bits_tick();
    // handle commands
    handle_order();

    // handle things that need to be done regularly / independent of any commands
    swd_protocol_tick();
    swd_packet_bits_tick();
}

Result swd_connect(bool multi, uint32_t target, uint32_t AP_sel)
{
    // TODO protect against concurrent access (cmdq_write)
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        uint32_t tid = next_cmd_result_slot();
        cmd_queue[cmdq_write].order = CMD_CONNECT;
        cmd_queue[cmdq_write].flag = multi;
        cmd_queue[cmdq_write].i_val = target;
        cmd_queue[cmdq_write].i_val_2 = AP_sel;
        cmd_queue[cmdq_write].transaction_id = (Result)tid;
        cmdq_write = next_idx;
        return (Result)tid;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_write_ap(uint32_t addr, uint32_t data)
{
    // TODO protect against concurrent access (cmdq_write)
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        cmd_queue[cmdq_write].order = CMD_WRITE;
        cmd_queue[cmdq_write].address = addr;
        cmd_queue[cmdq_write].i_val = data;
        cmdq_write = next_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_read_ap(uint32_t addr)
{
    // TODO protect against concurrent access (cmdq_write)
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        uint32_t tid = next_cmd_result_slot();
        cmd_queue[cmdq_write].order = CMD_READ;
        cmd_queue[cmdq_write].address = addr;
        cmd_queue[cmdq_write].transaction_id = (Result)tid;
        cmdq_write = next_idx;
        return (Result)tid;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_get_result(Result transaction, uint32_t* data)
{
    if(transaction < CMD_QUEUE_LENGTH)
    {
        if(true == cmd_result_data_available[transaction])
        {
            *data = cmd_result_data[transaction];
            return RESULT_OK;
        }
        else
        {
            return ERR_NOT_COMPLETED;
        }
    }
    else
    {
        // invalid idx (out of bounds)
        return ERR_INVALID_TRANSACTION_ID;
    }
}

void swd_eingine_add_cmd_result(Result idx, uint32_t data)
{
    cmd_result_data[idx] = data;
}

static uint32_t next_cmd_result_slot(void)
{
    uint32_t res = cmd_result_data_write;
    cmd_result_data_available[res] = false;
    cmd_result_data_write++;
    return res;
}

static void handle_order(void)
{
    Result order_state;
    bool first;

    if(NULL == cur_order)
    {
        // no order in processing -> try to process next order
        if(cmdq_read != cmdq_write)
        {
            // new command available
            // debug_line("swd: start order");
            cur_order = order_look_up[cmd_queue[cmdq_read].order];
            start_timeout();
            first = true;
        }
        else
        {
            // -> no next order
            return;
        }
    }
    else
    {
        // we already have an order
        first = false;
    }
    // call handler
    order_state = (*cur_order)(&cmd_queue[cmdq_read], first);
    if(ERR_NOT_COMPLETED != order_state)
    {
        // order is finished
        if(RESULT_OK > order_state)
        {
            // error
            debug_line("swd: error %ld on order %s", order_state, order_names[cmd_queue[cmdq_read].order]);
            if(CMD_CONNECT == cmd_queue[cmdq_read].order)
            {
                cmd_result_data[cmd_queue[cmdq_read].transaction_id] = (uint32_t)ERR_TARGET_ERROR;
            }
        }
        else if(RESULT_OK == order_state)
        {
            // finished successfully
            if(CMD_CONNECT == cmd_queue[cmdq_read].order)
            {
                debug_line("swd: connected");
            }
        }
        else
        {
            debug_line("swd: error %ld on order %s", order_state, order_names[cmd_queue[cmdq_read].order]);
        }
        // debug_line("swd: order %s done (%ld)", order_names[cmd_queue[cmdq_read].order], last_phase);
        finished_order();
    }
    else
    {
        // order not done
        if(true == check_timeout())
        {
            debug_line("ERROR: SWD: timeout in running %s order !", order_names[cmd_queue[cmdq_read].order]);
            // do not try anymore
            if(0 < cmd_queue[cmdq_read].transaction_id)
            {
                // there is a transaction active for this packet, but we do not need that anymore
                cmd_result_data[cmd_queue[cmdq_read].transaction_id] = (uint32_t)ERR_TIMEOUT;
            }
            finished_order();
        }
    }
}

static void finished_order(void)
{
    cur_order = NULL;
    cmdq_read++;
    if(CMD_QUEUE_LENGTH == cmdq_read)
    {
        cmdq_read = 0;
    }
}

static bool check_timeout(void)
{
    uint32_t cur_time = time_get_ms();
    if(true == wait_for_wrap_around)
    {
        if(10 > cur_time)
        {
            // wrap around happened
            wait_for_wrap_around = false;
        }
        // else continue waiting
    }
    else
    {
        if(cur_time > timeout_time)
        {
            // Timeout !!!
            return true;
        }
        // else not a timeout, yet.
    }
    return false;
}

static void start_timeout(void)
{
    uint32_t start_time = time_get_ms();
    timeout_time = start_time + ORDER_TIMEOUT_TIME_MS;
    if(timeout_time > MAX_SAFE_COUNT)
    {
        // an end time of 0xffffffff would not work as all values are always < 0xffffffff
        uint32_t remainder = ORDER_TIMEOUT_TIME_MS - (MAX_SAFE_COUNT - start_time);
        timeout_time = 2 + remainder;
        wait_for_wrap_around = true;
    }
    else if(timeout_time < start_time)
    {
        // wrap around
        wait_for_wrap_around = true;
    }
    else
    {
        wait_for_wrap_around = false;
    }
}
