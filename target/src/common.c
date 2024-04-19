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
#include "nomagic/walk.h"
#include "time.h"

#define ACTION_QUEUE_LENGTH 5
#define MAX_SAFE_COUNT    0xfffffff0  // comparing against < 0xffffffff is always true -> we want to avoid 0xffffffff as end time of timeout
#define WALK_TIMEOUT_TIME_MS  300


static void handle_actions(void);
static Result handle_target_reply_questionmark(action_data_typ* action, bool first_call);
static Result handle_target_reply_continue(action_data_typ* action, bool first_call);
static Result handle_target_reply_read_memory(action_data_typ* action, bool first_call);
static Result handle_target_reply_write_memory(action_data_typ* action, bool first_call);
static Result handle_target_reply_step(action_data_typ* action, bool first_call);


static volatile uint32_t action_read;
static volatile uint32_t action_write;
static action_handler cur_action;
static action_data_typ action_queue[ACTION_QUEUE_LENGTH];
static const action_handler action_look_up[NUM_ACTIONS] = {
        handle_target_connect,
        handle_target_close_connection,
        handle_target_reply_g,
        handle_target_reply_questionmark,
        handle_target_reply_write_g,
        handle_target_reply_continue,
        handle_target_reply_read_memory,
        handle_target_reply_write_memory,
        handle_target_reply_step,
};

static uint32_t timeout_time;
static bool wait_for_wrap_around;
static bool attached;
static walk_data_typ cur_walk;

void target_init(void)
{
    action_read = 0;
    action_write = 0;
    cur_action = NULL;
    attached = false;
    cur_walk.is_done = true;
    cur_walk.cur_step.is_done = true;
    cur_walk.cur_step.result = RESULT_OK;
    swd_init();
    walk_init();
}

void target_tick(void)
{
    swd_tick();
    if(false == cur_walk.is_done)
    {
        walk_execute(&cur_walk);
    }
    else
    {
        handle_actions();
    }
}

bool cmd_target_info(uint32_t loop)
{
    if(0 == loop)
    {
    debug_line("Target Status");
    debug_line("=============");
    debug_line("target: RP2040");  // TODO target cfg
    // walk state
    if(true == cur_walk.is_done)
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
        debug_line("walk type: %d", cur_walk.type);
        debug_line("step type : %d", cur_walk.cur_step.type);
        debug_line("walk phase: %ld", cur_walk.phase);
        debug_line("step phase : %ld", cur_walk.cur_step.phase);
        debug_line("walk is done : %d", cur_walk.is_done);
        debug_line("step is done : %d", cur_walk.cur_step.is_done);
        debug_line("action_write : %ld", action_write);
        debug_line("action_read : %ld", action_read);
    }
    else
    {
        if(loop -2 < ACTION_QUEUE_LENGTH)
        {
            debug_line("action_queue[%ld].action = %d", loop -2, action_queue[loop-2].action);
            debug_line(".phase = %ld, .intern_0 = %ld, .par_i_0 = %ld",
                       action_queue[loop-2].phase,
                       action_queue[loop-2].intern_0,
                       action_queue[loop-2].par_i_0);
            debug_line(".walk.is_done = %d, .walk.type = %d, .walk.result = %ld, .walk.phase = %ld",
                       action_queue[loop-2].walk->is_done,
                       action_queue[loop-2].walk->type,
                       action_queue[loop-2].walk->result,
                       action_queue[loop-2].walk->phase);
        }
        else
        {
            return true; // true == Done; false = call me again
        }
    }

    return false; // true == Done; false = call me again
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

void target_connect(void)
{
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = SWD_CONNECT;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = SWD_CONNECT;
    }
}

void target_close_connection(void)
{
    // TODO protect against concurrent access (action_write)
    uint32_t next_idx = action_write + 1;
    if(ACTION_QUEUE_LENGTH == next_idx)
    {
        next_idx = 0;
    }
    if(action_read != next_idx)
    {
        action_queue[action_write].action = SWD_CLOSE_CONNECTION;
        action_write = next_idx;
    }
    else
    {
        // can not happen, as gdb can only do one command after the other,...
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = SWD_CLOSE_CONNECTION;
    }
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
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = GDB_CMD_G;
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
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = GDB_CMD_QUESTIONMARK;
    }
}

