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
#include "hex.h"
#include "result.h"
#include "swd.h"

// Result swd_read_ap(uint32_t addr);
// Result swd_get_result(uint32_t transaction, uint32_t* data);

void cotex_m_add_general_registers(void)
{
    uint32_t i;
    uint32_t val;
    Result transId;
    Result receive;
    char buf[9];
    buf[8] = 0;

    for(i = 0; i < 17; i++)
    {
        transId = 5; // TODO
        receive = swd_get_result(transId, &val);
        if(RESULT_OK == receive)
        {
            int_to_hex(buf, val, 8);
            reply_packet_add(buf);
        }
    }
}
