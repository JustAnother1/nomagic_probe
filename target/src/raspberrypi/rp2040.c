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
#include <string.h>
#include "target_info.h"
#include "arm/cortex-m.h"
#include "target_actions.h"
#include "target_info.h"
#include "result.h"
#include "debug_log.h"
#include "swd.h"
#include "gdb_packets.h"
#include "common.h"

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

#define MEMORY_MAP_CONTENT  \
"<memory-map>\r\n" \
"<memory type=\"rom\" start=\"0x00000000\" length=\"0x00004000\"/>\r\n" \
"<memory type=\"flash\" start=\"0x10000000\" length=\"0x4000000\">\r\n" \
"<property name=\"blocksize\">0x1000</property>\r\n" \
"</memory>\r\n" \
"<memory type=\"ram\" start=\"0x20000000\" length=\"0x20042000\"/>\r\n" \
"</memory-map>\r\n"

static bool attached;

void target_init(void)
{
    attached = false;
}

void target_tick(void)
{

}

Result target_connect(uint32_t phase)
{
    (void)phase; // TODO
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

Result target_read_result(Result transaction, uint32_t* data)
{
    return swd_get_result(transaction, data);
}

Result target_reply_g(void)
{
    reply_packet_prepare();
    cotex_m_add_general_registers();
    reply_packet_send();
    return ERR_TARGET_ERROR;
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    if(0 == strncmp(filename, "target.xml", 10))
    {
        send_part(TARGET_XML_CONTENT, sizeof(TARGET_XML_CONTENT), offset, len);
        return;
    }
    else if(0 == strncmp(filename, "threads", 7))
    {
        send_part(THREADS_CONTENT, sizeof(THREADS_CONTENT), offset, len);
        return;
    }
    else if(0 == strncmp(filename, "memory-map", 10))
    {
        send_part(MEMORY_MAP_CONTENT, sizeof(MEMORY_MAP_CONTENT), offset, len);
        return;
    }

    debug_line("xfer:file invalid");
    // if we reach this, then the request was invalid
    reply_packet_prepare();
    reply_packet_add("E00");
    reply_packet_send();
}
