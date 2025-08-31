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
#include "cfg/serial_cfg.h"
#include "probe_api/common.h"
#include "probe_api/debug_log.h"
#include "probe_api/gdb_error_codes.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "probe_api/result.h"
#include "probe_api/swd.h"
#include "probe_api/time.h"
#include "target.h"
#include "target/common_actions.h"

//action definitions must be after "probe_api/common.h"
#include "cfg/target_actions.h"
#include "probe_api/cortex-m_actions.h"

#define ACTION_TRACE_LENGTH           30
#define ACTION_QUEUE_LENGTH           5
#define ACTION_TIMEOUT_TIME_MS        6000
#define GDB_RUNNING_REPORT_TIMEOUT_MS 500

typedef struct{
    uint32_t action;
    uint32_t phase_in;
    uint32_t phase_out;
    Result result;
} action_trace_typ;


static void handle_actions(void);
static void check_if_still_running(void);
static void report_to_gdb(void);
static action_data_typ * book_action_slot(void);
static Result add_target_action(action_data_typ * const action);

static volatile uint32_t action_read;
static volatile uint32_t action_write;
static action_handler cur_action;
static action_data_typ action_queue[ACTION_QUEUE_LENGTH];

static const action_handler action_look_up[NUM_ACTIONS] = {
        handle_target_connect,                // SWD_CONNECT
        handle_target_close_connection,       // SWD_CLOSE_CONNECTION
#ifdef FEAT_GDB_SERVER
        handle_target_reply_g,                // GDB_CMD_G
        handle_target_reply_questionmark,     // GDB_CMD_QUESTIONMARK
        handle_target_reply_write_g,          // GDB_CMD_WRITE_G
        handle_target_reply_continue,         // GDB_CMD_CONTINUE
        handle_target_reply_read_memory,      // GDB_CMD_READ_MEMORY
        handle_target_reply_write_memory,     // GDB_CMD_WRITE_MEMORY
        handle_target_reply_step,             // GDB_CMD_STEP
        handle_check_target_running,          // CHECK_RUNNING
        handle_target_reply_vFlashDone,       // GDB_CMD_VFLASH_DONE
        handle_target_reply_vFlashErase,      // GDB_CMD_VFLASH_ERASE
        handle_target_reply_vFlashWrite,      // GDB_CMD_VFLASH_WRITE
        handle_target_reply_write_register,   // GDB_CMD_WRITE_REGISTER
#endif
        TARGET_SPECIFIC_ACTION_HANDLERS
};

#ifdef FEAT_CLI
static const char* action_names[NUM_ACTIONS] = {
        "connect",
        "close_connection",
#ifdef FEAT_GDB_SERVER
        "reply_g",
        "reply_questionmark",
        "reply_write_G",
        "reply_continue",
        "reply_read_memory",
        "reply_write_memory",
        "reply_step",
        "check running",
        "flash done",
        "flash erase",
        "flash write",
#endif
        TARGET_SPECIFIC_ACTION_NAMES
};
#endif

static timeout_typ action_to;
static bool attached;
static target_status_typ target_status;
static action_trace_typ trace_buf[ACTION_TRACE_LENGTH];
static uint32_t trace_end;
static timeout_typ report_to;

void common_target_init(void)
{
    action_read = 0;
    action_write = 0;
    cur_action = NULL;
    attached = false;
    trace_end = ACTION_TRACE_LENGTH -1;
    memset(&action_queue, 0, sizeof(action_queue));
    memset(&trace_buf, 0, sizeof(trace_buf));
    target_status = NOT_CONNECTED;
    swd_init();
}

void target_set_status(target_status_typ new_status)
{
    if(new_status != target_status)
    {
        if(CONNECTED_RUNNING == new_status)
        {
            start_timeout(&report_to, GDB_RUNNING_REPORT_TIMEOUT_MS);
        }
        debug_msg("target status changed to ");
        switch(new_status)
        {
        case NOT_CONNECTED:     debug_line("not connected"); break;
        case CONNECTING:        debug_line("connecting"); break;
        case CONNECTED_HALTED:  debug_line("connected halted"); break;
        case CONNECTED_RUNNING: debug_line("connected running"); break;
        default:                debug_line("unknown"); break;
        }
        target_status = new_status;
    }
    // else no change
}

