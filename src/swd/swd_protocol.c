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
#include <hal/time_base.h>
#include "swd_protocol.h"
#include "swd_packets.h"
#include "hal/debug_uart.h"
#include "result_queue.h"


// timeout until the WDIO line will be put into low power mode (High)
#define SWDIO_IDLE_TIMEOUT_US    12000
// after switching on the debug part of the chip, ask at most this many times if it now powered on (CTRL/STAT)
#define MAX_WAIT_POWER_ON     10

#define AP_VERSION_APv1       1
#define AP_VERSION_APv2       2 // new in ADIv6.0


typedef struct{
    uint32_t ap_sel;
    uint32_t version;
    bool long_address_support;
    bool large_data_support;
    uint32_t reg_BASE;
    uint32_t reg_CSW;
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
static uint32_t read_data;
static uint32_t transaction_id;
static uint32_t cycle_counter;
static uint32_t first_ap;
static uint32_t ctrl_stat;
static uint32_t reg_data;  // TODO sort these out

static Result check_AP(uint32_t idr, int32_t phase);
static Result read_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t* data, int32_t phase);
static Result write_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t data, int32_t phase);


void swd_protocol_init(void)
{
    memset(&state, 0, sizeof(state));
    read_data = 0;
    transaction_id = 0;
    cycle_counter = 0;
    ctrl_stat = 0;
    state.is_connected = false;
    state.is_minimal_debug_port = false;
    state.last_activity_time_us = time_us_32();
    state.mem_ap.ap_sel = 0xffffffff;
    swd_packets_init();
}

void swd_protocol_set_AP_sel(uint32_t val)
{
    state.mem_ap.ap_sel = val;
}

void swd_protocol_tick(void)
{
    swd_packets_tick();
    // to reduce current consumption of target put the SWDIO in idle (High) (Reason: Target must have a pull up on SWDIO)
    uint32_t now = time_us_32();
    if(state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US < state.last_activity_time_us)
    {
        // wrap around
        if((now > state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US) && (now < state.last_activity_time_us))
        {
            swd_packets_set_swdio_idle();
        }
        // else wait for timeout
    }
    else
    {
        if(now > state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US)
        {
            swd_packets_set_swdio_idle();
        }
        // else wait for timeout
    }
}

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

    case 2: debug_line("debug port version    %ld", state.dp_version); break;
    case 3: debug_line("DPIDR                 0x%08lx", state.reg_DPIDR); break;
    case 4: debug_line("SELECT                0x%08lx", state.reg_SELECT); break;
    case 5: debug_line("CTRL/STAT             0x%08lx", state.reg_CTRL_STAT); break;
    case 6: debug_line("APSEL                 %ld", state.mem_ap.ap_sel); break;
    case 7: debug_line("AP version            %ld", state.mem_ap.version); break;
    case 8: debug_line("BASE                  0x%08lx", state.mem_ap.reg_BASE); break;
    case 9: debug_line("CSW                   0x%08lx", state.mem_ap.reg_CSW); break;

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

    default: done = true;
    }
    return done;
}

