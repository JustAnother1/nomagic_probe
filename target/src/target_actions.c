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

#include "target_actions.h"
#include "target_info.h"
#include <stdbool.h>
#include "result.h"
#include "debug_log.h"
#include "swd.h"
#include "gdb_packets.h"

// RP2040:
// Core 0: 0x01002927
// Core 1: 0x11002927
// Rescue DP: 0xf1002927
// Core0 and Core1 instance IDs can be changed
// so to be sure check also these end points:
// 0x21002927, 0x31002927, 0x41002927, 0x51002927, 0x61002927, 0x71002927
// 0x81002927, 0x91002927, 0xa1002927, 0xb1002927, 0xc1002927, 0xd1002927,
// 0xe1002927

// decoded:
// IDCODE:
// bit 0     = 1;
// bit 1-11  = Designer (JEP106)
// bit 27-12 = PartNo
// bit 28-31 = Version (implementation defined)

// Part Number : 0x1002
// Designer = Raspberry Pi Trading Ltd.
// JEP 106 = 9x 0x7f then 0x13


#define SWD_ID_CORE_0    0x01002927
#define SWD_ID_CORE_1    0x11002927
#define SWD_ID_RESCUE_DP 0xf1002927

void target_init(void)
{
    target_info_init();
}

int32_t target_connect(void)
{
    debug_line("SWDv2 (0x%08x)", SWD_ID_CORE_0);
    swd_protocol_set_AP_sel(0);
    return swd_connect(true, SWD_ID_CORE_0);
}

bool target_is_connected(void)
{
    return swd_is_connected();
}

Result target_request_read(uint32_t address)
{
    return swd_read_ap(address);
}

int32_t target_read_result(uint32_t transaction, uint32_t* data)
{
    return swd_get_result(transaction, data);
}

void target_reply_g(void)
{
    uint32_t i;
    reply_packet_prepare();
    for(i = 0; i < 17; i++)
    {
        // reply_packet_add("xxxxxxxx");  // register is not available
        reply_packet_add("00000000");  // register is 0
        // -> Remote 'g' packet reply is of odd length
    }
    reply_packet_send();
}
