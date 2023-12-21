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

#include "result_queue.h"
#include <stdbool.h>

static uint32_t next_index;
static uint32_t results[MAX_QUEUE_ENTRIES];
static bool busy[MAX_QUEUE_ENTRIES];

void result_queue_init(void)
{
    uint32_t i;
    next_index = 0;
    for(i = 0; i < MAX_QUEUE_ENTRIES; i++)
    {
        busy[i] = false;
    }
}

Result result_queue_get_next_transaction_id(uint32_t* data)
{
    if(false == busy[next_index])
    {
        busy[next_index] = true;
        *data = next_index;
        next_index++;
        if(MAX_QUEUE_ENTRIES == next_index)
        {
            next_index = 0;
        }
        return 0;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result result_queue_add_result_of(uint32_t transaction, uint32_t data)
{
    if(true == busy[transaction])
    {
        results[transaction] = data;
        return 0;
    }
    else
    {
        return ERR_WRONG_STATE;
    }
}

Result result_queue_get_result(uint32_t transaction, uint32_t* data)
{
    if(true == busy[transaction])
    {
        *data = results[transaction];
        busy[transaction] = false;
        return 0;
    }
    else
    {
        return ERR_WRONG_STATE;
    }
}