void target_reply_write_g(char* received, uint32_t length)
{
    // ‘G XX…’
    //     Write general registers. See read registers packet, for a description
    // of the XX… data.
    //    ‘XX…’
    //        Each byte of register data is described by two hex digits.
    // The bytes with the register are transmitted in target byte order.
    // The size of each register and their position within the ‘g’ packet
    // are determined by the target description (see Target Descriptions);
    // in the absence of a target description, this is done using code
    // internal to GDB; typically this is some customary register layout
    // for the architecture in question.
    //        When reading registers, the stub may also return a string of
    // literal ‘x’’s in place of the register data digits, to indicate that
    // the corresponding register’s value is unavailable. For example, when
    // reading registers from a trace frame (see Using the Collected Data),
    // this means that the register has not been collected in the trace frame.
    // When reading registers from a live program, this indicates that the stub
    // has no means to access the register contents, even though the
    // corresponding register is known to exist. Note that if a register truly
    // does not exist on the target, then it is better to not include it in the
    // target description in the first place.
    //        For example, for an architecture with 4 registers of 4 bytes each,
    // the following reply indicates to GDB that registers 0 and 2 are
    // unavailable, while registers 1 and 3 are available, and both have zero
    // value:
    //        -> g
    //        <- xxxxxxxx00000000xxxxxxxx00000000
    //     Reply:
    //     ‘OK’
    //         for success
    //     ‘E NN’
    //         for an error

    // received is something like "G xxxxxxxx00000000xxxxxxxx00000000"

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
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = GDB_CMD_WRITE_G;
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
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = GDB_CMD_CONTINUE;
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
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = GDB_CMD_READ_MEMORY;
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
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = GDB_CMD_WRITE_MEMORY;
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
        debug_line("ERROR: GDB Server action queue full !");
        action_queue[action_write].action = GDB_CMD_STEP;
    }
}

static Result handle_target_reply_questionmark(action_data_typ* action, bool first_call)
{
    // This is sent when connection is first established to query the reason the target halted.
    // The reply is the same as for step and continue. This packet has a special interpretation
    // when the target is in non-stop mode; see Remote Non-Stop.
    // Reply: See Stop Reply Packets, for the reply specifications.
    // https://sourceware.org/gdb/current/onlinedocs/gdb.html/Stop-Reply-Packets.html#Stop-Reply-Packets

    (void) action;
    (void) first_call;
    // TODO report correct reason
    reply_packet_prepare();
    reply_packet_add("S05");
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_continue(action_data_typ* action, bool first_call)
{
    // ‘c [addr]’
    // Continue at addr, which is the address to resume. If addr is omitted, resume at current address.
    // This packet is deprecated for multi-threading support. See vCont packet.
    // Reply: See Stop Reply Packets, for the reply specifications.

    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_read_memory(action_data_typ* action, bool first_call)
{
    // ‘m addr,length’
    //     Read length addressable memory units starting at address addr
    // (see addressable memory unit). Note that addr may not be aligned to any
    // particular boundary.
    //     The stub need not use any particular size or alignment when gathering
    // data from memory for the response; even if addr is word-aligned and
    // length is a multiple of the word size, the stub is free to use byte
    // accesses, or not. For this reason, this packet may not be suitable for
    // accessing memory-mapped I/O devices.
    //     Reply:
    //     ‘XX…’
    //         Memory contents; each byte is transmitted as a two-digit
    // hexadecimal number. The reply may contain fewer addressable memory units
    // than requested if the server was able to read only part of the region of
    // memory.
    //     ‘E NN’
    //         NN is errno

    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_send();
    return RESULT_OK;
}

static Result handle_target_reply_write_memory(action_data_typ* action, bool first_call)
{
    // ‘M addr,length:XX…’
    //     Write length addressable memory units starting at address addr (see
    // addressable memory unit). The data is given by XX…; each byte is
    // transmitted as a two-digit hexadecimal number.
    //     Reply:
    //     ‘OK’
    //         for success
    //     ‘E NN’
    //         for an error (this includes the case where only part of the data
    // was written).

    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_add("OK");
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
            uint32_t start_time = time_get_ms();
            action_queue[action_read].phase = 0;
            action_queue[action_read].walk = &cur_walk;
            cur_action = action_look_up[action_queue[action_read].action];
            first = true;
            timeout_time = start_time + WALK_TIMEOUT_TIME_MS;
            if(timeout_time > MAX_SAFE_COUNT)
            {
                // an end time of 0xffffffff would not work as all values are always < 0xffffffff
                uint32_t remainder = 100 - (MAX_SAFE_COUNT - start_time);
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
        uint32_t cur_time = time_get_ms();

        if(cur_time > timeout_time)
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
