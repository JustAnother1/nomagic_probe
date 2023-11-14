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

// Multi Drop needs to select the end point before any communication.
// No detection of available end points possible, just testing all values.

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

bool cmd_swd_info(uint32_t loop)
{
    return swd_info(loop);
}

bool cmd_swd_test(uint32_t loop)
{
    (void)loop;
    uint8_t* parameter;

    // activate_Reset();
    // activate_Run();

    parameter = cli_get_parameter(0);
    if(NULL == parameter)
    {
        int32_t res;
        debug_line("SWDv1");
        res = swd_connect(false, 0);
        if(RES_OK != res)
        {
            debug_line("ERROR: SWD: failed to connect (%ld)!", res);
            return true;
        }
    }
    else
    {
        int32_t res;
        uint32_t id = (uint32_t)atoi((const char*)parameter);
        debug_line("SWDv2 (0x%08lx)", id);
        res = swd_connect(true, id);
        if(RES_OK != res)
        {
            debug_line("ERROR: SWD: failed to connect (%ld)!", res);
            return true;
        }
    }

    return true;
}