Result connect_handler(int32_t phase, command_typ* cmd)
{
    Result phase_result;
    bool multi = cmd->flag;
    uint32_t target = cmd->i_val;

    if(0 == phase)
    {
        // can not return 0 as active phase as 0 == Result_OK
        // -> nothing to initialize here
        phase = 1;
    }

// Phase 1 (multi(SWDv2) only - disconnect)
    if(1 == phase)
    {
        if(true == multi)
        {
            // go through dormant state: 1. disconnect, 2. ...
            phase_result = swd_packet_disconnect();
            if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
            {
                return phase; // -> try again
            }
            else if(RESULT_OK == phase_result)
            {
                state.is_connected = false;
                state.last_activity_time_us = time_us_32();
                phase = 2;
            }
            else
            {
                // some other error
                return phase_result;
            }
        }
        else
        {
            // phase is 0 -> go to next phase
            phase = 4;
        }
    }

// Phase 2 (multi(SWDv2) only) JTAG->Dormant
    if(2 == phase)
    {
        phase_result = jtag_to_dormant_state_sequence();
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 3;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 3 (multi(SWDv2) only) Dormant -> SWD
    if(3 == phase)
    {
        phase_result = leave_dormant_state_to_swd_sequence();
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 4;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 4 line reset
    if(4 == phase)
    {
        phase_result = swd_packet_line_reset();
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 5;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 5 (multi(SWDv2) only) send TargetSelect Packet
    if(5 == phase)
    {
        if(true == multi)
        {
            phase_result = swd_packet_write(DP, ADDR_TARGETSEL, target);
            if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
            {
                return phase; // -> try again
            }
            else if(RESULT_OK == phase_result)
            {
                phase = 6;
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
            phase = 6;
        }
    }

// Phase 6 read ID Register
    if(6 == phase)
    {
        phase_result = swd_packet_read(DP, ADDR_DPIDR);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return phase; // -> try again
        }
        else if(0 < phase_result)
        {
            transaction_id = (uint32_t)phase_result;
            phase = 7;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 7 parse data from ID Register
    if(7 == phase)
    {
        phase_result = result_queue_get_result(PACKET_QUEUE, transaction_id, &read_data);
        if(ERR_NOT_YET_AVAILABLE == phase_result)
        {
            return phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            state.reg_DPIDR = read_data;
            state.is_connected = true;
            if(0 != ((1<<16) & read_data))
            {
                state.is_minimal_debug_port = true;
            }
            else
            {
                state.is_minimal_debug_port = false;
            }
            state.dp_version = (read_data & 0xF000)>>12;  // bit 12 to 15
            phase = 8;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 8 clear all previous errors
    if(8 == phase)
    {
        phase_result = swd_packet_write(DP, ADDR_ABORT, 0x1f);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 9;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 9 Issue a debug power request (CTRL/STAT)
    // TODO maybe have an configuration option to only power up the debug part ad not the system. Might be relevant for low power systems that are sleeping.
    if(9 == phase)
    {
        phase_result = swd_packet_write(DP, ADDR_CTRL_STAT, 0x50000000);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 10;
            cycle_counter = 0;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 9 + 10 : wait for debug part of chip to be powered on

// Phase 10 read CTRL/STAT Register
    if(10 == phase)
    {
        phase_result = swd_packet_read(DP, ADDR_CTRL_STAT);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return phase; // -> try again
        }
        else if(0 < phase_result)
        {
            transaction_id = (uint32_t)phase_result;
            phase = 11;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 11 parse data from CTRL/STAT Register
    if(11 == phase)
    {
        phase_result = result_queue_get_result(PACKET_QUEUE, transaction_id, &read_data);
        if(ERR_NOT_YET_AVAILABLE == phase_result)
        {
            return phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            cycle_counter++;
            state.reg_CTRL_STAT = read_data;
            if(0xf0000000 == (0xf0000000 & read_data))
            {
                // chip debug part is now powered on
                phase = 12;
            }
            else
            {
                // not powered on yet -> try again
                if(cycle_counter < MAX_WAIT_POWER_ON)
                {
                    phase = 10;
                }
                else
                {
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

// Phase 12 - we are done
    if(12 == phase)
    {
        // done!
        return RESULT_OK;
    }

    return phase;
}

Result scan_handler(int32_t phase, command_typ* cmd)
{
    (void) cmd;

    if(0 == phase)
    {
        cycle_counter = 0;
        first_ap = 0xffffffff;
        phase = 1;
    }

    if(1 == phase)
    {
        debug_line("testing AP %ld", cycle_counter);
        state.mem_ap.ap_sel = cycle_counter;
        phase = 2;
    }

// Phase 2 read IDR Register

    if((phase > 1) && (phase < 100))
    {
        phase = phase - 2;
        Result res = read_ap_register(AP_BANK_IDR, AP_REGISTER_IDR, &read_data, phase);
        if(RESULT_OK == res)
        {
            phase = 100;
        }
        else
        {
            if(0 > res)
            {
                return res;
            }
            else
            {
                return res + 2;
            }
        }
    }

    if(99 < phase)
    {
        if(0 != read_data)
        {
            Result tres;
            if(100 == phase)
            {
                debug_line("AP %ld: 0x%08lx", cycle_counter, read_data);
            }

            tres = check_AP(read_data, (phase-100));
            if(0 != tres)
            {
                if(0 < tres)
                {
                    // phase
                    return tres + 100;
                }
                else
                {
                    // ERROR
                    return tres;
                }
            }
            else
            {
                // done with this AP
                cycle_counter++;
                if(256 > cycle_counter)
                {
                    phase = 1;
                    state.mem_ap.ap_sel = cycle_counter;
                }
                else
                {
                    // scan complete
                    debug_line("Done!");
                    return RESULT_OK;
                }
            }
        }
        else
        {
            // reached end of APs
            debug_line("AP %ld: IDR 0x%08lx", cycle_counter, read_data);
            state.mem_ap.ap_sel = cycle_counter - 1;  // use the last good AP
            debug_line("Done!");
           return RESULT_OK;
        }
    }

    return (Result)phase;
}

Result read_handler(int32_t phase, command_typ* cmd)
{
    if(100 > phase)
    {
        Result res = write_ap_register(AP_BANK_TAR, AP_REGISTER_TAR, cmd->i_val, phase);
        if(RESULT_OK == res)
        {
            return 100;
        }
        else
        {
            return res;
        }
    }
    else
    {
        phase = phase -100;
        Result res = read_ap_register(AP_BANK_DRW, AP_REGISTER_DRW, &read_data, phase);
        if(RESULT_OK == res)
        {
            return result_queue_add_result_of(COMMAND_QUEUE, cmd->transaction_id, read_data);
        }
        else
        {
            if(0 > res)
            {
                return res;
            }
            else
            {
                return res + 100;
            }
        }
    }
}


// static functions

static Result read_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t* data, int32_t phase)
{
    Result phase_result;

    if(0 == phase)
    {
        // can not return 0 as active phase as 0 == Result_OK
        // -> nothing to initialize here
        phase = 1;
    }

    if(1 == phase)
    {
        uint32_t req_select = (ap_bank_reg << 4) | (state.mem_ap.ap_sel <<24);
        if(req_select != state.reg_SELECT)
        {
            phase_result = swd_packet_write(DP, ADDR_SELECT, req_select);
            if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
            {
                return (Result)phase; // -> try again
            }
            else if(RESULT_OK == phase_result)
            {
                state.reg_SELECT = req_select;
                phase = 2;
            }
            else
            {
                // some other error
                return phase_result;
            }
        }
        else
        {
            phase = 2;
        }
    }

// Phase 2 read AP Register
    if(2 == phase)
    {
        phase_result = swd_packet_read(AP, ap_register);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return (Result)phase; // -> try again
        }
        else if(0 < phase_result)
        {
            transaction_id = (uint32_t)phase_result;
            phase = 3;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 3 receive data from AP register read
    if(3 == phase)
    {
        phase_result = result_queue_get_result(PACKET_QUEUE, transaction_id, data);
        if(ERR_NOT_YET_AVAILABLE == phase_result)
        {
            return (Result)phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 4;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 4 read CTRL/STAT Register
    if(4 == phase)
    {
        phase_result = swd_packet_read(DP, ADDR_CTRL_STAT);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return (Result)phase; // -> try again
        }
        else if(0 < phase_result)
        {
            transaction_id = (uint32_t)phase_result;
            phase = 5;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 5 parse data from CTRL/STAT Register
    if(5 == phase)
    {
        phase_result = result_queue_get_result(PACKET_QUEUE, transaction_id, &ctrl_stat);
        if(ERR_NOT_YET_AVAILABLE == phase_result)
        {
            return (Result)phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            if(0 == (ctrl_stat & 0x40))
            {
                debug_line("CTRL/STAT 0x%08lx", ctrl_stat);
                debug_line("SWD:AP(%ld): AP read failed", state.mem_ap.ap_sel);
                return ERR_TARGET_ERROR;
            }
            phase = 6;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }


// Phase 6 read RDBUFF Register
    if(6 == phase)
    {
        phase_result = swd_packet_read(DP, ADDR_RDBUFF);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return (Result)phase; // -> try again
        }
        else if(0 < phase_result)
        {
            transaction_id = (uint32_t)phase_result;
            phase = 7;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 7 parse data from RDBUFF Register
    if(7== phase)
    {
        phase_result = result_queue_get_result(PACKET_QUEUE, transaction_id, data);
        if(ERR_NOT_YET_AVAILABLE == phase_result)
        {
            return (Result)phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 8;
        }
        else
        {
            // some other error
            debug_line("swd:read_result failed err:%ld, trID:%ld ", phase_result, transaction_id);
            return phase_result;
        }
    }

// Phase 8 - we are done
    if(8 == phase)
    {
        // done!
        return RESULT_OK;
    }

    return (Result)phase;
}

static Result write_ap_register(uint32_t ap_bank_reg, uint32_t ap_register, uint32_t data, int32_t phase)
{
    Result phase_result;

    if(0 == phase)
    {
        // can not return 0 as active phase as 0 == Result_OK
        // -< nothing to init here
        phase = 1;
    }

    if(1 == phase)
    {
        uint32_t req_select = (ap_bank_reg << 4) | (state.mem_ap.ap_sel <<24);
        if(req_select != state.reg_SELECT)
        {
            phase_result = swd_packet_write(DP, ADDR_SELECT, req_select);
            if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
            {
                return (Result)phase; // -> try again
            }
            else if(RESULT_OK == phase_result)
            {
                state.reg_SELECT = req_select;
                phase = 2;
            }
            else
            {
                // some other error
                return phase_result;
            }
        }
        else
        {
            phase = 2;
        }
    }

// Phase 2 write to AP register
    if(2 == phase)
    {
        phase_result = swd_packet_write(AP, ap_register, data);
        if(ERR_QUEUE_FULL_TRY_AGAIN == phase_result)
        {
            return (Result)phase; // -> try again
        }
        else if(RESULT_OK == phase_result)
        {
            phase = 3;
        }
        else
        {
            // some other error
            return phase_result;
        }
    }

// Phase 3 - we are done
    if(3 == phase)
    {
        // done!
        return RESULT_OK;
    }

    return (Result)phase;
}


static Result check_AP(uint32_t idr, int32_t phase)
{
    uint32_t class = (idr & (0xf << 13))>> 13;
    state.mem_ap.ap_sel = cycle_counter;
    if(8 == class)
    {
        // Memory Access Port (MEM-AP)
        if(0 == phase)
        {
            state.mem_ap.version = AP_VERSION_APv1;
            debug_line("APv1:");
            debug_line("AP: IDR: Revision: %ld", (idr & (0xful<<28))>>28 );
            debug_line("AP: IDR: Jep 106 : %ld x 0x7f + 0x%02lx", (idr & (0xf << 24))>>24, (idr & (0x7f<<17))>>17 );
            debug_line("AP: IDR: class :   %ld", class );
            debug_line("AP: IDR: variant:  %ld", (idr & (0xf<<4))>>4 );
            debug_line("AP: IDR: type:     %ld", (idr & 0xf) );
            phase = 1;
            return (Result)phase;
        }

        if(phase < 100)
        {
            phase = phase -1;
            Result res = read_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, &reg_data, phase);
            if(RESULT_OK == res)
            {
                debug_line("AP: CSW  : 0x%08lx", reg_data);
                state.mem_ap.reg_CSW = reg_data;

                // change CSW !!!
                reg_data = reg_data & ~0x3ful; // no auto address increment
                reg_data = reg_data | 0x80000002; // DbgSwEnable + data size = 32bit
                phase = 100;
                return (Result)phase;
            }
            else
            {
                if(0 > res)
                {
                    return res;
                }
                else
                {
                    return res + 1;
                }
            }
        }

        if(phase < 200)
        {
            phase = phase -100;
            Result res = write_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, reg_data, phase);
            if(RESULT_OK == res)
            {
                return 200;
            }
            else
            {
                if(0 > res)
                {
                    return res;
                }
                else
                {
                    return res + 100;
                }
            }
        }

        if(phase < 300)
        {
            phase = phase -200;
            Result res = read_ap_register(AP_BANK_BASE, AP_REGISTER_BASE, &reg_data, phase);
            if(RESULT_OK == res)
            {
                debug_line("AP: BASE : 0x%08lx", reg_data);
                state.mem_ap.reg_BASE = reg_data;
                phase = 300;
            }
            else
            {
                if(0 > res)
                {
                    return res;
                }
                else
                {
                    return res + 200;
                }
            }
        }

        if(phase < 400)
        {
            phase = phase -300;
            Result res = read_ap_register(AP_BANK_CFG, AP_REGISTER_CFG, &reg_data, phase);
            if(RESULT_OK == res)
            {
                debug_line("AP: CFG  : 0x%08lx", reg_data);
                if(0 == (reg_data & 0x02))
                {
                    state.mem_ap.long_address_support = false;
                }
                else
                {
                    state.mem_ap.long_address_support = true;
                }
                if(0 == (reg_data & 0x04))
                {
                    state.mem_ap.large_data_support = false;
                }
                else
                {
                    state.mem_ap.large_data_support = true;
                }
                phase = 400;
            }
            else
            {
                if(0 > res)
                {
                    return res;
                }
                else
                {
                    return res + 300;
                }
            }
        }

        if(phase < 500)
        {
            phase = phase -400;
            Result res = read_ap_register(AP_BANK_CFG1, AP_REGISTER_CFG1, &reg_data, phase);
            if(RESULT_OK == res)
            {
                debug_line("AP: CFG1 : 0x%08lx", reg_data);

                if(cycle_counter < first_ap)
                {
                    first_ap = cycle_counter;
                }
                phase = 500;
                return RESULT_OK; // done with this AP
            }
            else
            {
                if(0 > res)
                {
                    return res;
                }
                else
                {
                    return res + 400;
                }
            }
        }
        return (Result)phase;  // should not happen
    }
    else if(9 == class)
    {
        // Memory Access Port (MEM-AP)
        state.mem_ap.version = AP_VERSION_APv2;
        debug_line("APv2:");
        debug_line("AP: IDR: Revision: %ld", (idr & (0xful<<28))>>28 );
        debug_line("AP: IDR: Jep 106 : %ld x 0x7f + 0x%02lx", (idr & (0xf << 24))>>24, (idr & (0x7f<<17))>>17 );
        debug_line("AP: IDR: class :   %ld", class );
        debug_line("AP: IDR: variant:  %ld", (idr & (0xf<<4))>>4 );
        debug_line("AP: IDR: type:     %ld", (idr & 0xf) );
        // TODO

        if(cycle_counter < first_ap)
        {
            first_ap = cycle_counter;
        }

        return RESULT_OK; // done with this AP
    }
    else
    {
        debug_line("AP unknown class %ld !", class);
        return RESULT_OK; // done with this AP
    }
}

