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
#include "arm/cortex-m.h"

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

#define SWD_AP_SEL       0

#define MEMORY_MAP_CONTENT  \
"<memory-map>\r\n" \
"<memory type=\"rom\" start=\"0x00000000\" length=\"0x00004000\"/>\r\n" \
"<memory type=\"flash\" start=\"0x10000000\" length=\"0x4000000\">\r\n" \
"<property name=\"blocksize\">0x1000</property>\r\n" \
"</memory>\r\n" \
"<memory type=\"ram\" start=\"0x20000000\" length=\"0x20042000\"/>\r\n" \
"</memory-map>\r\n"

static bool attached;
static uint32_t step;

void target_init(void)
{
    attached = false;
}

void target_tick(void)
{
}

Result target_request_read(uint32_t address)
{
    return swd_read_ap(address);
}

Result target_read_result(Result transaction, uint32_t* data)
{
    return swd_get_result(transaction, data);
}

Result target_connect(bool first_call)
{
    static Result phase = 0;
    static Result transaction_id;
    Result res;
    if(true == first_call)
    {
        debug_line("SWDv2 (0x%08x)", SWD_ID_CORE_0);
        swd_protocol_set_AP_sel(0);
        phase = 1;
    }

    if(1 == phase)
    {
        res = swd_connect(true, SWD_ID_CORE_0, SWD_AP_SEL);
        if(RESULT_OK < res)
        {
            transaction_id = res;
            phase = 2;
        }
        else
        {
            return res;
        }
    }

    if(2 == phase)
    {
        uint32_t data;
        res = swd_get_result(transaction_id, &data);
        if(RESULT_OK == res)
        {
            if(RESULT_OK == data)
            {
                phase = 3;
            }
            else
            {
                debug_line("target: SWD connect failed ! (%ld)", data);
                return ERR_TARGET_ERROR;
            }
        }
        else
        {
            return res;
        }
    }

    if((3 == phase) || (4 == phase))
    {
        if(3 == phase)
        {
            res = cortex_m_init(true);
            phase = 4;
        }
        else
        {
            res = cortex_m_init(false);
        }
        if(RESULT_OK == res)
        {
            debug_line("target: initialized cortex-m");
            //phase = 5;
            phase = 7;
        }
        else
        {
            return res;
        }
    }
/*
    if((5 == phase) || (6 == phase))
    {
        if(5 == phase)
        {
            res = cortex_m_halt_cpu(true);
            phase = 6;
        }
        else
        {
            res = cortex_m_halt_cpu(false);
        }
        if(RESULT_OK == res)
        {
            debug_line("target: halted CPU");
            phase = 7;
        }
        else
        {
            return res;
        }
    }
*/
    if(7 == phase)
    {
        // all done
        return RESULT_OK;
    }

    debug_line("target connect: invalid phase!");
    return ERR_WRONG_STATE;
}

bool cmd_swd_test(uint32_t loop)
{
    if(0 == loop)
    {
        step = 0;
        return false;
    }
    else
    {
        if((0 == step) || (1 == step))
        {
            // connect
            Result res;
            if(0 == step)
            {
                res = target_connect(true);
                step = 1;
            }
            else
            {
                res = target_connect(false);
            }
            if(RESULT_OK == res)
            {
                // ok
                debug_line("SWD: connected!");
                step = 2;
                return false;
            }
            else if(ERR_NOT_COMPLETED == res)
            {
                // call again
                return false;
            }
            else
            {
                // error
                debug_line("ERROR: SWD: failed to connect (%ld)!", res);
                return true;
            }
        }
        else if(2 == step)
        {
            // scan
            Result res;
            res = swd_scan();
            if(RESULT_OK == res)
            {
                // ok -> done
                return true;
            }
            else if (ERR_QUEUE_FULL_TRY_AGAIN == res)
            {
                // else busy -> call again
                return false;
            }
            else
            {
                // error
                debug_line("ERROR: SWD: failed to scan (%ld)!", res);
                return true;
            }
        }
        else
        {
            // should not happen
            return true;
        }
    }
}
