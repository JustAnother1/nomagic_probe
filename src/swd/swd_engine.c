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
#include "swd_protocol.h"
#include <stddef.h>
#include "result_queue.h"

#define CMD_QUEUE_LENGTH  3

// parameter value is:
// 0 == calling for the first time
// negative value (-1, -2,..    = currently not used
// positive value (1, 2, 3,...) = returned value of last call
// return value is:
// 0                            = OK      -> order was executed successfully
// negative value (-1, -2,..    = ERROR   -> something went wrong, order failed
// positive value (1, 2, 3,...) = WORKING -> more steps necessary, call order_handler again
typedef Result (*order_handler)(int32_t phase, command_typ* cmd);


static void handle_order(void);


static swd_engine_state_typ state;
static volatile uint32_t cmdq_read;
static volatile uint32_t cmdq_write;
static command_typ cmd_queue[CMD_QUEUE_LENGTH];
static const order_handler order_look_up[NUM_ORDERS] = {
        connect_handler,
        scan_handler,
        read_handler,
};
static int32_t order_state;
static order_handler cur_order;
static int32_t last_error;

void swd_init(void)
{
    cmdq_read = 0;
    cmdq_write = 0;
    order_state = 0;
    cur_order = NULL;
    last_error = 0;
    state = NOT_CONNECTED;
    swd_protocol_init();
    result_queue_init();
}

void swd_tick(void)
{
    // handle commands
    handle_order();

    // handle things that need to be done regularly / independent of any commands
    switch(state)
    {
        case NOT_CONNECTED: break;
        case BUSY_CONNECTING : break;
        case CONNECTED : swd_protocol_tick(); break;
    }
}

swd_engine_state_typ swd_get_state(void)
{
    return state;
}

Result swd_connect(bool multi, uint32_t target)
{
    if(NOT_CONNECTED == state)
    {
        // TODO protect against concurrent access (cmdq_write)
        uint32_t next_idx = cmdq_write + 1;
        if(CMD_QUEUE_LENGTH == next_idx)
        {
            next_idx = 0;
        }
        if(cmdq_read != next_idx)
        {
            cmd_queue[cmdq_write].order = CONNECT;
            cmd_queue[cmdq_write].flag = multi;
            cmd_queue[cmdq_write].i_val = target;
            state = BUSY_CONNECTING;
            return 0;
        }
        else
        {
            return ERR_QUEUE_FULL_TRY_AGAIN;
        }
    }
    else
    {
        // already connected
        return ERR_WRONG_STATE;
    }
}

Result swd_scan(void)
{
    if(CONNECTED == state)
    {
        // TODO protect against concurrent access (cmdq_write)
        uint32_t next_idx = cmdq_write + 1;
        if(CMD_QUEUE_LENGTH == next_idx)
        {
            next_idx = 0;
        }
        if(cmdq_read != next_idx)
        {
            cmd_queue[cmdq_write].order = SCAN;
            return 0;
        }
        else
        {
            return ERR_QUEUE_FULL_TRY_AGAIN;
        }
    }
    else
    {
        // not connected
        return ERR_NOT_CONNECTED;
    }
}

Result swd_read_ap(uint32_t addr)
{
    if(CONNECTED == state)
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
            Result res = result_queue_get_next_transaction_id(&tid);
            if(0 == res)
            {
                cmd_queue[cmdq_write].order = READ;
                cmd_queue[cmdq_write].i_val = addr;
                cmd_queue[cmdq_write].transaction_id = tid;
                return 0;
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
    else
    {
        return ERR_NOT_CONNECTED;
    }
}

Result swd_get_result(uint32_t transaction, uint32_t* data)
{
    return result_queue_get_result(transaction, data);
}

static void handle_order(void)
{
    if(0 == order_state)
    {
        // no order in processing -> try to process next order
        if(cmdq_read != cmdq_write)
        {
            // new command available
            cur_order = order_look_up[cmd_queue[cmdq_read].order];
        }
        else
        {
            // -> no next order
            return;
        }
    }
    // else we already have an order
    // call handler
    order_state = (*cur_order)(order_state, &cmd_queue[cmdq_read]);
    if(1 > order_state)
    {
        // order is finished
        if(0 > order_state)
        {
            // error
            last_error = order_state;
        }
        // else 0 == OK = finished successfully
        if(CONNECT == cmd_queue[cmdq_read].order)
        {
            state = CONNECTED;
        }
        cmdq_read++;
        if(CMD_QUEUE_LENGTH == cmdq_read)
        {
            cmdq_read = 0;
        }
    }
    // else order not done
}
