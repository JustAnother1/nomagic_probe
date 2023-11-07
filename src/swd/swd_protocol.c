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

typedef struct{
    bool is_connected; // true = communication to target active.
    bool is_minimal_debug_port; // if true then Transaction counter, Pushed-verify, and Pushed-find operations are not implemented.
    uint32_t dp_version; // can be 0 to 3 (ADIv6)
    uint32_t reg_DPIDR;
    uint32_t reg_SELECT;
} swd_state;

static swd_state state;

void swd_init(void)
{
    memset(&state, 0, sizeof(state));
    state.is_connected = false;
    state.is_minimal_debug_port = false;
    swd_packets_init();
}

void swd_tick(void)
{
    // TODO
}


uint32_t swd_connect(bool multi, uint32_t target)
{
    uint32_t read_data = 0;
    int res;

    packet_line_reset();

    if(true == multi)
    {
        // write TARGETSEL register to select the target CPU
        packet_write(DP, ADDR_TARGETSEL, target);  // ignore result -> line is not driven
    }
    // else -> nothing to do

    // read id register
    res = packet_read(DP, ADDR_DPIDR, &read_data);
    if(ACK_OK == res)
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
        switch(res)
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
    }
    // Issue a debug power request (CTRL/STAT)
    res = packet_write(DP, ADDR_CTRL_STAT, 0x50000000); // TODO maybe have an option to only power up the debug part ad not the system. Might be relevant for low power systems that are sleeping.
    if(ACK_OK != res)
    {
        switch(res)
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
    }
    return read_data;
}

void swd_disconnect(void)
{
    packet_disconnect();
    state.is_connected = false;
}


// read AP Register
// read AP register
// if read was not OK
// then read READOK Flag from DP:CTRL/STAT
// if RAEDOK 1 then RESEND request // issue was transporting the bits from DP over SWD. read to DP worked.
// if 0 then read AP failed // the AP could not execute the read


// write AP
// after many AP writes insert a AP read or a write to SELECT (this helps the chip to handle buffered writes.