void target_interrupt_execution(void)
{
    if(CONNECTED_RUNNING == target_status)
    {
        target_set_status(CONNECTED_HALTED);
    }
    target_command_halt_cpu();
}

void common_target_tick(void)
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
            check_if_still_running();
            report_to_gdb();
            break;

        default:
            // should not happen
            target_set_status(NOT_CONNECTED);
            break;
    }
}

#ifdef FEAT_CLI
bool common_action_info(uint32_t loop)
{
    if(0 == loop)
    {
        cli_line("available actions:");
        return false;
    }
    if(loop > NUM_ACTIONS)
    {
        cli_line("Done!");
        return true;
    }
    else
    {
        cli_line("%3ld : %20s", loop-1, action_names[loop -1]);
        return false;
    }
}

bool common_cmd_target_info(uint32_t loop)
{
    if(0 == loop)
    {
        // walk state
        if(NULL == cur_action)
        {
            cli_line("SWD state: idle");
            return true; // true == Done; false = call me again
        }
        else
        {
            cli_line("SWD state: active");
        }
    }
    else if(1 == loop)
    {
        cli_line("action type: %d", action_queue[action_read].action);
        cli_line("cur_phase: %ld", action_queue[action_read].cur_phase);
        cli_line("can run : %d", action_queue[action_read].can_run);
        cli_line("action_write : %ld", action_write);
        cli_line("action_read : %ld", action_read);
    }
    else
    {
        if(loop -2 < ACTION_QUEUE_LENGTH)
        {
            cli_line("action_queue[%ld].action = %d", loop -2, action_queue[loop-2].action);
            cli_line(".cur_phase = %ld, .intern[0] = %ld, .parameter[0] = %ld",
                     action_queue[loop-2].cur_phase,
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

bool cmd_target_trace(uint32_t loop)
{
    if(0 == loop)
    {
        cli_line("trace end : %ld", trace_end);
        cli_line("num, action(newest last), phase,   result");
    }
    else
    {
        uint32_t idx;
        if(loop > ACTION_TRACE_LENGTH)
        {
            // printed complete trace buffer
            return true;
        }
        idx = trace_end + loop;

        while(ACTION_TRACE_LENGTH <= idx)
        {
            idx = idx - ACTION_TRACE_LENGTH;
        }

        if(0 != trace_buf[idx].action)
        {
            // print entry
            cli_line("%3ld, %20s,     %ld,   %ld",
                     idx,
                     action_names[trace_buf[idx].action -1], // 0 is a valid action
                     trace_buf[idx].phase_in,
                     trace_buf[idx].result);
        }
        else
        {
            // unused entries (not yet wrapped around)
            cli_line("%3ld, %20s,     %ld,   %ld",
                     idx,
                     "not used",
                     trace_buf[idx].phase_in,
                     trace_buf[idx].result);
        }
    }
    return false; // true == Done; false = call me again
}
#endif

static action_data_typ * book_action_slot(void)
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
        memset(&action_queue[slot_index], 0, sizeof(action_data_typ));
        action_queue[slot_index].can_run = false;
        return &action_queue[slot_index];
    }
    else
    {
        // queue is full
        debug_error("ERROR: target action queue full !");
        return NULL;
    }
}

static Result add_target_action(action_data_typ * const action)
{
    action->can_run = true;
    action->first_call = true;
    return RESULT_OK;
}

bool add_action(action_typ act)
{
    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_error("ERROR: could not add %s ! Action queue full!", action_names[act]);
        return false;
    }
    action->action = act;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_error("ERROR: could not add %s ! adding action failed(%ld)!", action_names[act], res);
        return false;
    }
    return true;
}

bool add_action_with_parameter(action_typ act, parameter_typ* parsed_parameter)
{
    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_error("ERROR: could not add %s ! Action queue full!", action_names[act]);
        return false;
    }
    action->action = act;
    action->gdb_parameter = *parsed_parameter;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_error("ERROR: could not add %s ! adding action failed(%ld)!", action_names[act], res);
        return false;
    }
    return true;
}


