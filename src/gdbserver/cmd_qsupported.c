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
#include "cfg/serial_cfg.h"

// openocd:
// --------
// -multiprocess+;swbreak+;hwbreak+;qRelocInsn+;fork-events+;vfork-events+;exec-events+;vContSupported+;QThreadEvents+;no-resumed+
// picoprobe:
// ----------
// PacketSize=4000;qXfer:memory-map:read+;qXfer:features:read+;qXfer:threads:read+;QStartNoAckMode+;vContSupported+
// black magic probe:
// ------------------
// gdb_putpacket_f("PacketSize=%X;qXfer:memory-map:read+;qXfer:features:read+;"
// "vContSupported+" GDB_QSUPPORTED_NOACKMODE,
// GDB_MAX_PACKET_SIZE);
// #define GDB_QSUPPORTED_NOACKMODE ";QStartNoAckMode+"
// GDB_MAX_PACKET_SIZE = 1024
/*
Feature                openocd   picoprobe   black magic probe
-------                -------   ---------   -----------------
exec-events+             x
fork-events+             x
hwbreak+                 x
multiprocess+            x
no-resumed+              x
qRelocInsn+              x
QStartNoAckMode+                   x           x
QThreadEvents+           x
qXfer:features:read+               x           x
qXfer:memory-map:read+             x           x
qXfer:threads:read+                x
swbreak+                 x
vfork-events+            x
vContSupported+          x         x           x
*/

// if we implement Non stop Mode then we should add ‘QNonStop+’


void handle_cmd_qSupported(char* parameter, uint32_t length)
{
    (void) length;
    (void) parameter;
    char buf[10] = {0};
    /* only necessary if we would report a feature only in reply to a feature reported by gdb.
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
    */
    reply_packet_prepare();
    reply_packet_add("PacketSize=");
    snprintf(buf, 9, "%x", MAX_COMMAND_LENGTH -1); // GDB does not send a 0 at the end, so we need to have space for an additional 0
    reply_packet_add(buf);
    reply_packet_add(";hwbreak+");
    reply_packet_add(";QStartNoAckMode+");
    reply_packet_add(";qXfer:features:read+");
    reply_packet_add(";qXfer:memory-map:read+");
    reply_packet_add(";qXfer:threads:read+");
    reply_packet_add(";vContSupported+");

    reply_packet_send();
}
