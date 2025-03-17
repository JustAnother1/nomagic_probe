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
#include "hal/time_base.h"
#include "cli_swd.h"
#include "probe_api/cli.h"

#include "probe_api/swd.h"
#include "probe_api/debug_log.h"
#include "probe_api/common.h"


bool cmd_swd_connect(const uint32_t loop)
{
    (void)loop;
    target_connect();
    return true;
}

bool cmd_swd_read_memory(const uint32_t loop)
{
    static uint32_t addr;
    static uint32_t len;
    static int32_t phase;

    if(0 == loop)
    {
        // first call
        phase = 0;
        // read address
        uint8_t* str = cli_get_parameter(0);
        addr = (uint32_t)atoi((const char*)str);
        // read length
        str = cli_get_parameter(1);
        len = (uint32_t)atoi((const char*)str);
    }
    else
    {
        if(0 == phase)
        {
            Result res = swd_read_ap(addr);
            if(RESULT_OK < res)
            {
                phase = res;
            }
            else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
            {
                // try again
            }
            else
            {
                // some error
                debug_line("ERROR: failed to read target memory (%ld)!", res);
                return true;
            }
        }
        else
        {
            uint32_t data;
            Result res = swd_get_result(phase, &data);
            if(RESULT_OK == res)
            {
                uint32_t i;
                for(i = 0; i < 4; i++)
                {
                    if(0 == ((addr + i) & 0xf))
                    {
                        debug_msg("\r\nAddress 0x%08lx :", addr + i);
                    }
                    debug_msg(" %02lx", data & 0xff);
                    data = data>>8;
                }
                // debug_line("addr: 0x%08lx, read : 0x%08lx", addr, data);
                if(len < 4)
                {
                    // we are done
                    return true;
                }
                else
                {
                    // read next address
                    addr = addr + 4;
                    len = len - 4;
                    phase = 0;
                }
            }
            else
            {
                if(ERR_NOT_COMPLETED == res)
                {
                    // try again
                }
                else
                {
                    // some error
                    debug_line("ERROR: failed to receive read value from target memory (%ld)!", res);
                    return true;
                }
            }
        }
    }
    return false;
}

bool cmd_swd_write_memory(const uint32_t loop)
{
    static uint32_t val;
    static uint32_t addr;
    static int32_t phase;

    if(0 == loop)
    {
        // first call
        phase = 0;
        uint8_t* addr_str = cli_get_parameter(0);
        uint8_t* val_str = cli_get_parameter(1);
        val = (uint32_t)atoi((const char*)val_str);
        addr = (uint32_t)atoi((const char*)addr_str);
    }
    else
    {
        if(0 == phase)
        {
            Result res = swd_write_ap(addr, val);
            if(RESULT_OK < res)
            {
                phase = res;
            }
            else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
            {
                // try again
            }
            else
            {
                // some error
                debug_line("ERROR: failed to write to target memory (%ld)!", res);
                return true;
            }
        }
        else
        {
            uint32_t data;
            Result res = swd_get_result(phase, &data);
            if(RESULT_OK == res)
            {
                if(RESULT_OK == data)
                {
                    debug_line("OK");
                    return true;
                }
                else
                {
                    debug_line("ERROR: SWD write to target memory failed ! (%ld)", data);
                    return true;
                }
            }
            else
            {
                if(ERR_NOT_COMPLETED == res)
                {
                    // try again
                }
                else
                {
                    // some error
                    debug_line("ERROR: failed to write to target memory, reported %ld !", res);
                }
            }
        }
    }
    return false;
}