void target_connect(void)
{
    add_action(SWD_CONNECT);
    target_command_halt_cpu();  // TODO
}

void target_close_connection(void)
{
    add_action(SWD_CLOSE_CONNECTION);
}

void target_restart_action_timeout(void)
{
    start_timeout(&action_to, ACTION_TIMEOUT_TIME_MS);
}

static void check_if_still_running(void)
{
#ifdef FEAT_GDB_SERVER
    if((NULL == cur_action) && (action_read != action_write))
    {
        add_action(CHECK_RUNNING);
    }
    // else wait until all queued actions have finished.
#endif
}

static void handle_actions(void)
{
    Result res;

    if(true == serial_gdb_is_buffer_full())
    {
        // give the buffer time to drain -> try again next time
        return;
    }

    if(NULL == cur_action)
    {
        // no action in processing -> try to process next action
        if(action_read != action_write)
        {
            if(true == action_queue[action_read].can_run)
            {
                // new action available
                action_queue[action_read].cur_phase = 0;
                cur_action = action_look_up[action_queue[action_read].action];
                debug_line("ACTIONS: starting with action %s !", action_names[action_queue[action_read].action]);
                start_timeout(&action_to, ACTION_TIMEOUT_TIME_MS);
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

    // we now have an action

    // trace call
    if(true == action_queue[action_read].first_call)
    {
        // new action
        trace_end ++;
        if(trace_end == ACTION_TRACE_LENGTH)
        {
            trace_end = 0;
        }
    }
    trace_buf[trace_end].action = action_queue[action_read].action + 1;  // 0 is a valid action
    trace_buf[trace_end].phase_in = action_queue[action_read].cur_phase;

    // call handler
    res = (*cur_action)(&action_queue[action_read]);
    // TODO I don't understand why these line cause an Hard Fault
    // trace_buf[trace_end].phase_out = action_queue[action_read].cur_phase;
    // trace_buf[trace_end].result = res;


    if(ERR_NOT_COMPLETED == res)
    {
        // order not done
        if(true == timeout_expired(&action_to))
        {
            debug_error("ERROR: target: SWD: timeout in running '%s' phase %ld !",
                       action_names[action_queue[action_read].action],
                       action_queue[action_read].cur_phase);
            // TODO can we do something better than to just skip this command?
            reply_packet_prepare();
            reply_packet_add(ERROR_TIMEOUT);
            reply_packet_send();
            // do not try anymore
            cur_action = NULL;
            action_read++;
            if(ACTION_QUEUE_LENGTH == action_read)
            {
                action_read = 0;
            }
        }
        else
        {
            // try again
        }
    }
    else
    {
        // action has finished
#ifdef FEAT_GDB_SERVER
        gdb_is_not_busy_anymore();
#endif
        if(RESULT_OK > res)
        {
            // error
            debug_error("target: error %ld on action %s.%ld",
                       res,
                       action_names[action_queue[action_read].action],
                       action_queue[action_read].cur_phase);
#ifdef FEAT_GDB_SERVER
            if(true == is_gdb_busy())
            {
                reply_packet_send();
                gdb_is_not_busy_anymore();
            }
#endif
        }
        else
        {
            debug_line("ACTIONS: finished with action %s !", action_names[action_queue[action_read].action]);
        }
        cur_action = NULL;
        action_read++;
        if(ACTION_QUEUE_LENGTH == action_read)
        {
            action_read = 0;
        }
    }
}


static void report_to_gdb(void)
{
#ifdef FEAT_GDB_SERVER
    if(CONNECTED_RUNNING == target_status)
    {
        if(true == timeout_expired(&report_to))
        {
            reply_packet_prepare();
            reply_packet_add("O");  // No Output
            reply_packet_send();
            start_timeout(&report_to, GDB_RUNNING_REPORT_TIMEOUT_MS);
        }
        // else  wait
    }
#endif
}

