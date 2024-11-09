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
#include <stddef.h>
#include "probe_api/activity.h"
#include "probe_api/debug_log.h"
#include "probe_api/result.h"
#include "probe_api/steps.h"

Result act_read_register(activity_data_typ* const state, volatile uint32_t* address, uint32_t* read_value)
{
    Result res;

    if(NULL == state)
    {
        return ERR_ACTION_NULL;
    }

    if(true == state->first_call)
    {
        // first call
        // debug_line("called act_read_register!");
        state->phase = 1;
        state->first_call = false;
    }

    if(1 == state->phase)
    {
        res = step_read_ap(address);
        if(RESULT_OK == res)
        {
            state->phase++;
        }
        else
        {
            return res;
        }
    }

    if(2 == state->phase)
    {
        res =  step_get_Result_data(read_value);
        if(RESULT_OK == res)
        {
            return RESULT_OK;
        }
        else
        {
            return res;
        }
    }

    return ERR_WRONG_STATE;
}

