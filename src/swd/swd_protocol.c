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

static int32_t find_all_AP(void);
static int32_t check_AP(uint32_t APsel, uint32_t idr);
static int32_t check_memory(void);
static int32_t send_write_packet(uint32_t APnotDP, uint32_t address, uint32_t data);
static int32_t send_read_packet(uint32_t APnotDP, uint32_t address, uint32_t* data);
static int32_t read_ap_register(uint32_t ap_sel, uint32_t ap_bank_reg, uint32_t ap_register, uint32_t* data);
static int32_t write_ap_register(uint32_t ap_sel, uint32_t ap_bank_reg, uint32_t ap_register, uint32_t data);

void swd_init(void)
{
    memset(&state, 0, sizeof(state));
    state.is_connected = false;
    state.is_minimal_debug_port = false;
    swd_packets_init();
    state.last_activity_time_us = time_us_32();
}

bool swd_is_connected(void)
{
    return state.is_connected;
}

void swd_tick(void)
{
    // to reduce current consumption of target put the SWDIO in idle (High) (Reason: Target must have a pull up on SWDIO)
    uint32_t now = time_us_32();
    if(state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US < state.last_activity_time_us)
    {
        // wrap around
        if((now > state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US) && (now < state.last_activity_time_us))
        {
            swd_packet_set_swdio_idle();
        }
        // else wait for timeout
    }
    else
    {
        if(now > state.last_activity_time_us + SWDIO_IDLE_TIMEOUT_US)
        {
            swd_packet_set_swdio_idle();
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

int32_t swd_connect(bool multi, uint32_t target)
{
    uint32_t read_data = 0;
    int32_t res;
    uint32_t i;

    if(true == multi)
    {
        // go through dormant state
        swd_disconnect();
        jtag_to_dormant_state_sequence();
        leave_dormant_state_to_swd_sequence();
    }

    swd_packet_line_reset();

    if(true == multi)
    {
        // write TARGETSEL register to select the target CPU
        if(RES_OK != send_write_packet(DP, ADDR_TARGETSEL, target))
        {
            debug_line("SWD: TARGETSLECT failed!");
            return -1;
        }
        // else -OK
    }
    // else -> nothing to do

    // read id register
    res = send_read_packet(DP, ADDR_DPIDR, &read_data);
    if(RES_OK == res)
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
    }
    else
    {
        debug_line("SWD: failed to read DPIDR");
        swd_disconnect();
        return -2;
    }

    res = send_write_packet(DP, ADDR_ABORT, 0x1f); // clear all errors
    if(RES_OK != res)
    {
        debug_line("SWD: failed to write Abort");
        swd_disconnect();
        return -3;
    }

    // Issue a debug power request (CTRL/STAT)
    // TODO maybe have an configuration option to only power up the debug part ad not the system. Might be relevant for low power systems that are sleeping.
    res = send_write_packet(DP, ADDR_CTRL_STAT, 0x50000000);
    if(RES_OK != res)
    {
        debug_line("SWD: failed to write CTRL/STAT");
        swd_disconnect();
        return -4;
    }

    // wait for debug part of chip to be powered on
    for(i = 0; i < MAX_WAIT_POWER_ON; i++)
    {
        res = send_read_packet(DP, ADDR_CTRL_STAT, &read_data);
        if(RES_OK == res)
        {
            state.reg_CTRL_STAT = read_data;
            if(0xf0000000 == (0xf0000000 & read_data))
            {
                // chip debug part is now powered on
                break;
            }
            // else - not powered on yet -> try again
        }
        else
        {
            debug_line("SWD: failed to read CTRL/STAT");
            swd_disconnect();
            return -5;
        }
    }

    if(RES_OK != find_all_AP())
    {
        swd_disconnect();
        return -6;
    }

    return RES_OK;
}

void swd_disconnect(void)
{
    swd_packet_disconnect();
    state.is_connected = false;
    state.last_activity_time_us = time_us_32();
}

// static functions

static int32_t read_ap_register(uint32_t ap_sel, uint32_t ap_bank_reg, uint32_t ap_register, uint32_t* data)
{
    uint32_t ctrl_stat;
    uint32_t req_select = (ap_bank_reg << 4) | (ap_sel <<24);
    if(req_select != state.reg_SELECT)
    {
        if(RES_OK != send_write_packet(DP, ADDR_SELECT, req_select))
        {
            debug_line("SWD:AP(%ld): failed to write SELECT", ap_sel);
            return -1;
        }
        state.reg_SELECT = req_select;
    }

    if(RES_OK != send_read_packet(AP, ap_register, data))
    {
        debug_line("SWD:AP(%ld): failed to read AP-register", ap_sel);
        return -2;
    }

    if(RES_OK != send_read_packet(DP, ADDR_CTRL_STAT, &ctrl_stat))
    {
        debug_line("SWD:AP(%ld): failed to read CTRL/STAT", ap_sel);
        return -3;
    }
    if(0 == (ctrl_stat & 0x40))
    {
        debug_line("CTRL/STAT 0x%08lx", ctrl_stat);
        debug_line("SWD:AP(%ld): AP read failed", ap_sel);
        return -4;
    }

    if(RES_OK != send_read_packet(DP, ADDR_RDBUFF, data))
    {
        debug_line("SWD:AP(%ld): failed to read DP-RDBUFF", ap_sel);
        return -5;
    }

    return RES_OK;
}

static int32_t write_ap_register(uint32_t ap_sel, uint32_t ap_bank_reg, uint32_t ap_register, uint32_t data)
{
    uint32_t ctrl_stat;
    uint32_t req_select = (ap_bank_reg << 4) | (ap_sel <<24);
    if(req_select != state.reg_SELECT)
    {
        if(RES_OK != send_write_packet(DP, ADDR_SELECT, req_select))
        {
            debug_line("SWD:AP(%ld): failed to write SELECT", ap_sel);
            return -1;
        }
        state.reg_SELECT = req_select;
    }

    if(RES_OK != send_write_packet(AP, ap_register, data))
    {
        debug_line("SWD:AP(%ld): failed to read AP-register", ap_sel);
        return -2;
    }

    if(RES_OK != send_read_packet(DP, ADDR_CTRL_STAT, &ctrl_stat))
    {
        debug_line("SWD:AP(%ld): failed to read CTRL/STAT", ap_sel);
        return -3;
    }
    if(0 == (ctrl_stat & 0x40))
    {
        debug_line("CTRL/STAT 0x%08lx", ctrl_stat);
        debug_line("SWD:AP(%ld): AP read failed", ap_sel);
        return -4;
    }

    return RES_OK;
}

static int32_t find_all_AP(void)
{
    uint32_t i;
    uint32_t idr;
    for(i = 0; i < 256; i++)
    {
        debug_line("testing AP %ld", i);
        // IDR
        if(RES_OK != read_ap_register(i, AP_BANK_IDR, AP_REGISTER_IDR, &idr))
        {
            debug_line("SWD:AP(%ld): failed to read ap register", i);
            return -1;
        }

        if(0 != idr)
        {
            debug_line("AP %ld: 0x%08lx", i, idr);
            if(RES_OK != check_AP(i, idr))
            {
                return -6;
            }
        }
        else
        {
            // reached end of APs
            debug_line("AP %ld: IDR 0x%08lx", i, idr);
            break;
        }
    }
    return RES_OK;
}


static int32_t check_AP(uint32_t APsel, uint32_t idr)
{
    uint32_t class = (idr & (0xf << 13))>> 13;
    if(8 == class)
    {
        uint32_t reg_data;
        // Memory Access Port (MEM-AP)
        state.mem_ap.ap_sel = APsel;
        state.mem_ap.version = AP_VERSION_APv1;
        debug_line("APv1:");
        debug_line("AP: IDR: Revision: %ld", (idr & (0xful<<28))>>28 );
        debug_line("AP: IDR: Jep 106 : %ld x 0x7f + 0x%02lx", (idr & (0xf << 24))>>24, (idr & (0x7f<<17))>>17 );
        debug_line("AP: IDR: class :   %ld", class );
        debug_line("AP: IDR: variant:  %ld", (idr & (0xf<<4))>>4 );
        debug_line("AP: IDR: type:     %ld", (idr & 0xf) );

        if(RES_OK != read_ap_register(APsel, AP_BANK_BASE, AP_REGISTER_BASE, &reg_data))
        {
            debug_line("SWD:AP(%ld): failed to read ap register", APsel);
            return -1;
        }
        debug_line("AP: BASE : 0x%08lx", reg_data);
        state.mem_ap.reg_BASE = reg_data;

        if(RES_OK != read_ap_register(APsel, AP_BANK_CFG, AP_REGISTER_CFG, &reg_data))
        {
            debug_line("SWD:AP(%ld): failed to read ap register", APsel);
            return -1;
        }
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

        if(RES_OK != read_ap_register(APsel, AP_BANK_CFG1, AP_REGISTER_CFG1, &reg_data))
        {
            debug_line("SWD:AP(%ld): failed to read ap register", APsel);
            return -1;
        }
        debug_line("AP: CFG1 : 0x%08lx", reg_data);

        if(RES_OK != read_ap_register(APsel, AP_BANK_CSW, AP_REGISTER_CSW, &reg_data))
        {
            debug_line("SWD:AP(%ld): failed to read ap register", APsel);
            return -1;
        }
        debug_line("AP: CSW  : 0x%08lx", reg_data);
        state.mem_ap.reg_CSW = reg_data;
        return check_memory();
    }
    else if(9 == class)
    {
        // Memory Access Port (MEM-AP)
        state.mem_ap.ap_sel = APsel;
        state.mem_ap.version = AP_VERSION_APv2;
        debug_line("APv2:");
        debug_line("AP: IDR: Revision: %ld", (idr & (0xful<<28))>>28 );
        debug_line("AP: IDR: Jep 106 : %ld x 0x7f + 0x%02lx", (idr & (0xf << 24))>>24, (idr & (0x7f<<17))>>17 );
        debug_line("AP: IDR: class :   %ld", class );
        debug_line("AP: IDR: variant:  %ld", (idr & (0xf<<4))>>4 );
        debug_line("AP: IDR: type:     %ld", (idr & 0xf) );
        // TODO
    }
    else
    {
        debug_line("AP unknown class %ld !", class);
    }
    return RES_OK;
}

static int32_t check_memory(void)
{
    uint32_t reg_data;
    if(RES_OK != write_ap_register(state.mem_ap.ap_sel, AP_BANK_TAR, AP_REGISTER_TAR, state.mem_ap.reg_BASE))
    {
        debug_line("SWD:AP(%ld): failed to write ap register", state.mem_ap.ap_sel);
        return -1;
    }
    if(RES_OK != read_ap_register(state.mem_ap.ap_sel, AP_BANK_DRW, AP_REGISTER_DRW, &reg_data))
    {
        debug_line("SWD:AP(%ld): failed to read ap register", state.mem_ap.ap_sel);
        return -1;
    }
    debug_line("AP: @BASE  : 0x%08lx", reg_data);
    return RES_OK;
}

static int32_t send_write_packet(uint32_t APnotDP, uint32_t address, uint32_t data)
{
    uint32_t ack;
    ack = swd_packet_write(APnotDP, address, data);
    state.last_activity_time_us = time_us_32();
    if(ACK_OK != ack)
    {
        debug_line("SWD: failed to write (%ld/%ld/0x%08lx)", APnotDP, address, data);
        switch(ack)
        {
        case ACK_PROTOCOL_ERROR_0:
            debug_line("SWD: Line stays low (no target?)");
            break;

        case ACK_WAIT:
            debug_line("SWD: Wait");
            break;

        case ACK_FAULT:
            debug_line("SWD: Fault");
            break;

        case ACK_PROTOCOL_ERROR_1:
            debug_line("SWD: Line stays high (no target?)");
            break;

        case ERROR_PARITY:
            debug_line("SWD: parity error");
            break;
        }
        swd_disconnect();
        return -1;
    }
    return RES_OK;
}

static int32_t send_read_packet(uint32_t APnotDP, uint32_t address, uint32_t* data)
{
    uint32_t ack = swd_packet_read(APnotDP, address, data);
    state.last_activity_time_us = time_us_32();
    if(ACK_OK == ack)
    {
        return RES_OK;
    }
    else
    {
        debug_line("SWD: failed to read (%ld/%ld)", APnotDP, address);
        switch(ack)
        {
        case ACK_PROTOCOL_ERROR_0:
            debug_line("SWD: Line stays low (no target?)");
            break;

        case ACK_WAIT:
            debug_line("SWD: Wait");
            // TODO retry ?
            break;

        case ACK_FAULT:
            debug_line("SWD: Fault");
            break;

        case ACK_PROTOCOL_ERROR_1:
            debug_line("SWD: Line stays high (no target?)");
            break;

        case ERROR_PARITY:
            debug_line("SWD: parity error");
            break;
        }
        swd_disconnect();
        return -1;
    }
}

