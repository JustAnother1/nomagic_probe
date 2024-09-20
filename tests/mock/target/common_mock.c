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



void target_connect(void)
{
    num_calls[CALL_IDX_TARGET_CONNECT]++;
}

void target_close_connection(void)
{
    num_calls[CALL_IDX_TARGET_CLOSE_CONNECTION]++;
}

bool cmd_target_trace(uint32_t loop)
{
    (void) loop;
    return true;
}
