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

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "gdb_packets.h"
#include "device_specific.h"
#include "result.h"
#include "swd.h"
#include "debug_log.h"

#define ACTION_QUEUE_LENGTH 5

// parameter phase value is:
// 0 == calling for the first time
// negative value (-1, -2,..    = currently not used
// positive value (1, 2, 3,...) = returned value of last call
// return value is:
// 0                            = OK      -> order was executed successfully
// negative value (-1, -2,..    = ERROR   -> something went wrong, order failed
// positive value (1, 2, 3,...) = WORKING -> more steps necessary, call order_handler again
typedef Result (*action_handler)(action_data_typ* action, bool first_call);


static void handle_actions(void);
static Result handle_target_reply_questionmark(action_data_typ* action, bool first_call);
static Result handle_target_reply_write_g(action_data_typ* action, bool first_call);
static Result handle_target_reply_continue(action_data_typ* action, bool first_call);
static Result handle_target_reply_read_memory(action_data_typ* action, bool first_call);
static Result handle_target_reply_write_memory(action_data_typ* action, bool first_call);
static Result handle_target_reply_step(action_data_typ* action, bool first_call);


static volatile uint32_t action_read;
static volatile uint32_t action_write;
static action_handler cur_action;
static action_data_typ action_queue[ACTION_QUEUE_LENGTH];
static const action_handler action_look_up[NUM_ACTIONS] = {
        handle_target_reply_g,
        handle_target_reply_questionmark,
        handle_target_reply_write_g,
        handle_target_reply_continue,
        handle_target_reply_read_memory,
        handle_target_reply_write_memory,
        handle_target_reply_step,
};

#ifdef FEAT_DEBUG_UART
static const char* action_names[NUM_ACTIONS] = {
        "read general register",
};
#endif

static uint32_t timeout_counter;

void target_common_init(void)
{
    action_read = 0;
    action_write = 0;
    cur_action = NULL;
    timeout_counter = 0;
}

void send_part(char* part, uint32_t size, uint32_t offset, uint32_t length)
{
    reply_packet_prepare();
    if(offset + length < size)
    {
        reply_packet_add("m");
    }
    else
    {
        reply_packet_add("l");
    }
    if(offset > size)
    {
        // offset invalid
        reply_packet_prepare();
        reply_packet_add("E 01");
        reply_packet_send();
        return;
    }
    if(offset + length > size)
    {
        length = size - offset;
    }
    reply_packet_add_max(&part[offset], length);
    reply_packet_send();
}

bool target_is_connected(void)
{
    return swd_is_connected();
}

Result target_request_read(uint32_t address)
{
    return swd_read_ap(address);
}

Result target_read_result(Result transaction, uint32_t* data)
{
    return swd_get_result(transaction, data);
}

void target_common_tick(void)
{
    handle_actions();
}

void target_reply_g(void)
{
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = GDB_CMD_G;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        for(;;)
        {
            ;  // TODO
        }
    }
}

void target_reply_questionmark(void)
{
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = GDB_CMD_QUESTIONMARK;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        for(;;)
        {
            ;  // TODO
        }
    }
}

void target_reply_write_g(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = GDB_CMD_WRITE_G;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        for(;;)
        {
            ;  // TODO
        }
    }
}

void target_reply_continue(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = GDB_CMD_CONTINUE;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        for(;;)
        {
            ;  // TODO
        }
    }
}

void target_reply_read_memory(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = GDB_CMD_READ_MEMORY;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        for(;;)
        {
            ;  // TODO
        }
    }
}

void target_reply_write_memory(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = GDB_CMD_WRITE_MEMORY;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        for(;;)
        {
            ;  // TODO
        }
    }
}

void target_reply_step(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = GDB_CMD_STEP;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        for(;;)
        {
            ;  // TODO
        }
    }
}

static Result handle_target_reply_questionmark(action_data_typ* action, bool first_call)
{
    (void) action;
    (void) first_call;
    // TODO report correct reason
    reply_packet_prepare();
    reply_packet_add("S05");
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_write_g(action_data_typ* action, bool first_call)
{
    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_add("OK");
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_continue(action_data_typ* action, bool first_call)
{
    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_read_memory(action_data_typ* action, bool first_call)
{
    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_write_memory(action_data_typ* action, bool first_call)
{
    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_step(action_data_typ* action, bool first_call)
{
    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_send();
    return RESULT_OK;
}

static void handle_actions(void)
{
    Result res;
    bool first;
    if(NULL == cur_action)
    {
        // no action in processing -> try to process next action
        if(action_read != action_write)
        {
            // new action available
            cur_action = action_look_up[action_queue[action_read].action];
            first = true;
            timeout_counter = 0;
        }
        else
        {
            // -> no next order
            return;
        }
    }
    else
    {
        first = false;
    }
    // else we already have an action
    // call handler
    res = (*cur_action)(&action_queue[action_read], first);
    if(ERR_NOT_COMPLETED != res)
    {
        // action is finished
        if(RESULT_OK > res)
        {
            // error
            debug_line("target: error %ld on action %s", res, action_names[action_queue[action_read].action]);
        }
        cur_action = NULL;
        action_read++;
        if(ACTION_QUEUE_LENGTH == action_read)
        {
            action_read = 0;
        }
    }
    else
    {
        // order not done
        timeout_counter++;

        if(100 < timeout_counter)
        {
            debug_line("ERROR: SWD: timeout in running %s order !", action_names[action_queue[action_read].action]);
            timeout_counter = 0;
            // TODO can we do something better than to just skip this command?
            // do not try anymore
            cur_action = NULL;
            action_read++;
            if(ACTION_QUEUE_LENGTH == action_read)
            {
                action_read = 0;
            }
        }
    }
}
