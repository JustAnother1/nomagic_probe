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
#include "probe_api/time.h"

#define CMD_QUEUE_LENGTH       5
#define ORDER_TIMEOUT_TIME_MS  100

static void handle_order(void);
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
        read_reg_handler,
        write_reg_handler,
        disconnect_handler,
};

#ifdef FEAT_CLI
static const char* order_names[NUM_ORDERS] = {
        "connect",
        "read",
        "write",
};
#endif

static order_handler cur_order;
static timeout_typ to;
static bool has_error;

void swd_init(void)
{
    uint32_t i;
    for(i = 0; i < CMD_QUEUE_LENGTH;i++)
    {
        cmd_result_data_available[i] = false;
        cmd_result_data[i] = 0;
    }
    swd_reset_error_condition();
    swd_protocol_init();
}

void swd_reset_error_condition(void)
{
    cmdq_read = 0;
    cmdq_write = 0;
    cmd_result_data_write = 0;
    cur_order = NULL;
    has_error = false;
    swd_packet_bits_reset_error_condition();
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
    if(true == has_error)
    {
        debug_error("called swd_connect() in error state!");
        return ERR_WRONG_STATE;
    }
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
    if(true == has_error)
    {
        debug_error("swd_write_ap(): not operational !");
        return ERR_WRONG_STATE;
    }
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
        cmd_queue[cmdq_write].transaction_id = 0;
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
    if(true == has_error)
    {
        debug_error("swd_read_ap(): not operational !");
        return ERR_WRONG_STATE;
    }
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

Result swd_read_ap_reg(uint32_t bank, uint32_t reg)
{
    // TODO protect against concurrent access (cmdq_write)
    if(true == has_error)
    {
        debug_error("swd_read_ap_reg(): not operational !");
        return ERR_WRONG_STATE;
    }
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        uint32_t tid = next_cmd_result_slot();
        cmd_queue[cmdq_write].order = CMD_READ_REG;
        cmd_queue[cmdq_write].i_val = bank;
        cmd_queue[cmdq_write].i_val_2 = reg;
        cmd_queue[cmdq_write].transaction_id = (Result)tid;
        cmdq_write = next_idx;
        return (Result)tid;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_write_ap_reg(uint32_t bank, uint32_t reg, uint32_t data)
{
    // TODO protect against concurrent access (cmdq_write)
    if(true == has_error)
    {
        debug_error("swd_write_ap_reg(): not operational !");
        return ERR_WRONG_STATE;
    }
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        cmd_queue[cmdq_write].order = CMD_WRITE_REG;
        cmd_queue[cmdq_write].i_val = bank;
        cmd_queue[cmdq_write].i_val_1 = reg;
        cmd_queue[cmdq_write].i_val_2 = data;
        cmd_queue[cmdq_write].transaction_id = 0;
        cmdq_write = next_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_disconnect(void)
{
    // TODO protect against concurrent access (cmdq_write)
    if(true == has_error)
    {
        debug_error("called swd_disconnect() in error state!");
        return ERR_WRONG_STATE;
    }
    uint32_t next_idx = cmdq_write + 1;
    if(CMD_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(cmdq_read != next_idx)
    {
        uint32_t tid = next_cmd_result_slot();
        cmd_queue[cmdq_write].order = CMD_DISCONNECT;
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
    if(NULL == data)
    {
        return ERR_INVALID_PARAMETER;
    }
    if(transaction < 1)
    {
        // 0 or negative values are not valid
        return ERR_INVALID_TRANSACTION_ID;
    }
    transaction--;
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
    if((idx < 1) || (idx > CMD_QUEUE_LENGTH))
    {
        // 0 or negative values are not valid
        debug_error("swd_eingine_add_cmd_result() : ERR_INVALID_TRANSACTION_ID");
        return;
    }
    idx = idx -1;
    cmd_result_data[idx] = data;
    cmd_result_data_available[idx] = true;
}

static uint32_t next_cmd_result_slot(void)
{
    uint32_t res = cmd_result_data_write; // get next free slot
    cmd_result_data_available[res] = false; // mark slot as used
    cmd_result_data_write++; // move pointer to next free slot
    if(CMD_QUEUE_LENGTH == cmd_result_data_write) // handle wrap around
    {
        cmd_result_data_write = 0;
    }
    res = res + 1;  // to avoid a value of 0
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
            start_timeout(&to, ORDER_TIMEOUT_TIME_MS);
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

    // handle result of order
    if((ERR_NOT_COMPLETED == order_state) || (ERR_QUEUE_FULL_TRY_AGAIN == order_state))
    {
        // order not done
        if(true == timeout_expired(&to))
        {
            debug_error("ERROR: SWD: timeout in running %s order !", order_names[cmd_queue[cmdq_read].order]);
            // do not try anymore
            if(0 < cmd_queue[cmdq_read].transaction_id)
            {
                // there is a transaction active for this packet, but we do not need that anymore
                swd_eingine_add_cmd_result(cmd_queue[cmdq_read].transaction_id, (uint32_t)ERR_TIMEOUT);
            }
            finished_order();
        }
    }
    else
    {
        // order is finished
        if(RESULT_OK > order_state)
        {
            // error
            debug_error("swd: error %ld on order %s", order_state, order_names[cmd_queue[cmdq_read].order]);
            if(0 < cmd_queue[cmdq_read].transaction_id)
            {
                swd_eingine_add_cmd_result(cmd_queue[cmdq_read].transaction_id, (uint32_t)ERR_TARGET_ERROR);
            }
            has_error = true;
        }
        else if(RESULT_OK == order_state)
        {
            // finished successfully
        }
        else
        {
            debug_error("swd: error %ld on order %s", order_state, order_names[cmd_queue[cmdq_read].order]);
            has_error = true;
        }
        // debug_line("swd: order %s done (%ld)", order_names[cmd_queue[cmdq_read].order], last_phase);
        finished_order();
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
