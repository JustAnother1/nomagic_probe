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
#include "target_api/target_actions.h"

static uint32_t step;
static Result progress;


bool cmd_swd_connect(uint32_t loop)
{
    (void)loop;
    Result res;

    if(10000 < loop)
    {
        debug_line("ERROR: SWD: failed to connect (timeout)!");
        return true;
    }
    if(0 == loop)
    {
        res = target_connect(true);
    }
    else
    {
        res = target_connect(false);
    }
    if(RESULT_OK == res)
    {
        return true;
    }
    else if(ERR_NOT_COMPLETED == res)
    {
        // not yet complete
        return false;
    }
    else
    {
        debug_line("ERROR: SWD: failed to connect (%ld)!", res);
        return true;
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
        Result res;
        uint32_t data = 0;

        res = target_read_result(progress, &data);
        if(ERR_NOT_COMPLETED == res)
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
