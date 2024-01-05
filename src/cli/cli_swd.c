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

#include "probe_api/swd.h"
#include "target_api/target_actions.h"

static uint32_t step;
static int32_t progress;


bool cmd_swd_info(uint32_t loop)
{
    return swd_info(loop);
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
        if(0 == step)
        {
            // connect
            int32_t res;
            res = target_connect();
            if (1 > res)
            {
                if(0 == res)
                {
                    // ok
                    step = 1;
                }
                else
                {
                    // error
                    debug_line("ERROR: SWD: failed to connect (%ld)!", res);
                    return true;
                }
            }
            // else busy -> call again
            return false;
        }
        else if(1 == step)
        {
            // scan
            int32_t res;
            res = swd_scan();
            if (1 > res)
            {
                if(0 == res)
                {
                    // ok -> done
                    return true;
                }
                else
                {
                    // error
                    debug_line("ERROR: SWD: failed to scan (%ld)!", res);
                    return true;
                }
            }
            // else busy -> call again
            return false;
        }
        else
        {
            // should not happen
            return true;
        }
    }
}

bool cmd_swd_connect(uint32_t loop)
{
    (void)loop;
    int32_t res;

    res = target_connect();
    if(0 == res)
    {
        return true;
    }
    else if(0 > res)
    {
        debug_line("ERROR: SWD: failed to connect (%ld)!", res);
        return true;
    }
    else
    {
        // not yet complete
        return false;
    }
}

bool cmd_swd_ap_read(uint32_t loop)
{
    if( 0 == loop)
    {
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
            uint32_t addr = (uint32_t)atoi((const char*)parameter);

            res = target_request_read(addr);
            if(0 > res)
            {
                debug_line("ERROR: SWD: failed to request read data (%ld)!", res);
                return true;
            }
            else
            {
                // not yet complete
                progress = res;
                step = addr;
                return false;
            }
        }
    }
    else
    {
        int32_t res;
        uint32_t data = 0;

        res = target_read_result((uint32_t)progress, &data);
        if(ERR_NOT_YET_AVAILABLE == res)
        {
            // not yet complete
            return false;
        }
        else if(0 > res)
        {
            debug_line("ERROR: SWD: failed to read requested data (%ld) trId:%ld !", res, progress);
            return true;
        }
        else if (0 == res)
        {
            debug_line("Reading 0x%08lx as 0x%08lx", step, data);
            return true;
        }
        else
        {
            // not yet complete
            return false;
        }
    }
}
