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

#include "common_mock.h"

#include <stdint.h>
#include <stdbool.h>
#include "probe_api/result.h"
#include "probe_api/common.h"

static uint32_t num_calls[NUM_CALL_COUNTER];

void mock_target_reset_call_counts(void)
{
    uint32_t i;
    for(i = 0; i < NUM_CALL_COUNTER; i++)
    {
        num_calls[i] = 0;
    }
}

uint32_t mock_get_call_counter_of(uint32_t idx)
{
    return num_calls[idx];
}

void target_init(void)
{

}

void target_set_status(target_status_typ new_status)
{
    (void) new_status;
}

void target_tick(void)
{

}

bool common_cmd_target_info(uint32_t loop)
{
    (void) loop;
    return true;
}

bool cmd_target_trace(uint32_t loop)
{
    (void) loop;
    return true;
}

Result add_target_action(action_data_typ * const action)
{
    (void) action;
    return RESULT_OK;
}

bool add_action(action_typ act)
{
    (void) act;
    return true;
}

bool add_action_with_parameter(action_typ act, parameter_typ* parsed_parameter)
{
    (void) act;
    (void) parsed_parameter;
    return true;
}

void target_connect(void)
{
    num_calls[CALL_IDX_TARGET_CONNECT]++;
}

void target_close_connection(void)
{
    num_calls[CALL_IDX_TARGET_CLOSE_CONNECTION]++;
}


