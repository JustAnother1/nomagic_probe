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
#include "result_queue.h"
#include "swd_packets.h"

#define CMD_QUEUE_LENGTH  5

static void handle_order(void);


static volatile uint32_t cmdq_read;
static volatile uint32_t cmdq_write;
static command_typ cmd_queue[CMD_QUEUE_LENGTH];
static const order_handler order_look_up[NUM_ORDERS] = {
        connect_handler,
        scan_handler,
        read_handler,
};

#ifdef FEAT_DEBUG_UART
static const char* order_names[NUM_ORDERS] = {
        "connect",
        "scan",
        "read",
};
#endif

static Result order_state;
static order_handler cur_order;
static Result last_error;
static uint32_t timeout_counter;

void swd_init(void)
{
    cmdq_read = 0;
    cmdq_write = 0;
    order_state = 0;
    cur_order = NULL;
    last_error = 0;
    swd_protocol_init();
    result_queue_init();
}

void swd_tick(void)
{
    // handle commands
    handle_order();

    // handle things that need to be done regularly / independent of any commands
    swd_packets_tick();
    swd_protocol_tick();
}

Result swd_connect(bool multi, uint32_t target)
{
    // TODO protect against concurrent access (cmdq_write)
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        cmd_queue[cmdq_write].order = CMD_CONNECT;
        cmd_queue[cmdq_write].flag = multi;
        cmd_queue[cmdq_write].i_val = target;
        cmdq_write = next_idx;
        return 0;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_scan(void)
{
    // TODO protect against concurrent access (cmdq_write)
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        cmd_queue[cmdq_write].order = CMD_SCAN;
        cmdq_write = next_idx;
        return 0;
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
        uint32_t tid;
        Result res = result_queue_get_next_transaction_id(COMMAND_QUEUE, &tid);
        if(RESULT_OK == res)
        {
            cmd_queue[cmdq_write].order = CMD_READ;
            cmd_queue[cmdq_write].i_val = addr;
            cmd_queue[cmdq_write].transaction_id = tid;
            cmdq_write = next_idx;
            return (Result)tid;
        }
        else
        {
            return res;
        }
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_get_result(Result transaction, uint32_t* data)
{
    return result_queue_get_result(COMMAND_QUEUE, transaction, data);
}

static void handle_order(void)
{
    Result last_phase;
    if(0 == order_state)
    {
        // no order in processing -> try to process next order
        if(cmdq_read != cmdq_write)
        {
            // new command available
            // debug_line("swd: start order");
            cur_order = order_look_up[cmd_queue[cmdq_read].order];
            timeout_counter = 0;
        }
        else
        {
            // -> no next order
            return;
        }
    }
    // else we already have an order
    // call handler
    last_phase = order_state;
    order_state = (*cur_order)(order_state, &cmd_queue[cmdq_read]);
    if(1 > order_state)
    {
        // order is finished
        if(RESULT_OK > order_state)
        {
            // error
            last_error = order_state;
            debug_line("swd: error %ld on order %s", order_state, order_names[cmd_queue[cmdq_read].order]);
        }
        else
        {
            // finished successfully
            if(CMD_CONNECT == cmd_queue[cmdq_read].order)
            {
                debug_line("swd: connected");
            }
        }
        // debug_line("swd: order %s done (%ld)", order_names[cmd_queue[cmdq_read].order], last_phase);
        order_state = 0;
        cmdq_read++;
        if(CMD_QUEUE_LENGTH == cmdq_read)
        {
            cmdq_read = 0;
        }
        timeout_counter = 0;
    }
    else
    {
        // order not done
        if(order_state == last_phase)
        {
            timeout_counter++;
        }
        else
        {
            timeout_counter = 0;
        }
        if(100 < timeout_counter)
        {
            debug_line("ERROR: SWD: timeout in order processing !");
            debug_line("swd: order %s (%ld)", order_names[cmd_queue[cmdq_read].order], last_phase);
            timeout_counter = 0;
            // TODO can we do something better than to just skip this command?
            // do not try anymore
            order_state = 0;
            cmdq_read++;
            if(CMD_QUEUE_LENGTH == cmdq_read)
            {
                cmdq_read = 0;
            }
        }
    }
}
