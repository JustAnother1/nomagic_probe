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

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "hal/time_base.h"
#include "swd_protocol.h"
#include "swd_packets.h"
#include "probe_api/debug_log.h"
#include "swd_packet_bits.h"
#include "swd_engine.h"
#include "probe_api/swd.h"

// timeout until the WDIO line will be put into low power mode (High)
#define SWDIO_IDLE_TIMEOUT_US    12000
// after switching on the debug part of the chip, ask at most this many times if it now powered on (CTRL/STAT)
#define MAX_WAIT_POWER_ON     10

#define AP_VERSION_APv1       1
#define AP_VERSION_APv2       2 // new in ADIv6.0

// not sure why the Prot field is b0100010
#define CSW_VAL 0xA2000012


typedef struct{
    uint32_t ap_sel;
    uint32_t version;
    bool long_address_support;
    bool large_data_support;
    uint32_t reg_BASE;
    uint32_t reg_CSW;
    uint32_t reg_TAR;
} mem_ap_typ;

typedef struct{
    bool is_connected; // true = communication to target active.
    bool is_minimal_debug_port; // if true then Transaction counter, Pushed-verify, and Pushed-find operations are not implemented.
    uint32_t dp_version; // can be 0 to 3 (ADIv6)
    uint32_t reg_DPIDR;
    uint32_t reg_SELECT;
    uint32_t reg_CTRL_STAT;
    uint32_t last_activity_time_us;
    mem_ap_typ mem_ap;
} swd_state_typ;


static swd_state_typ state;

static Result read_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t* data, bool first_call, command_typ* cmd);
static Result write_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t data, bool first_call, command_typ* cmd);


void swd_protocol_init(void)
{
    memset(&state, 0, sizeof(state));
    state.is_connected = false;
    state.is_minimal_debug_port = false;
    state.dp_version = 0;
    state.reg_DPIDR = 0;
    state.reg_SELECT = 0;
    state.reg_CTRL_STAT = 0;
    state.last_activity_time_us = time_us_32();
    state.mem_ap.ap_sel = 0xffffffff;
    state.mem_ap.version = 0;
    state.mem_ap.long_address_support = false;
    state.mem_ap.large_data_support = false;
    state.mem_ap.reg_BASE = 0;
    state.mem_ap.reg_CSW = 0;
    state.mem_ap.reg_TAR = 0;
    swd_packets_init();
}

void swd_protocol_tick(void)
{
    swd_packet_bits_tick();
    // to reduce current consumption of target put the SWDIO in idle (High) (Reason: Target must have a pull up on SWDIO)
    uint32_t now = time_us_32();
    if(state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US < state.last_activity_time_us)  // TODO rethink
    {
        // wrap around
        if((now > state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US) && (now < state.last_activity_time_us))
        {
            swd_packet_bits_set_swdio_idle();
        }
        // else wait for timeout
    }
    else
    {
        if(now > state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US)
        {
            swd_packet_bits_set_swdio_idle();
        }
        // else wait for timeout
    }
}

void swd_protocol_set_AP_sel(uint32_t val)
{
    state.mem_ap.ap_sel = val;
}

#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
bool swd_info(uint32_t which)
{
    bool done = false;
    switch(which)
    {
    case 0: if(true == state.is_connected)
            {
                debug_line("swd:                  connected");
            }
            else
            {
                debug_line("swd: not connected");
                done = true;  // do not print other data as it can not be valid
            }
            break;

    case 1: if(true == state.is_minimal_debug_port)
            {
                debug_line("debug port:           minimal");
            }
            else
            {
                debug_line("debug port:           normal");
            }
            break;

    case  2: debug_line("debug port version    %ld", state.dp_version); break;
    case  3: debug_line("DPIDR                 0x%08lx", state.reg_DPIDR); break;
    case  4: debug_line("SELECT                0x%08lx", state.reg_SELECT); break;
    case  5: debug_line("CTRL/STAT             0x%08lx", state.reg_CTRL_STAT); break;
    case  6: debug_line("APSEL                 %ld", state.mem_ap.ap_sel); break;
    case  7: debug_line("AP version            %ld", state.mem_ap.version); break;
    case  8: debug_line("BASE                  0x%08lx", state.mem_ap.reg_BASE); break;
    case  9: debug_line("CSW                   0x%08lx", state.mem_ap.reg_CSW); break;

    case 10: if(true == state.mem_ap.large_data_support)
            {
                debug_line("large data support:   enabled");
            }
            else
            {
                debug_line("large data support:   not enabled");
            }
            break;

    case 11: if(true == state.mem_ap.long_address_support)
            {
                debug_line("long address support: enabled");
            }
            else
            {
                debug_line("long address support: not enabled");
            }
            break;

    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    {
        uint32_t read = 0;
        Result res = swd_get_result((Result)(which - 11), &read);
        if(ERR_NOT_COMPLETED == res)
        {
            debug_line("Result %ld : not ready !", which - 11);
        }
        else if(RESULT_OK == res)
        {
            debug_line("Result %ld : 0x%08lx !", which - 11, read);
        }
    }
    break;

    default: done = true;
    }
    return done;
}
#endif

