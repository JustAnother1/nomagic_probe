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
#include <string.h>
#include "gdb_packets.h"
#include "result.h"
#include "swd.h"
#include "debug_log.h"
#include "time.h"
#include "hex.h"
#include "common.h"
#include "gdb_packets.h"
#include "actions.h"

#define ACTION_QUEUE_LENGTH     5
#define ACTION_TIMEOUT_TIME_MS  300

static void handle_actions(void);



static volatile uint32_t action_read;
static volatile uint32_t action_write;
static action_handler cur_action;
static action_data_typ action_queue[ACTION_QUEUE_LENGTH];


static timeout_typ to;
static bool attached;
static target_status_typ target_status;

void target_init(void)
{
    action_read = 0;
    action_write = 0;
    cur_action = NULL;
    attached = false;
    memset(&action_queue, 0, sizeof(action_queue));
    target_status = NOT_CONNECTED;
    swd_init();
}

void target_set_status(target_status_typ new_status)
{
    target_status = new_status;
}

void target_tick(void)
{
    swd_tick();
    handle_actions();
    // handle state
    switch(target_status)
    {
        case NOT_CONNECTED:
            break;

        case CONNECTING:
            break;

        case CONNECTED_HALTED:
            break;

        case CONNECTED_RUNNING:
            // check if still running
            break;

        default:
            // should not happen
            target_status = NOT_CONNECTED;
            break;
    }
}

bool common_cmd_target_info(uint32_t loop)
{
    if(0 == loop)
    {
    // walk state
    if(NULL == cur_action)
    {
        debug_line("SWD state: idle");
        return true; // true == Done; false = call me again
    }
    else
    {
        debug_line("SWD state: active");
    }
    }
    else if(1 == loop)
    {
        debug_line("action type: %d", action_queue[action_read].action);
        debug_line("phase: %ld", action_queue[action_read].phase);
        debug_line("sub-phase : %ld", action_queue[action_read].sub_phase);
        debug_line("action is done : %d", action_queue[action_read].is_done);
        debug_line("can run : %d", action_queue[action_read].can_run);
        debug_line("action_write : %ld", action_write);
        debug_line("action_read : %ld", action_read);
    }
    else
    {
        if(loop -2 < ACTION_QUEUE_LENGTH)
        {
            debug_line("action_queue[%ld].action = %d", loop -2, action_queue[loop-2].action);
            debug_line(".phase = %ld, .intern[0] = %ld, .parameter[0] = %ld",
                       action_queue[loop-2].phase,
                       action_queue[loop-2].intern[0],
                       action_queue[loop-2].parameter[0]);
        }
        else
        {
            return true; // true == Done; false = call me again
        }
    }

    return false; // true == Done; false = call me again
}

action_data_typ * book_action_slot(void)
{
    // TODO protect against concurrent access (action_write)
    uint32_t slot_index =  action_write;
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        // we have a free slot!
        action_write = next_idx;
        action_queue[slot_index].can_run = false;
        return &action_queue[slot_index];
    }
    else
    {
        // queue is full
        debug_line("ERROR: target action queue full !");
        return NULL;
    }
}

Result add_target_action(action_data_typ * const action)
{
    action->can_run = true;
    return RESULT_OK;
}

void target_connect(void)
{
    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not connect to target ! Action queue full!");
        return;
    }
    action->action = SWD_CONNECT;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not connect to target ! adding action failed(%ld)!", res);
        return;
    }
}

void target_close_connection(void)
{
    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not disconnect from target ! Action queue full!");
        return;
    }
    action->action = SWD_CLOSE_CONNECTION;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not disconnect from target ! adding action failed(%ld)!", res);
        return;
    }
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
            if(true == action_queue[action_read].can_run)
            {
                // new action available
                action_queue[action_read].phase = 0;
                cur_action = action_look_up[action_queue[action_read].action];
                first = true;
                start_timeout(&to, ACTION_TIMEOUT_TIME_MS);
            }
            else
            {
                // someone is still filling in the details on this one
                // -> wait for it to complete
                return;
            }
        }
        else
        {
            // no next order -> nothing to do
            return;
        }
    }
    else
    {
        first = false;
    }

    // we now have an action
    // call handler
    res = (*cur_action)(&action_queue[action_read], first);

    if(ERR_NOT_COMPLETED != res)
    {
        // action has finished
        if(RESULT_OK > res)
        {
            // error
            debug_line("target: error %ld on action %d", res, action_queue[action_read].action);
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
        if(true == timeout_expired(&to))
        {
            debug_line("ERROR: target: SWD: timeout in running %d order !", action_queue[action_read].action);
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
