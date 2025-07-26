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
#include <stdbool.h>
#include <string.h>

#include "probe_api/cortex-m.h"  // TODO remove once no cortex-M specific stuff anymore in here
#include "probe_api/debug_log.h"
#include "probe_api/flash_write_buffer.h"
#include "probe_api/gdb_error_codes.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "probe_api/result.h"
#include "probe_api/steps.h"
#include "probe_api/swd.h"
#include "probe_api/util.h"
#include "target/common_actions.h"
#include "target.h"


#define INTERN_RETRY_COUNTER    1
#define INTERN_REGISTER_IDX     2

#ifdef FEAT_GDB_SERVER

#define MAX_MONITOR_LINE_LENGTH         50
static char msg_buf[MAX_MONITOR_LINE_LENGTH];

#endif

// SWD_CONNECT
Result handle_target_connect(action_data_typ* const action)
{
    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        debug_line("resetting error condition!");
        swd_reset_error_condition();
        // connection just opened, we know nothing about the targets state -> initialize
        target_re_init();

        action->cur_phase = 0;
        action->first_call = false;
    }

    // disconnect (In case the Chips it is still connected to a previous session)
    if(0 == action->cur_phase)
    {
        res = step_disconnect();
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(1 == action->cur_phase)
    {
        res = step_get_Result_OK();  // TODO do we really need this?
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // connect
    if(2 == action->cur_phase)
    {
        res = step_connect(target_is_SWDv2(),
                           target_get_SWD_core_id(0), // TODO multi core
                           target_get_SWD_APSel(0)); // TODO multi core
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(3 == action->cur_phase)
    {
        res = step_get_Result_OK();
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    // write DEBUGEN in DHCSR
    // C_DEBUGEN = 1; C_HALT = b10;
    if(4 == action->cur_phase)
    {
        res = step_write_ap(DHCSR, DBGKEY | (1 << DHCSR_C_DEBUGEN_OFFSET) );
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // init DEMCR
    if(5 == action->cur_phase)
    {
        // bit 24: DWTENA:       0= DWT disabled;                 1= DWT enabled.
        // bit 10: VC_HARDERR:   0= haling on HardFault disabled; 1= halting on HardFault enabled.
        // bit 0:  VC_CORERESET: 0= Reset Vector Catch disabled;  1= Reset Vector Catch enabled.
        res = step_write_ap(DEMCR, (1 << 24) | (1 << 10) | 1 );
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // DHCSR
    // bit 3: C_MASKINTS: 0= do not mask;                       1= Mask PendSV, SysTick and external configurable interrupts.
    // bit 2: C_STEP:     0= single stepping disabled;          1= single stepping enabled.
    // bit 1: C_HALT:     0= Request a halted processor to run; 1= Request a running processor to halt.
    // bit 0: C_DEBUGEN:  0= Halting debug disabled;            1= Halting debug enabled.
    if(6 == action->cur_phase)
    {
        res = step_write_ap(DHCSR, DBGKEY
                         | (1 << DHCSR_C_MASKINTS_OFFSET)   // TODO configure ?
                         | (1 << DHCSR_C_HALT_OFFSET)       // TODO configure ?
                         | (1 << DHCSR_C_DEBUGEN_OFFSET) );
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // TODO add more steps?

    if(7 == action->cur_phase)
    {
        debug_line("connected!");
        target_set_status(CONNECTED_HALTED);  // TODO enable connect without halt (configuration)
        return RESULT_OK;
    }

    return ERR_WRONG_STATE;
}

// SWD_CLOSE_CONNECTION
Result handle_target_close_connection(action_data_typ* const action)
{
    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        debug_line("closing SWD connection !");
        action->cur_phase = 0;

        Result res = swd_disconnect();
        if(RESULT_OK < res)
        {
            action->intern[0] = (uint32_t)res;
            action->cur_phase = 1;
            action->first_call = false;
            return ERR_NOT_COMPLETED;
        }
        else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
        {
            // try again
            return ERR_NOT_COMPLETED;
        }
        else
        {
            // some error
            return res;
        }
    }
    else
    {
        uint32_t data;
        Result res = swd_get_result((Result)action->intern[0], &data);
        if(RESULT_OK == res)
        {
            target_set_status(NOT_CONNECTED);
            if(RESULT_OK == data)
            {
                debug_line("Disconnected!");
                return RESULT_OK;
            }
            else
            {
                debug_error("target: SWD disconnect failed ! (Res: %ld)", data);
                return ERR_WRONG_VALUE;
            }
        }
        else
        {
            if(ERR_QUEUE_FULL_TRY_AGAIN == res)
            {
                // try again
                return ERR_NOT_COMPLETED;
            }
            else if(ERR_NOT_COMPLETED == res)
            {
                // try again
                return ERR_NOT_COMPLETED;
            }
            else
            {
                // some error
                debug_error("target: SWD disconnect failed ! (%ld)", res);
                return res;
            }
        }
    }
}


#ifdef FEAT_GDB_SERVER

// GDB_CMD_G
Result handle_target_reply_g(action_data_typ* const action)
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

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        reply_packet_prepare();
        action->cur_phase = 0;
        action->intern[INTERN_REGISTER_IDX] = 0;
        action->intern[INTERN_RETRY_COUNTER] = 0;
        action->first_call = false;
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    // 1. write to DCRSR the REGSEL value and REGWnR = 0
    if(0 == action->cur_phase)
    {
        res = step_write_ap(DCRSR, action->intern[INTERN_REGISTER_IDX]);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // 2. read DHCSR until S_REGRDY is 1
    if(1 == action->cur_phase)
    {
        res = step_read_ap(DHCSR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(2 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(3 == action->cur_phase)
    {
        if(0 == (action->read_0 & (1<<DHCSR_S_REGRDY_OFFSET)))
        {
            // Register not ready
            action->intern[INTERN_RETRY_COUNTER]++;
            if(10 < action->intern[INTERN_RETRY_COUNTER])
            {
                // no data available -> read again
                action->cur_phase = 1;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                debug_error("ERROR: gdb 'g' : too many retries !");
                reply_packet_send();
                return ERR_TIMEOUT;
            }
        }
        else
        {
            // data available -> read data
            action->cur_phase = action->cur_phase + 1;
            action->intern[INTERN_RETRY_COUNTER] = 0;
        }
    }

    // 3. read data from DCRDR
    if(4 == action->cur_phase)
    {
        res = step_read_ap(DCRDR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(5 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(6 == action->cur_phase)
    {
        // this register done, next?
        if(false == reply_packet_add_hex(action->read_0, 8))
        {
            reply_packet_send();
            return ERR_TOO_LONG;
        }
        // debug_line("read 0x%08lx", action->read_0);
        action->intern[INTERN_REGISTER_IDX] ++;
        action->cur_phase = 0;
        if(19 == action->intern[INTERN_REGISTER_IDX])
        {
            // skip
            action->intern[INTERN_REGISTER_IDX] ++;
        }
        if(21 == action->intern[INTERN_REGISTER_IDX])
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

// GDB_CMD_WRITE_G
Result handle_target_reply_write_g(action_data_typ* const action)
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

    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        reply_packet_prepare();
        if(MEMORY != action->gdb_parameter.type)
        {
            // wrong parameter type
            debug_error("ERROR: wrong parameter type !");
            reply_packet_add(ERROR_CODE_INVALID_PARAMETER_FORMAT_TYPE);
            reply_packet_send();
            return ERR_WRONG_VALUE;
        }
        else
        {
            action->cur_phase = 1;
            action->intern[INTERN_RETRY_COUNTER] = 0;
        }
        action->first_call = false;
    }

    if(1 == action->cur_phase)
    {
        uint32_t i;
        bool found = false;
        for(i = 0; i < MAX_MEMORY_POSITIONS; i++)
        {
            if(true == action->gdb_parameter.memory.memory[i].has_value)
            {
                // write that value
                found = true;
                action->gdb_parameter.memory.memory[i].has_value = false;
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
        if(18 < action->parameter[0])
        {
            // skip reserved 19
            action->parameter[0] ++;
        }
        action->parameter[1] = action->gdb_parameter.memory.memory[i].value;
        action->cur_phase = 2;
        return ERR_NOT_COMPLETED;
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    // 1. write value to DCRDR.
    if(2 == action->cur_phase)
    {
        res = step_write_ap(DCRDR, action->parameter[1]);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // 2. write to DCRSR the REGSEL value and REGWnR = 1
    if(3 == action->cur_phase)
    {
        res = step_write_ap(DCRSR, action->parameter[0] | (1 << DCRSR_REGWNR_OFFSET) );
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // 2. read DHCSR until S_REGRDY is 1
    if(4 == action->cur_phase)
    {
        res = step_read_ap(DHCSR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(5 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(6 == action->cur_phase)
    {
        if(0 == (action->read_0 & (1<<DHCSR_S_REGRDY_OFFSET)))
        {
            // write not finished
            action->intern[INTERN_RETRY_COUNTER] ++;
            if(100 < action->intern[INTERN_RETRY_COUNTER])
            {
                // write not finished -> read again
                action->cur_phase = 4;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                debug_error("ERROR: gdb 'G' : too many retries !");
                reply_packet_add("E23");
                reply_packet_send();
                return ERR_TIMEOUT;
            }
        }
        else
        {
            // write finished
            action->cur_phase = 1;
            return ERR_NOT_COMPLETED;
        }
    }

    return ERR_WRONG_STATE;
}

Result handle_target_reply_write_register(action_data_typ* const action)
{
    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        reply_packet_prepare();
        if( (MEMORY_LOCATION != action->gdb_parameter.type)
           || (MAX_MEMORY_POSITIONS < action->gdb_parameter.memory_location.idx) )
        {
            // wrong parameter type
            debug_error("ERROR: wrong parameter type !");
            reply_packet_add(ERROR_CODE_INVALID_PARAMETER_FORMAT_TYPE);
            reply_packet_send();
            return ERR_WRONG_VALUE;
        }
        else
        {
            action->cur_phase = 1;
            action->intern[INTERN_RETRY_COUNTER] = 0;
        }
        action->first_call = false;
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    // 1. write value to DCRDR.
    if(1 == action->cur_phase)
    {
        res = step_write_ap(DCRDR, action->gdb_parameter.memory_location.value);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // 2. write to DCRSR the REGSEL value and REGWnR = 1
    if(2 == action->cur_phase)
    {
        res = step_write_ap(DCRSR, action->gdb_parameter.memory_location.idx | (1 << DCRSR_REGWNR_OFFSET) );
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // 2. read DHCSR until S_REGRDY is 1
    if(3 == action->cur_phase)
    {
        res = step_read_ap(DHCSR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(4 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(5 == action->cur_phase)
    {
        if(0 == (action->read_0 & (1<<DHCSR_S_REGRDY_OFFSET)))
        {
            // write not finished
            action->intern[INTERN_RETRY_COUNTER] ++;
            if(100 < action->intern[INTERN_RETRY_COUNTER])
            {
                // write not finished -> read again
                action->cur_phase = 3;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                debug_error("ERROR: gdb 'P' : too many retries !");
                reply_packet_add("E23");
                reply_packet_send();
                return ERR_TIMEOUT;
            }
        }
        else
        {
            // write finished
            reply_packet_add("OK");
            reply_packet_send();
            return RESULT_OK;
        }
    }

    return ERR_WRONG_STATE;
}

// GDB_CMD_QUESTIONMARK
Result handle_target_reply_questionmark(action_data_typ* const action)
{
    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    send_stopped_reply();
    return RESULT_OK;
}

// GDB_CMD_CONTINUE
Result handle_target_reply_continue(action_data_typ* const action)
{
    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        reply_packet_prepare();
        action->cur_phase = 1;
        action->intern[INTERN_RETRY_COUNTER] = 0;
        action->first_call = false;
        return ERR_NOT_COMPLETED;
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    if(1 == action->cur_phase)
    {
        res = step_write_ap(DHCSR,  DBGKEY | (1 << DHCSR_C_DEBUGEN_OFFSET) );
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(2 == action->cur_phase)
    {
        res = step_read_ap(DHCSR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(3 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(4 == action->cur_phase)
    {
        if(0 == (action->read_0 & (1<<DHCSR_S_HALT_OFFSET)))
        {
            // Halt -> Run
            action->cur_phase = 5;
        }
        else
        {
            // Still in Halt
            action->intern[INTERN_RETRY_COUNTER] = action->intern[INTERN_RETRY_COUNTER] + 1;
            if(1000 > action->intern[INTERN_RETRY_COUNTER])
            {
                action->intern[INTERN_RETRY_COUNTER] = 0;
                debug_error("ERROR: releasing Halt did not work !");
                return ERR_TARGET_ERROR;
            }
            action->cur_phase = 2; // TODO
        }
    }

    if(5 == action->cur_phase)
    {
        target_set_status(CONNECTED_RUNNING);
        // gdb_is_not_busy_anymore();
        reply_packet_add("O");  // No Output
        reply_packet_send();
        return RESULT_OK;
    }

    return ERR_WRONG_STATE;
}

// GDB_CMD_WRITE_MEMORY
Result handle_target_reply_write_memory(action_data_typ* const action)
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

    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        reply_packet_prepare();
        if(ADDRESS_LENGTH_MEMORY != action->gdb_parameter.type)
        {
            // wrong parameter type
            debug_error("ERROR: wrong parameter type !");
            reply_packet_add(ERROR_CODE_INVALID_PARAMETER_FORMAT_TYPE);
            reply_packet_send();
            return ERR_WRONG_VALUE;
        }
        else
        {
            action->cur_phase = 1;
            action->intern[0] = action->gdb_parameter.address_length_memory.length;
        }
        action->first_call = false;
    }

    if(1 == action->cur_phase)
    {
        uint32_t i;
        bool found = false;
        for(i = 0; i < MAX_MEMORY_POSITIONS; i++)
        {
            if(true == action->gdb_parameter.address_length_memory.memory[i].has_value)
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
        action->parameter[0] = action->gdb_parameter.address_length_memory.address + i*4;
        action->parameter[1] = action->gdb_parameter.address_length_memory.memory[i].value;
        action->cur_phase = action->cur_phase + 1;
    }

    if(2 == action->cur_phase)
    {
        res = step_write_ap((uint32_t *)action->parameter[0], action->parameter[1]);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(3 == action->cur_phase)
    {
        action->cur_phase = 1;
        // continue with next memory location
        return ERR_NOT_COMPLETED;
    }

    return ERR_WRONG_STATE;
}

// GDB_CMD_STEP
Result handle_target_reply_step(action_data_typ* const action)
{
    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        action->cur_phase = 0;
        action->first_call = false;
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    // DHCSR
    // bit 3: C_MASKINTS: 0= do not mask;                       1= Mask PendSV, SysTick and external configurable interrupts.
    // bit 2: C_STEP:     0= single stepping disabled;          1= single stepping enabled.
    // bit 1: C_HALT:     0= Request a halted processor to run; 1= Request a running processor to halt.
    // bit 0: C_DEBUGEN:  0= Halting debug disabled;            1= Halting debug enabled.
    if(0 == action->cur_phase)
    {
        res = step_write_ap(DHCSR, DBGKEY
                         | (1 << DHCSR_C_MASKINTS_OFFSET)   // TODO "s" vs "S"
                         | (1 << DHCSR_C_STEP_OFFSET)
                         | (1 << DHCSR_C_DEBUGEN_OFFSET) );
        if(RESULT_OK == res)
        {
            send_stopped_reply();
            return RESULT_OK;
        }
        else
        {
            return res;
        }
    }

    return ERR_WRONG_STATE;
}

// CHECK_RUNNING
Result handle_check_target_running(action_data_typ* const action)
{
    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        reply_packet_prepare();
        action->cur_phase = 0;
        action->intern[INTERN_RETRY_COUNTER] = 0;
        action->first_call = false;
        return ERR_NOT_COMPLETED;
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    if(0 == action->cur_phase)
    {
        res = step_read_ap(DHCSR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(1 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(2 == action->cur_phase)
    {
        if(0 == (action->read_0 & (1<<DHCSR_S_HALT_OFFSET)))
        {
            // running
            return RESULT_OK;
        }
        else
        {
            // Halted
            target_set_status(CONNECTED_HALTED);
            send_stopped_reply();
        }
    }

    return ERR_WRONG_STATE;
}

void send_stopped_reply(void)
{
    reply_packet_prepare();
    // S = Signal; 05 = SIGTRAP
    reply_packet_add("S05");  // TODO send real stop reply
    reply_packet_send();
}

// GDB_MONITOR_REG
Result handle_monitor_reg(action_data_typ* const action)
{
    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        if(HAS_VALUE != action->gdb_parameter.type)
        {
            // wrong parameter type
            debug_error("ERROR: wrong parameter type !");
            reply_packet_prepare();
            reply_packet_add(ERROR_CODE_INVALID_PARAMETER_FORMAT_TYPE);
            reply_packet_send();
            return ERR_WRONG_VALUE;
        }
        else
        {
            action->cur_phase = 0;
            if(true == action->gdb_parameter.has_value.valid)
            {
                // not all registers but just one
                action->intern[INTERN_REGISTER_IDX] = action->gdb_parameter.has_value.value;
            }
            else
            {
                // all registers
                action->intern[INTERN_REGISTER_IDX] = 0;
            }
            action->intern[INTERN_RETRY_COUNTER] = 0;
        }
        action->first_call = false;
    }

    // TODO remove ARM specific code
    // TODO move ARM specific code into an activity

    // 1. write to DCRSR the REGSEL value and REGWnR = 0
    if(0 == action->cur_phase)
    {
        res = step_write_ap(DCRSR, action->intern[INTERN_REGISTER_IDX]);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    // 2. read DHCSR until S_REGRDY is 1
    if(1 == action->cur_phase)
    {
        reply_packet_prepare();
        reply_packet_add("O"); // packet is $ big oh, hex string# checksum
        res = step_read_ap(DHCSR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(2 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(3 == action->cur_phase)
    {
        if(0 == (action->read_0 & (1<<DHCSR_S_REGRDY_OFFSET)))
        {
            // Register not ready
            action->intern[INTERN_RETRY_COUNTER]++;
            if(10 < action->intern[INTERN_RETRY_COUNTER])
            {
                // no data available -> read again
                action->cur_phase = 1;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                debug_error("ERROR: gdm 'mon reg' : too many retries !");
                reply_packet_send();
                return ERR_TIMEOUT;
            }
        }
        else
        {
            // data available -> read data
            action->cur_phase = action->cur_phase + 1;
            action->intern[INTERN_RETRY_COUNTER] = 0;
        }
    }

    // 3. read data from DCRDR
    if(4 == action->cur_phase)
    {
        res = step_read_ap(DCRDR);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(5 == action->cur_phase)
    {
        res = step_get_Result_data(&action->read_0);
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }

    if(6 == action->cur_phase)
    {
        // clear buffer
        char buf[100];
        memset(&msg_buf, 0, sizeof(msg_buf));

        if(true == action->gdb_parameter.has_value.valid)
        {
            switch(action->intern[INTERN_REGISTER_IDX])
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                snprintf(msg_buf, sizeof(msg_buf), "r%ld (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 13: // sp
                snprintf(msg_buf, sizeof(msg_buf), "sp (/32): 0x%08lx\r\n", action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 14: // LR
                snprintf(msg_buf, sizeof(msg_buf), "lr (/32): 0x%08lx\r\n", action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 15: // PC
                snprintf(msg_buf, sizeof(msg_buf), "pc (/32): 0x%08lx\r\n", action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 16: // xPSR
                snprintf(msg_buf, sizeof(msg_buf), "xPSR (/32): 0x%08lx\r\n", action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 17: // MSP
                snprintf(msg_buf, sizeof(msg_buf), "msp (/32): 0x%08lx\r\n", action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 18: // PSP
                snprintf(msg_buf, sizeof(msg_buf), "psp (/32): 0x%08lx\r\n", action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 20: // CONROL / PRIMASK
                snprintf(msg_buf, sizeof(msg_buf), "control/primask (/32): 0x%08lx\r\n", action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;
            }
        }
        else
        {
            switch(action->intern[INTERN_REGISTER_IDX])
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) r%ld (/32): 0x%08lx\r\n",
                         action->intern[INTERN_REGISTER_IDX],
                         action->intern[INTERN_REGISTER_IDX],
                         action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 13: // sp
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) sp (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 14: // LR
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) lr (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 15: // PC
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) pc (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 16: // xPSR
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) xPSR (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 17: // MSP
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) msp (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;

            case 18: // PSP
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) psp (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                // no 19
                action->intern[INTERN_REGISTER_IDX] ++;
                break;

            case 20: // CONROL / PRIMASK
                snprintf(msg_buf, sizeof(msg_buf), "(%ld) control/primask (/32): 0x%08lx\r\n", action->intern[INTERN_REGISTER_IDX], action->read_0);
                encode_text_to_hex_string(msg_buf, sizeof(buf), buf);
                reply_packet_add(buf);
                break;
            }
        }
        reply_packet_send();

        // this register done, next?
        action->intern[INTERN_REGISTER_IDX] ++;
        action->cur_phase = 0;

        if(   (true == action->gdb_parameter.has_value.valid)  // only one value to report
           || (21 == action->intern[INTERN_REGISTER_IDX]) ) // reported on all values
        {
            // finished
            // end of output
            reply_packet_prepare();
            reply_packet_add("OK");
            reply_packet_send();

            gdb_is_not_busy_anymore();
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

Result handle_monitor_halt(action_data_typ* const action)
{
    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    // DHCSR.C_HALT == 1
    // then DHCSR.C_MASKINTS = 1 if ignore interrupt is enabled
    if(true == action->first_call)
    {
        reply_packet_prepare();
        if(HAS_VALUE != action->gdb_parameter.type)
        {
            // wrong parameter type
            debug_error("ERROR: wrong parameter type !");
            reply_packet_add(ERROR_CODE_INVALID_PARAMETER_FORMAT_TYPE);
            reply_packet_send();
            return ERR_WRONG_VALUE;
        }
        else
        {
            if(true == action->gdb_parameter.has_value.valid)
            {
                debug_error("DELAY: %ldms", action->gdb_parameter.has_value.value);
                // TODO implement pause
            }
            action->first_call = false;
            return ERR_NOT_COMPLETED;
        }
    }

    // TODO implement halt
    reply_packet_add("OK");
    reply_packet_send();
    gdb_is_not_busy_anymore();
    return RESULT_OK;
}

// GDB_CMD_MON_RESET
Result handle_monitor_reset(action_data_typ* const action)
{
    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        reply_packet_prepare();
        if(HAS_VALUE != action->gdb_parameter.type)
        {
            // wrong parameter type
            debug_error("ERROR: wrong parameter type !");
            reply_packet_add(ERROR_CODE_INVALID_PARAMETER_FORMAT_TYPE);
            reply_packet_send();
            return ERR_WRONG_VALUE;
        }
        else
        {
            action->first_call = false;
            return ERR_NOT_COMPLETED;
        }
    }

    switch(action->gdb_parameter.has_value.value)
    {
    default:  // fall through
    case MONITOR_RESET_TYPE_RUN:
        // TODO implement reset
        break;

    case MONITOR_RESET_TYPE_INIT:
        // TODO implement reset
        break;

    case MONITOR_RESET_TYPE_HALT:
        // TODO implement reset
        break;
    }
    reply_packet_add("OK");
    reply_packet_send();
    gdb_is_not_busy_anymore();
    return RESULT_OK;
}








#endif /* FEAT_GDB_SERVER */

