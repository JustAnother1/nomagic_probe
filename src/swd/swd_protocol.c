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

typedef struct{
    uint32_t ap_sel;

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
static int32_t send_write_packet(uint32_t APnotDP, uint32_t address, uint32_t data);
static int32_t send_read_packet(uint32_t APnotDP, uint32_t address, uint32_t* data);

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
                debug_line("swd: connected");
            }
            else
            {
                debug_line("swd: not connected");
                done = true;
            }
            break;

    case 1: if(true == state.is_minimal_debug_port)
            {
                debug_line("minimal debug port");
            }
            else
            {
                debug_line("normal debug port");
            }
            break;

    case 2: debug_line("debug port version %ld", state.dp_version); break;
    case 3: debug_line("DPIDR  0x%08lx", state.reg_DPIDR); break;
    case 4: debug_line("SELECT 0x%08lx", state.reg_SELECT); break;

    default: done = true;
    }
    return done;
}

int32_t swd_connect(bool multi, uint32_t target)
{
    uint32_t read_data = 0;
    int32_t res;
    uint32_t i;

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

static int32_t find_all_AP(void)
{
    uint32_t i;
    uint32_t idr;
    uint32_t ctrl_stat;
    for(i = 0; i < 256; i++)
    {
        debug_line("testing AP %ld", i);
        // IDR
        state.reg_SELECT = (AP_BANK_IDR << 4) | (i <<24);
        // debug_line("SWD: SELECT: 0x%08lx", state.reg_SELECT);
        if(RES_OK != send_write_packet(DP, ADDR_SELECT, state.reg_SELECT))
        {
            debug_line("SWD:AP(%ld): failed to write SELECT", i);
            return -1;
        }

        if(RES_OK != send_read_packet(AP, AP_REGISTER_IDR, &idr))
        {
            debug_line("SWD:AP(%ld): failed to read AP-IDR", i);
            return -2;
        }

        if(RES_OK != send_read_packet(DP, ADDR_CTRL_STAT, &ctrl_stat))
        {
            debug_line("SWD:AP(%ld): failed to read CTRL/STAT", i);
            return -3;
        }
        if(0 == (ctrl_stat & 0x40))
        {
            debug_line("CTRL/STAT 0x%08lx", ctrl_stat);
            debug_line("SWD:AP(%ld): AP read failed", i);
            return -4;
        }

        if(RES_OK != send_read_packet(DP, ADDR_RDBUFF, &idr))
        {
            debug_line("SWD:AP(%ld): failed to read DP-RDBUFF", i);
            return -5;
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
        // Memory Access Port (MEM-AP)
        state.mem_ap.ap_sel = APsel;
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

