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

#include "target_api/target_info.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "probe_api/gdb_packets.h"
#include "hal/debug_uart.h"

#define TARGET_XML_CONTENT  \
"<?xml version=\"1.0\"?>\r\n" \
"<!DOCTYPE target SYSTEM \"gdb-target.dtd\">\r\n" \
"<target version=\"1.0\">\r\n" \
"<architecture>arm</architecture>\r\n" \
"<feature name=\"org.gnu.gdb.arm.m-profile\">\r\n" \
"<reg name=\"r0\" bitsize=\"32\" regnum=\"0\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r1\" bitsize=\"32\" regnum=\"1\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r2\" bitsize=\"32\" regnum=\"2\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r3\" bitsize=\"32\" regnum=\"3\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r4\" bitsize=\"32\" regnum=\"4\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r5\" bitsize=\"32\" regnum=\"5\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r6\" bitsize=\"32\" regnum=\"6\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r7\" bitsize=\"32\" regnum=\"7\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r8\" bitsize=\"32\" regnum=\"8\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r9\" bitsize=\"32\" regnum=\"9\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r10\" bitsize=\"32\" regnum=\"10\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r11\" bitsize=\"32\" regnum=\"11\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r12\" bitsize=\"32\" regnum=\"12\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"sp\" bitsize=\"32\" regnum=\"13\" save-restore=\"yes\" type=\"data_ptr\" group=\"general\"/>\r\n" \
"<reg name=\"lr\" bitsize=\"32\" regnum=\"14\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"pc\" bitsize=\"32\" regnum=\"15\" save-restore=\"yes\" type=\"code_ptr\" group=\"general\"/>\r\n" \
"<reg name=\"xPSR\" bitsize=\"32\" regnum=\"16\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"</feature>\r\n" \
"<feature name=\"org.gnu.gdb.arm.m-system\">\r\n" \
"<reg name=\"msp\" bitsize=\"32\" regnum=\"17\" save-restore=\"yes\" type=\"data_ptr\" group=\"system\"/>\r\n" \
"<reg name=\"psp\" bitsize=\"32\" regnum=\"18\" save-restore=\"yes\" type=\"data_ptr\" group=\"system\"/>\r\n" \
"<reg name=\"primask\" bitsize=\"1\" regnum=\"20\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"<reg name=\"basepri\" bitsize=\"8\" regnum=\"21\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"<reg name=\"faultmask\" bitsize=\"1\" regnum=\"22\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"<reg name=\"control\" bitsize=\"3\" regnum=\"23\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"</feature>\r\n" \
"</target>\r\n"


#define THREADS_CONTENT  \
"<?xml version=\"1.0\"?>\r\n" \
"<threads>\r\n" \
"</threads>\r\n"


#define MEMORY_MAP_CONTENT  \
"<memory-map>\r\n" \
"<memory type=\"rom\" start=\"0x00000000\" length=\"0x00004000\"/>\r\n" \
"<memory type=\"flash\" start=\"0x10000000\" length=\"0x4000000\">\r\n" \
"<property name=\"blocksize\">0x1000</property>\r\n" \
"</memory>\r\n" \
"<memory type=\"ram\" start=\"0x20000000\" length=\"0x20042000\"/>\r\n" \
"</memory-map>\r\n"


static void send_part(char* part, uint32_t size, uint32_t offset, uint32_t length);


static bool attached;


void target_info_init(void)
{
    attached = false;
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

static void send_part(char* part, uint32_t size, uint32_t offset, uint32_t length)
{
    reply_packet_prepare();
    if(offset + length < size)
    {
        reply_packet_add("m");
    }
    else
    {
        reply_packet_add("l");
    }
    if(offset > size)
    {
        // offset invalid
        reply_packet_prepare();
        reply_packet_add("E 01");
        reply_packet_send();
        return;
    }
    if(offset + length > size)
    {
        length = size - offset;
    }
    reply_packet_add_max(&part[offset], length);
    reply_packet_send();
}


