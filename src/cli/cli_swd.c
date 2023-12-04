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
#include <stdlib.h>
#include <hal/time_base.h>
#include "cli_swd.h"
#include "cli.h"

#include "swd/swd_protocol.h"
#include "swd/swd_gpio.h"
#include "swd/swd_packets.h"
#include "target_api/target_actions.h"


bool cmd_swd_info(uint32_t loop)
{
    return swd_info(loop);
}

bool cmd_swd_test(uint32_t loop)
{
    (void)loop;
    int32_t res;

    res = target_connect();
    if(RES_OK != res)
    {
        debug_line("ERROR: SWD: failed to connect (%ld)!", res);
    }

    return true;
}

bool cmd_swd_ap_read(uint32_t loop)
{
    (void)loop;
    uint8_t* parameter;

    parameter = cli_get_parameter(0);
    if(NULL == parameter)
    {
        debug_line("ERROR: no address given !");
        return true;
    }
    else
    {
        int32_t res;
        uint32_t data = 0;
        uint32_t addr = (uint32_t)atoi((const char*)parameter);
        int32_t apsel = swd_get_Memory_APsel();
        if(0 > apsel)
        {
            debug_line("ERROR: no Memory Access Port found on target !");
            return true;
        }
        res = read_ap(apsel, addr, &data);
        if(0 > res)
        {
            debug_line("ERROR: reading failed @ 0x%08lx!", addr);
            return true;
        }
        debug_line("Reading 0x%08lx as 0x%08lx", addr, data);
        return true;
    }
}
