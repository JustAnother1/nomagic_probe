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

#include <stddef.h>
#include "replies.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/result.h"
#include "probe_api/common.h"
#include "probe_api/debug_log.h"


void target_reply_questionmark(void)
{
    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not start reply question mark ! Action queue full!");
        return;
    }
    action->action = GDB_CMD_QUESTIONMARK;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not execute gdb:'?'! adding action failed(%ld)!", res);
        return;
    }
}

void target_reply_step(parameter_typ* parsed_parameter)
{
    // TODO
    (void)parsed_parameter;

    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not start reply step ! Action queue full!");
        return;
    }
    action->action = GDB_CMD_STEP;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not execute gdb:'s'! adding action failed(%ld)!", res);
        return;
    }
}

void target_reply_continue(parameter_typ* parsed_parameter)
{
    // TODO
    (void)parsed_parameter;

    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not start reply continue ! Action queue full!");
        return;
    }
    action->action = GDB_CMD_CONTINUE;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not execute gdb:'c'! adding action failed(%ld)!", res);
        return;
    }
}

bool target_reply_g(void)
{
    // ‘g’
    //    Read general registers.
    //    Reply:
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
    //    ‘E NN’
    //        for an error.

    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not start reply g ! Action queue full!");
        return false;
    }
    action->action = GDB_CMD_G;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not execute gdb:'g'! adding action failed(%ld)!", res);
        return false;
    }
    return true;
}

void target_reply_write_g(parameter_typ* parsed_parameter)
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

    // TODO
    (void)parsed_parameter;

    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not start reply G ! Action queue full!");
        return;
    }
    action->action = GDB_CMD_WRITE_G;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not execute gdb:'G'! adding action failed(%ld)!", res);
        return;
    }
}


void target_reply_read_memory(parameter_typ* parsed_parameter)
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


    // TODO
    (void)parsed_parameter;

    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not start reply read memory ! Action queue full!");
        return;
    }
    action->action = GDB_CMD_READ_MEMORY;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not execute gdb:'m'! adding action failed(%ld)!", res);
        return;
    }
}

void target_reply_write_memory(parameter_typ* parsed_parameter)
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

    // TODO
    (void)parsed_parameter;

    Result res;
    action_data_typ* const action =  book_action_slot();
    if(NULL == action)
    {
        debug_line("ERROR: could not start reply write memory ! Action queue full!");
        return;
    }
    action->action = GDB_CMD_WRITE_MEMORY;
    res = add_target_action(action);
    if(RESULT_OK != res)
    {
        debug_line("ERROR: could not execute gdb:'M'! adding action failed(%ld)!", res);
        return;
    }
}
