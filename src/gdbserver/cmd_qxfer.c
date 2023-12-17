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
#include "hal/debug_uart.h"
#include "probe_api/gdb_packets.h"


void handle_cmd_qXfer(char* parameter, uint32_t length)
{
    (void) length; // TODO
    // ‘qXfer:object:read:annex:offset,length’
    // qXfer:features:read:target.xml:0,3fb
    // -> object : features
    //    annex : target.xml
    //    offset : 0
    //    length = 0x3fb
    if(':' == *parameter)
    {
        uint32_t i;
        parameter++;
        char* curParameter = parameter;
        // parse parameters
        debug_line("qSupported parameter: %s !", parameter);
        for(i = 1; i < length; i++)
        {
            if(';' == *parameter)
            {
                *parameter = 0;
                debug_line("parameter: %s !", curParameter);
                parameter++;
                curParameter = parameter;
            }
            else
            {
                parameter++;
            }
        }
        debug_line("last parameter: %s !", curParameter);
        reply_packet_prepare();
        reply_packet_add(";vContSupported+");
        reply_packet_send();
    }
    else
    {
        // invalid
        reply_packet_prepare();
        reply_packet_add("E00");
        reply_packet_send();
    }
}
