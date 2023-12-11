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

#include "cmd_qsupported.h"
#include "hal/debug_uart.h"
#include "probe_api/gdb_packets.h"
#include "cfg/gdbserver_cfg.h"

void handle_cmd_qSupported(char* parameter, uint32_t length)
{
    (void) length; // TODO
    // Report the features supported by the server.
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
    }
    reply_packet_prepare();
    reply_packet_add("PacketSize=");
    reply_packet_add_hex(MAX_COMMAND_LENGTH, 0);
    reply_packet_add(";hwbreak+");
    // TODO add supported features
    // openocd: -multiprocess+;swbreak+;hwbreak+;qRelocInsn+;fork-events+;vfork-events+;exec-events+;vContSupported+;QThreadEvents+;no-resumed+
    //  reply picoprobe: PacketSize=4000;qXfer:memory-map:read+;qXfer:features:read+;qXfer:threads:read+;QStartNoAckMode+;vContSupported+
    // black magic probe:   gdb_putpacket_f("PacketSize=%X;qXfer:memory-map:read+;qXfer:features:read+;"
    // "vContSupported+" GDB_QSUPPORTED_NOACKMODE,
    // GDB_MAX_PACKET_SIZE);
    // #define GDB_QSUPPORTED_NOACKMODE ";QStartNoAckMode+"
    // GDB_MAX_PACKET_SIZE = 1024
    reply_packet_send();
}