Result connect_handler(command_typ* cmd, bool first_call)
{
    Result phase_result;
    bool multi = cmd->flag;
    uint32_t target = cmd->i_val;

    if(true == first_call)
    {
        state.mem_ap.ap_sel = cmd->i_val_2;
        cmd->phase = 1;
        swd_packet_bits_reset_error_condition();
    }

// Phase 1 (multi(SWDv2) only - disconnect)
    if(1 == cmd->phase)
    {
        if(true == multi)
        {
            // go through dormant state: 1. disconnect, 2. ...
            phase_result = swd_packet_disconnect();
            if(RESULT_OK == phase_result)
            {
                state.is_connected = false;
                state.last_activity_time_us = time_us_32();
                cmd->phase = 2;
            }
            else
            {
                // some other error
                return phase_result;
            }
        }
        else
        {
            // skip the multi only steps
            cmd->phase = 4;
        }
    }

// Phase 2 (multi(SWDv2) only) JTAG->Dormant
    if(2 == cmd->phase)
    {
        phase_result = jtag_to_dormant_state_sequence();
        if(RESULT_OK == phase_result)
        {
            cmd->phase = 3;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 3 (multi(SWDv2) only) Dormant -> SWD
    if(3 == cmd->phase)
    {
        phase_result = leave_dormant_state_to_swd_sequence();
        if(RESULT_OK == phase_result)
        {
            cmd->phase = 4;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 4 line reset
    if(4 == cmd->phase)
    {
        phase_result = swd_packet_line_reset();
        if(RESULT_OK == phase_result)
        {
            cmd->phase = 5;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 5 (multi(SWDv2) only) send TargetSelect Packet
    if(5 == cmd->phase)
    {
        if(true == multi)
        {
            phase_result = swd_packet_write(DP, ADDR_TARGETSEL, target);
            if(RESULT_OK == phase_result)
            {
                cmd->phase = 6;
            }
            else
            {
                // some other error
                return phase_result;
            }
        }
        else
        {
            // skip to next phase
            cmd->phase = 6;
        }
    }

// Phase 6 read ID Register
    if(6 == cmd->phase)
    {
        debug_line("INFO: request reading ID Register!");
        phase_result = swd_packet_read(DP, ADDR_DPIDR);
        if(RESULT_OK < phase_result)
        {
            cmd->sub_transaction_id = phase_result;
            cmd->phase = 7;
        }
        else if(RESULT_OK == phase_result)
        {
            // this should not happen
            debug_line("ERROR: Invalid ID received for SWD read!");
            return ERR_INVALID_TRANSACTION_ID;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 7 parse data from ID Register
    if(7 == cmd->phase)
    {
        phase_result = swd_packet_get_result(cmd->sub_transaction_id, &(cmd->read_data));
        if(RESULT_OK == phase_result)
        {
            debug_line("INFO: Read ID Register!");
            state.reg_DPIDR = cmd->read_data;
            state.is_connected = true;
            if(0 != ((1<<16) & cmd->read_data))
            {
                state.is_minimal_debug_port = true;
            }
            else
            {
                state.is_minimal_debug_port = false;
            }
            state.dp_version = (cmd->read_data & 0xF000)>>12;  // bit 12 to 15
            cmd->phase = 8;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 8 clear all previous errors
    if(8 == cmd->phase)
    {
        phase_result = swd_packet_write(DP, ADDR_ABORT, 0x1f);
        if(RESULT_OK == phase_result)
        {
            cmd->phase = 9;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 9 Issue a debug power request (CTRL/STAT)
    // TODO maybe have an configuration option to only power up the debug part ad not the system. Might be relevant for low power systems that are sleeping.
    if(9 == cmd->phase)
    {
        phase_result = swd_packet_write(DP, ADDR_CTRL_STAT, 0x50000000);
        if(RESULT_OK == phase_result)
        {
            cmd->phase = 10;
            cmd->retry_counter = 0;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 9 + 10 : wait for debug part of chip to be powered on

// Phase 10 read CTRL/STAT Register
    if(10 == cmd->phase)
    {
        phase_result = swd_packet_read(DP, ADDR_CTRL_STAT);
        if(0 < phase_result)
        {
            cmd->sub_transaction_id = phase_result;
            cmd->phase = 11;
        }
        else if(RESULT_OK == phase_result)
        {
            // this should not happen
            debug_line("ERROR: Invalid ID received for SWD read!");
            return ERR_INVALID_TRANSACTION_ID;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 11 parse data from CTRL/STAT Register
    if(11 == cmd->phase)
    {
        phase_result = swd_packet_get_result(cmd->sub_transaction_id, &(cmd->read_data));
        if(RESULT_OK == phase_result)
        {
            cmd->retry_counter++;
            state.reg_CTRL_STAT = cmd->read_data;
            if(0xf0000000 == (0xf0000000 & cmd->read_data))
            {
                // chip debug part is now powered on
                cmd->phase = 12;
            }
            else
            {
                // not powered on yet -> try again
                if(cmd->retry_counter < MAX_WAIT_POWER_ON)
                {
                    cmd->phase = 10;
                    return ERR_NOT_COMPLETED; // -> try again
                }
                else
                {
                    debug_line("TIMEOUT: when powering on the debug peripheral!");
                    return ERR_TIMEOUT;
                }
            }
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

    // Write APSel to SELECT Register
    if(12 == cmd->phase)
    {
        phase_result = swd_packet_write(DP, ADDR_SELECT, (state.mem_ap.ap_sel <<24));
        if(RESULT_OK == phase_result)
        {
            cmd->phase = 13;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

    // write CSW
    if((13 == cmd->phase) || (14 == cmd->phase))
    {
        if(13 == cmd->phase)
        {
            phase_result = write_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, CSW_VAL, true, cmd);
            cmd->phase = 14;
        }
        else
        {
            phase_result = write_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, CSW_VAL, false, cmd);
        }
        if(RESULT_OK == phase_result)
        {
            state.mem_ap.reg_CSW = CSW_VAL;
            cmd->phase = 15;
        }
        else
        {
            return phase_result;
        }
    }

    // read CSW
    if((15 == cmd->phase) || (16 == cmd->phase))
    {
        if(15 == cmd->phase)
        {
            phase_result = read_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, &(cmd->read_data), true, cmd);
            cmd->phase = 16;
        }
        else
        {
            phase_result = read_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, &(cmd->read_data), false, cmd);
        }
        if(RESULT_OK == phase_result)
        {
            cmd->phase = 17;
            /*
            // test if AP is now enabled
            if(0 != (read_data & 0x40))
            {
                phase = 16;
            }
            else
            {
                // try again
                phase = 12;
                return ERR_NOT_COMPLETED;
            }
            */
        }
        else
        {
            return phase_result;
        }
    }

// Phase 16 - we are done
    if(17 == cmd->phase)
    {
        // done!
        swd_eingine_add_cmd_result(cmd->transaction_id, RESULT_OK);
        return RESULT_OK;
    }

    debug_line("connect handler: invalid phase(%ld)!", cmd->phase);
    return ERR_WRONG_STATE;
}

Result write_handler(command_typ* cmd, bool first_call)
{
    if(true == first_call)
    {
        cmd->phase = 1;
    }

    if((1 == cmd->phase) || (2 == cmd->phase))
    {
        /* TODO auto increment !
        if(cmd->address == state.mem_ap.reg_TAR)
        {
            // we can skip this step
            cmd->phase = 3;
        }
        else */
        {
            Result res;
            if(1 == cmd->phase)
            {
                res = write_ap_register(AP_BANK_TAR, AP_REGISTER_TAR, cmd->address, true, cmd);
                cmd->phase = 2;
            }
            else
            {
                res = write_ap_register(AP_BANK_TAR, AP_REGISTER_TAR, cmd->address, false, cmd);
            }
            if(RESULT_OK == res)
            {
                state.mem_ap.reg_TAR = cmd->address;
                cmd->phase = 3;
            }
            else
            {
                return res;
            }
        }
    }

    if((3 == cmd->phase) || (4 == cmd->phase))
    {
        Result res;
        if(3 == cmd->phase)
        {
            res = write_ap_register(AP_BANK_DRW, AP_REGISTER_DRW, cmd->i_val, true, cmd);
            cmd->phase = 4;
        }
        else
        {
            res = write_ap_register(AP_BANK_DRW, AP_REGISTER_DRW, cmd->i_val, false, cmd);
        }
        return res;
    }

    debug_line("write handler: invalid phase!");
    return ERR_WRONG_STATE;
}

Result read_handler(command_typ* cmd, bool first_call)
{
    if(true == first_call)
    {
        cmd->phase = 1;
    }

    if((1 == cmd->phase) || (2 == cmd->phase))
    {
        /* TODO auto increment !
        if(cmd->address == state.mem_ap.reg_TAR)
        {
            // we can skip this step
            cmd->phase = 3;
        }
        else */
        {
            Result res;
            if(1 == cmd->phase)
            {
                res = write_ap_register(AP_BANK_TAR, AP_REGISTER_TAR, cmd->address, true, cmd);
                cmd->phase = 2;
            }
            else
            {
                res = write_ap_register(AP_BANK_TAR, AP_REGISTER_TAR, cmd->address, false, cmd);
            }
            if(RESULT_OK == res)
            {
                state.mem_ap.reg_TAR = cmd->address;
                cmd->phase = 3;
            }
            else
            {
                return res;
            }
        }
    }

    if((3 == cmd->phase) || (4 == cmd->phase))
    {
        Result res;
        if(3 == cmd->phase)
        {
            res = read_ap_register(AP_BANK_DRW, AP_REGISTER_DRW, &(cmd->read_data), true, cmd);
            cmd->phase = 4;
        }
        else
        {
            res = read_ap_register(AP_BANK_DRW, AP_REGISTER_DRW, &(cmd->read_data), false, cmd);
        }
        if(RESULT_OK == res)
        {
            swd_eingine_add_cmd_result(cmd->transaction_id, cmd->read_data);
        }
        return res;
    }

    debug_line("read handler: invalid phase!");
    return ERR_WRONG_STATE;
}

Result read_reg_handler(command_typ* cmd, bool first_call)
{
    Result res;
    if(true == first_call)
    {
        res = read_ap_register(cmd->i_val, cmd->i_val_2, &(cmd->read_data), true, cmd);
    }
    else
    {
        res = read_ap_register(cmd->i_val, cmd->i_val_2, &(cmd->read_data), false, cmd);
    }
    if(RESULT_OK == res)
    {
        swd_eingine_add_cmd_result(cmd->transaction_id, cmd->read_data);
    }
    return res;
}

Result write_reg_handler(command_typ* cmd, bool first_call)
{
    Result res;
    if(true == first_call)
    {
        res = write_ap_register(cmd->i_val, cmd->i_val_1, cmd->i_val_2, true, cmd);
    }
    else
    {
        res = write_ap_register(cmd->i_val, cmd->i_val_1, cmd->i_val_2, false, cmd);
    }
    return res;
}

Result disconnect_handler(command_typ* cmd, bool first_call)
{
    (void) first_call;
    Result res = swd_packet_disconnect();
    if(RESULT_OK == res)
    {
        // done!
        swd_eingine_add_cmd_result(cmd->transaction_id, RESULT_OK);
        return RESULT_OK;
    }
    else
    {
        return res;
    }
}

// static functions

static Result read_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t* data, bool first_call, command_typ* cmd)
{
    Result phase_result;

    if(true == first_call)
    {
        cmd->sub_phase = 1;
    }

    if(1 == cmd->sub_phase)
    {
        uint32_t req_select = (ap_bank_reg << 4) | (state.mem_ap.ap_sel <<24);
        if(req_select != state.reg_SELECT)
        {
            phase_result = swd_packet_write(DP, ADDR_SELECT, req_select);
            if(RESULT_OK == phase_result)
            {
                state.reg_SELECT = req_select;
                cmd->sub_phase = 2;
            }
            else
            {
                // some other error
                return phase_result;
            }
        }
        else
        {
            cmd->sub_phase = 2;
        }
    }

// Phase 2 read AP Register
    if(2 == cmd->sub_phase)
    {
        phase_result = swd_packet_read(AP, ap_register);
        if(0 < phase_result)
        {
            cmd->sub_transaction_id = phase_result;
            cmd->sub_phase = 3;
        }
        else if(RESULT_OK == phase_result)
        {
            // this should not happen
            debug_line("ERROR: Invalid ID received for SWD read!");
            return ERR_INVALID_TRANSACTION_ID;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 3 receive data from AP register read
    if(3 == cmd->sub_phase)
    {
        phase_result = swd_packet_get_result(cmd->sub_transaction_id, data);
        if(RESULT_OK == phase_result)
        {
            cmd->sub_phase = 4;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 4 read CTRL/STAT Register
    if(4 == cmd->sub_phase)
    {
        phase_result = swd_packet_read(DP, ADDR_CTRL_STAT);
        if(0 < phase_result)
        {
            cmd->sub_transaction_id = phase_result;
            cmd->sub_phase = 5;
        }
        else if(RESULT_OK == phase_result)
        {
            // this should not happen
            debug_line("ERROR: Invalid ID received for SWD read!");
            return ERR_INVALID_TRANSACTION_ID;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 5 parse data from CTRL/STAT Register
    if(5 == cmd->sub_phase)
    {
        phase_result = swd_packet_get_result(cmd->sub_transaction_id, &(state.reg_CTRL_STAT));
        if(RESULT_OK == phase_result)
        {
            if(0 == (state.reg_CTRL_STAT & 0x40))
            {
                debug_line("CTRL/STAT 0x%08lx", state.reg_CTRL_STAT);
                debug_line("SWD:AP(%ld): AP read failed", state.mem_ap.ap_sel);
                return ERR_TARGET_ERROR;
            }
            cmd->sub_phase = 6;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }


// Phase 6 read RDBUFF Register
    if(6 == cmd->sub_phase)
    {
        phase_result = swd_packet_read(DP, ADDR_RDBUFF);
        if(0 < phase_result)
        {
            cmd->sub_transaction_id = phase_result;
            cmd->sub_phase = 7;
        }
        else if(RESULT_OK == phase_result)
        {
            // this should not happen
            debug_line("ERROR: Invalid ID received for SWD read!");
            return ERR_INVALID_TRANSACTION_ID;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 7 parse data from RDBUFF Register
    if(7== cmd->sub_phase)
    {
        phase_result = swd_packet_get_result(cmd->sub_transaction_id, data);
        if(ERR_NOT_COMPLETED == phase_result)
        {
            return ERR_NOT_COMPLETED; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            cmd->sub_phase = 8;
        }
        else
        {
            // some other error
            debug_line("swd:read_result failed err:%ld, trID:%ld ", phase_result, cmd->sub_transaction_id);
            return phase_result;
        }
    }

// Phase 8 - we are done
    if(8 == cmd->sub_phase)
    {
        // done!
        return RESULT_OK;
    }

    debug_line("read ap register: invalid phase!");
    return ERR_WRONG_STATE;
}

static Result write_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t data, bool first_call, command_typ* cmd)
{
    Result phase_result;

    if(true == first_call)
    {
        cmd->sub_phase = 1;
    }

    if(1 == cmd->sub_phase)
    {
        uint32_t req_select = (ap_bank_reg << 4) | (state.mem_ap.ap_sel <<24);
        if(req_select != state.reg_SELECT)
        {
            phase_result = swd_packet_write(DP, ADDR_SELECT, req_select);
            if(RESULT_OK == phase_result)
            {
                state.reg_SELECT = req_select;
                cmd->sub_phase = 2;
            }
            else
            {
                // some other error
                return phase_result;
            }
        }
        else
        {
            cmd->sub_phase = 2;
        }
    }

// Phase 2 write to AP register
    if(2 == cmd->sub_phase)
    {
        phase_result = swd_packet_write(AP, ap_register, data);
        if(RESULT_OK == phase_result)
        {
            cmd->sub_phase = 3;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 3 - we are done
    if(3 == cmd->sub_phase)
    {
        // done!
        return RESULT_OK;
    }

    debug_line("write ap register: invalid phase!");
    return ERR_WRONG_STATE;
}
