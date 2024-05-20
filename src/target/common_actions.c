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
#include "probe_api/result.h"
#include "target/common_actions.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "probe_api/debug_log.h"
#include "probe_api/cortex-m.h"
#include "probe_api/swd.h"
#include "target.h"
#include "steps.h"


#define INTERN_RETRY_COUNTER    1
#define INTERN_REGISTER_IDX     2



Result handle_target_connect(action_data_typ* const action, bool first_call)
{
    if(true == first_call)
    {
        debug_line("resetting error condition!");
        swd_reset_error_condition();

        action->parameter[0] = target_is_SWDv2();
        action->parameter[1] = target_get_SWD_core_id(0);  // TODO multi core
        action->parameter[2] = target_get_SWD_APSel(0);  // TODO multi core
        action->phase = 0;
    }

    // disconnect (In case the Chips it is still connected to a previous session)
    if(0 == action->phase)
    {
        return do_disconnect(action);
    }

    if(1 == action->phase)
    {
        return do_get_Result_OK(action);  // TODO do we really need this?
    }

    // connect
    if(2 == action->phase)
    {
        return do_connect(action);
    }

    if(3 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    // write DEBUGEN in DHCSR
    // C_DEBUGEN = 1; C_HALT = b10;
    if(4 == action->phase)
    {
        return do_write_ap(action, DHCSR, DBGKEY | (0xffff & 1) );
    }

    if(5 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    // init DEMCR
    if(6 == action->phase)
    {
        // bit 24: DWTENA:       0= DWT disabled;                 1= DWT enabled.
        // bit 10: VC_HARDERR:   0= haling on HardFault disabled; 1= halting on HardFault enabled.
        // bit 0:  VC_CORERESET: 0= Reset Vector Catch disabled;  1= Reset Vector Catch enabled.
        return do_write_ap(action, DEMCR, (1 << 24) | (1 << 10) | 1 );
    }

    if(7 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    // DHCSR
    // bit 3: C_MASKINTS: 0= do not mask;                       1= Mask PendSV, SysTick and external configurable interrupts.
    // bit 2: C_STEP:     0= single stepping disabled;          1= single stepping enabled.
    // bit 1: C_HALT:     0= Request a halted processor to run; 1= Request a running processor to halt.
    // bit 0: C_DEBUGEN:  0= Halting debug disabled;            1= Halting debug enabled.
    if(8 == action->phase)
    {
        return do_write_ap(action, DHCSR, DBGKEY | (0xffff & 0xf) );
    }

    if(9 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    // TODO add more steps?

    if(10 == action->phase)
    {
        debug_line("connected!");
        target_set_status(CONNECTED_HALTED);  // TODO enable connect without halt
        return RESULT_OK;
    }

    return ERR_WRONG_STATE;
}

Result handle_target_close_connection(action_data_typ* const action, bool first_call)
{
    if(true == first_call)
    {
        debug_line("closing SWD connection !");
        action->phase = 0;
        action->is_done = false;

        Result res = swd_disconnect();
        if(RESULT_OK < res)
        {
            action->intern[0] = (uint32_t)res;
            action->phase = 1;
            action->result = ERR_NOT_COMPLETED;
        }
        else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
        {
            // try again
            action->result = ERR_NOT_COMPLETED;
        }
        else
        {
            // some error
            action->result = res;
            action->is_done = true;
        }

        return action->result;
    }
    else
    {
        uint32_t data;
        Result res = swd_get_result((Result)action->intern[0], &data);
        if(RESULT_OK == res)
        {
            if(RESULT_OK == data)
            {
                action->result = RESULT_OK;
                action->is_done = true;
                debug_line("Disconnected!");
            }
            else
            {
                debug_line("target: SWD disconnect failed ! (Res: %ld)", data);
                action->result = ERR_WRONG_VALUE;
                action->is_done = true;
            }
            target_set_status(NOT_CONNECTED);
        }
        else
        {
            if(ERR_QUEUE_FULL_TRY_AGAIN == res)
            {
                // try again
                action->result = ERR_NOT_COMPLETED;
            }
            else
            {
                // some error
                action->result = res;
                action->is_done = true;
                debug_line("target: SWD disconnect failed ! (%ld)", res);
            }
        }
    }
    return action->result;
}


#ifdef FEAT_GDB_SERVER
Result handle_target_reply_g(action_data_typ* const action, bool first_call)
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

    if(true == first_call)
    {
        reply_packet_prepare();
        action->phase = 0;
        action->intern[INTERN_REGISTER_IDX] = 0;
        action->intern[INTERN_RETRY_COUNTER] = 0;
    }

    // 1. write to DCRSR the REGSEL value and REGWnR = 0
    if(0 == action->phase)
    {
        return do_write_ap(action, DCRSR, action->intern[INTERN_REGISTER_IDX]);
    }

    if(1 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    // 2. read DHCSR until S_REGRDY is 1
    if(2 == action->sub_phase)
    {
        return do_read_ap(action, DHCSR);
    }

    if(3 == action->phase)
    {
        return do_get_Result_data(action);
    }

    if(4 == action->phase)
    {
        if(0 == (action->read_0 & (1<<16)))
        {
            action->intern[INTERN_RETRY_COUNTER]++;
            if(100 < action->intern[INTERN_RETRY_COUNTER])
            {
                // no data available -> read again
                action->phase = 2;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                // too many retries
                debug_line("ERROR: too many retries !");
                action->result = ERR_TIMEOUT;
                action->is_done = true;
                return action->result;
            }
        }
        else
        {
            // data available -> read data
            action->phase++;
        }
    }

    // 3. read data from DCRDR
    if(5 == action->phase)
    {
        return do_read_ap(action, DCRDR);
    }

    if(6 == action->phase)
    {
        return do_get_Result_data(action);
    }

    if(7 == action->phase)
    {
        // this register done, next?
        char buf[9];
        buf[8] = 0;
        int_to_hex(buf, action->read_0, 8);
        reply_packet_add(buf);
        debug_line("read 0x%08lx", action->read_0);
        action->intern[INTERN_REGISTER_IDX] ++;
        action->phase = 0;
        if(17 == action->intern[INTERN_REGISTER_IDX])
        {
            // finished
            reply_packet_send();
            return RESULT_OK;
        }
        else
        {
            // continue with next register
            return ERR_NOT_COMPLETED;
        }
    }

    return ERR_WRONG_STATE;
}


Result handle_target_reply_write_g(action_data_typ* const action, bool first_call)
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

    if(true == first_call)
    {
        reply_packet_prepare();
        action->phase = 1;
        action->intern[INTERN_RETRY_COUNTER] = 0;
        return ERR_NOT_COMPLETED;
    }

    if(1 == action->phase)
    {
        uint32_t i;
        bool found = false;
        for(i = 0; i < action->gdb_parameter->num_memory_locations; i++)
        {
            if(true == action->gdb_parameter->memory[i].has_value)
            {
                // write that value
                found = true;
                action->gdb_parameter->memory[i].has_value = false;
                break;
            }
            // else skip that value, or already done
        }
        if(false == found)
        {
            // no memory location found -> we are done
            reply_packet_add("OK");
            reply_packet_send();
            return RESULT_OK;
        }
        // else
        action->parameter[0] = i;  // select the register to write
        action->parameter[1] = action->gdb_parameter->memory[i].value;
        action->phase = 2;
        return ERR_NOT_COMPLETED;
    }

    // 1. write value to DCRDR.
    if(2 == action->phase)
    {
        return do_write_ap(action, DCRDR, action->parameter[1]);
    }

    if(3 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    // 2. write to DCRSR the REGSEL value and REGWnR = 1
    if(4 == action->phase)
    {
        return do_write_ap(action, DCRSR, action->parameter[0] | (1<<16) ); //  REGWnR = 1
    }

    if(5 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    // 2. read DHCSR until S_REGRDY is 1
    if(6 == action->sub_phase)
    {
        return do_read_ap(action, DHCSR);
    }

    if(7 == action->phase)
    {
        return do_get_Result_data(action);
    }

    if(8 == action->phase)
    {
        if(0 == (action->read_0 & (1<<16)))
        {
            // write not finished
            action->intern[INTERN_RETRY_COUNTER] ++;
            if(100 < action->intern[INTERN_RETRY_COUNTER])
            {
                // write not finished -> read again
                action->phase = 6;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                // too many retries
                debug_line("ERROR: too many retries !");
                action->result = ERR_TIMEOUT;
                action->is_done = true;
                reply_packet_prepare();
                reply_packet_add("E23");
                reply_packet_send();
                return action->result;
            }
        }
        else
        {
            // write finished
            action->phase = 1;
            return ERR_NOT_COMPLETED;
        }
    }

    return ERR_WRONG_STATE;
}

Result handle_target_reply_questionmark(action_data_typ* const action, bool first_call)
{
    (void)action;
    (void)first_call;
    reply_packet_prepare();
    reply_packet_add("S05");
    reply_packet_send();
    return RESULT_OK;
}

Result handle_target_reply_continue(action_data_typ* const action, bool first_call)
{
    (void)action;
    (void)first_call;
    send_unknown_command_reply();
    return RESULT_OK;
}

Result handle_target_reply_read_memory(action_data_typ* const action, bool first_call)
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
#define INTERN_MEMORY_OFFSET     1

    if(true == first_call)
    {
        reply_packet_prepare();
        action->phase = 0;
        action->intern[INTERN_MEMORY_OFFSET] = 0;
    }

    if(0 == action->sub_phase)
    {
        return do_read_ap(action, action->gdb_parameter->address + action->intern[INTERN_MEMORY_OFFSET]*4);
    }

    if(1 == action->phase)
    {
        return do_get_Result_data(action);
    }

    if(2 == action->phase)
    {
        char buf[9];
        buf[8] = 0;
        int_to_hex(buf, action->read_0, 8);
        reply_packet_add(buf);
        debug_line("read 0x%08lx", action->read_0);
        action->intern[INTERN_MEMORY_OFFSET]++;
        action->phase = 1;
        if(action->gdb_parameter->length == action->intern[INTERN_MEMORY_OFFSET])
        {
            // finished
            reply_packet_send();
            return RESULT_OK;
        }
        else
        {
            // continue with next register
            return ERR_NOT_COMPLETED;
        }
    }

    return ERR_WRONG_STATE;
}

Result handle_target_reply_write_memory(action_data_typ* const action, bool first_call)
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

    if(true == first_call)
    {
        reply_packet_prepare();
        action->phase = 1;
        action->intern[0] = action->gdb_parameter->length;
    }

    if(1 == action->phase)
    {
        uint32_t i;
        bool found = false;
        for(i = 0; i < action->gdb_parameter->num_memory_locations; i++)
        {
            if(true == action->gdb_parameter->memory[i].has_value)
            {
                // write that value
                found = true;
                break;
            }
            // else skip that value
        }
        if(false == found)
        {
            // no memory location found -> we are done
            reply_packet_add("OK");
            reply_packet_send();
            return RESULT_OK;
        }
        // else
        action->parameter[0] = action->gdb_parameter->address + i*4;
        action->parameter[1] = action->gdb_parameter->memory[i].value;
        action->phase++;
    }

    if(2 == action->phase)
    {
        return do_write_ap(action, action->parameter[0], action->parameter[1]);
    }

    if(3 == action->phase)
    {
        return do_get_Result_OK(action);
    }

    if(4 == action->phase)
    {
        action->phase = 1;
        // continue with next register
        return ERR_NOT_COMPLETED;
    }

    return ERR_WRONG_STATE;
}

Result handle_target_reply_step(action_data_typ* const action, bool first_call)
{
    (void)action;
    (void)first_call;
    send_unknown_command_reply();
    return RESULT_OK;
}
#endif

