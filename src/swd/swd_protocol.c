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
#include <hal/time_base.h>
#include "swd_protocol.h"
#include "swd_packets.h"
#include <unistd.h>
#include <stdio.h>
#include "hal/debug_uart.h"

// DP addresses:
// A[0] = 0,  A[1] = 0
#define ADDR_IDCODE    0  // A[3:2] = 0 0
#define ADDR_DPIDR     0  // A[3:2] = 0 0
#define ADDR_ABORT     0  // A[3:2] = 0 0
#define ADDR_CTRL_STAT 4  // A[3:2] = 0 1
#define ADDR_WCR       4  // A[3:2] = 0 1
#define ADDR_SELECT    8  // A[3:2] = 1 0
#define ADDR_RESEND    8  // A[3:2] = 1 0
#define ADDR_RDBUFF    12 // A[3:2] = 1 1
#define ADDR_TARGETSEL 12 // A[3:2] = 1 1

#define AP  1
#define DP  0

static bool isMinimalDebugPort;

void swd_init(void)
{
    isMinimalDebugPort = false;
}


uint32_t swd_connect(bool multi, uint32_t target)
{
    (void) target;
    uint32_t read_data = 0;
    int res;

    packet_line_reset();
    // the first one might not have worked if the device is talked to another debugger before we came along.
    delay_us(100000);  // TODO for Debug only !

    packet_line_reset();

    delay_us(100000);  // TODO for Debug only !

    if(true == multi)
    {
        // write TARGETSEL register to select the target CPU
        packet_write(DP, ADDR_TARGETSEL, 0x01002927);  // ignore result -> line is not driven
        delay_us(100000);  // TODO for Debug only !
    }
    // else -> nothing to do

    // read id register
    res = packet_read(DP, ADDR_DPIDR,&read_data);
    delay_us(100000);  // TODO for Debug only !
    if(ACK_OK == res)
    {
        if(0 != ((1<<16) & read_data))
        {
            isMinimalDebugPort = true;
        }
        else
        {
            isMinimalDebugPort = false;
        }
    }
    else
    {
        debug_line("res: %d", res);  // TODO for Debug only !
        switch(res)
        {
        case ACK_PROTOCOL_ERROR_0:
            debug_line("SWD: Line stays low (no target?)");
            break;

        case ACK_OK:
            debug_line("SWD: OK");
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
        read_data = 0;
    }
    return read_data;
}

void swd_disconnect(void)
{
    packet_disconnect();
}


// read AP Register
// read AP register
// if read was not OK
// then read READOK Flag from DP:CTRL/STAT
// if RAEDOK 1 then RESEND request // issue was transporting the bits from DP over SWD. read to DP worked.
// if 0 then read AP failed // the AP could not execute the read


// write AP
// after many AP writes insert a AP read or a write to SELECT (this helps the chip to handle buffered writes.
