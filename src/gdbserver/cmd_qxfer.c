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

#include "cmd_qxfer.h"
#include <string.h>
#include <stdbool.h>
#include "hal/debug_uart.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "target_api/target_info.h"
#include "util.h"
#include "probe_api/debug_log.h"

#define OBJECT_PART      0
#define READ_PART        1
#define ANNEX_PART       2
#define OFFSET_LEN_PART  3
#define NUM_PARTS        4

static bool valid;
static char* parts[NUM_PARTS];

static void parse_parameter(char* parameter, uint32_t length);


void handle_cmd_qXfer(char* parameter, uint32_t length)
{
    // ‘qXfer:object:read:annex:offset,length’
    // qXfer:features:read:target.xml:0,3fb
    // -> object : features
    //    annex : target.xml
    //    offset : 0
    //    length = 0x3fb
    parse_parameter(parameter, length);
    if(true == valid)
    {
        uint32_t offset;
        uint32_t len;
        char* clen = parts[OFFSET_LEN_PART];
        while(*clen != ',')
        {
            clen++;
        }
        *clen = 0;
        clen++;
        offset = hex_to_int(parts[OFFSET_LEN_PART], 0);
        len = hex_to_int(clen, 0);
        debug_line("xfer obj:%s, off:%ld, len:%ld", parts[OBJECT_PART], offset, len);
        if(0 == strncmp(parts[OBJECT_PART], "features", 8))
        {
            target_send_file(parts[ANNEX_PART], offset, len);
            return;
        }
        else if(0 == strncmp(parts[OBJECT_PART], "memory-map", 10))
        {
            target_send_file(parts[OBJECT_PART], offset, len);
            return;
        }
        else if(0 == strncmp(parts[OBJECT_PART], "threads", 7))
        {
            target_send_file(parts[OBJECT_PART], offset, len);
            return;
        }
        debug_line("xfer:object invalid");
    }
    debug_line("xfer:invalid");
    // if we reach this, then the request was invalid
    reply_packet_prepare();
    reply_packet_add("E00");
    reply_packet_send();
}

static void parse_parameter(char* parameter, uint32_t length)
{
    uint32_t i;
    uint32_t p = 0;

    if(':' != *parameter)
    {
        valid = false;
        return;
    }
    parameter++;
    parts[p] = parameter; // first part starts here
    p++;

    for(i = 1; i < length; i++)
    {
        if(':' == *parameter)
        {
            // found end of a part
            *parameter = 0;
            parameter++;
            parts[p] = parameter;
            p++;
        }
        else
        {
            parameter++;
        }
    }
    *parameter = 0; // end of last part

    if(NUM_PARTS == p)
    {
        valid = true;
    }
    else
    {
        debug_line("num parts %ld", p);
        valid = false;
    }
}
