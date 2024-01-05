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

#include <stdint.h>
#include "gdb_packets.h"

void cotex_m_add_general_registers(void)
{
    uint32_t i;
    for(i = 0; i < 17; i++)
    {
        // reply_packet_add("xxxxxxxx");  // register is not available
        reply_packet_add("00000000");  // register is 0
        // -> Remote 'g' packet reply is of odd length
    }
}
