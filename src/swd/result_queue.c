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
#include "probe_api/debug_log.h"

static uint32_t next_index[NUM_QUEUE];
static uint32_t results[NUM_QUEUE][MAX_QUEUE_ENTRIES];
static bool busy[NUM_QUEUE][MAX_QUEUE_ENTRIES];
static bool filled[NUM_QUEUE][MAX_QUEUE_ENTRIES];

void result_queue_init(void)
{
    uint32_t i;
    uint32_t q;

    for(q = 0; q < NUM_QUEUE; q++)
    {
        next_index[q] = 0;
        for(i = 0; i < MAX_QUEUE_ENTRIES; i++)
        {
            busy[q][i] = false;
            filled[q][i] = false;
        }
    }
}

Result result_queue_get_next_transaction_id(uint32_t queue_id, uint32_t* data)
{
    if(queue_id < NUM_QUEUE)
    {
        if(false == busy[queue_id][next_index[queue_id]])
        {
            busy[queue_id][next_index[queue_id]] = true;
            *data = (next_index[queue_id]) + 1;  // range is 1 .. MAX_QUEUE_ENTRIES
            next_index[queue_id] ++;
            if(MAX_QUEUE_ENTRIES == next_index[queue_id])
            {
                next_index[queue_id] = 0;
            }
            return RESULT_OK;
        }
        else
        {
            return ERR_QUEUE_FULL_TRY_AGAIN;
        }
    }
    else
    {
        return ERR_INVALID_QUEUE;
    }
}

Result result_queue_add_result_of(uint32_t queue_id, uint32_t transaction, uint32_t data)
{
    if((transaction > MAX_QUEUE_ENTRIES) || (0 == transaction))
    {
        debug_line("ERROR: swd: invalid transaction id %ld", transaction);
        return ERR_INVALID_TRANSACTION_ID;
    }
    // debug_line("add result queue:%ld, tid:%ld, data:%08lx", queue_id, transaction, data);
    transaction = transaction -1;
    if(true == busy[queue_id][transaction])
    {
        results[queue_id][transaction] = data;
        filled[queue_id][transaction] = true;
        return RESULT_OK;
    }
    else
    {
        return ERR_WRONG_STATE;
    }
}

Result result_queue_get_result(uint32_t queue_id, uint32_t transaction, uint32_t* data)
{
    if((transaction > MAX_QUEUE_ENTRIES) || (0 == transaction))
    {
        debug_line("ERROR: swd(%ld): invalid transaction id %ld", queue_id, transaction);
        return ERR_INVALID_TRANSACTION_ID;
    }
    transaction = transaction -1;
    if(true == busy[queue_id][transaction])
    {
        if(true == filled[queue_id][transaction])
        {
            *data = results[queue_id][transaction];
            busy[queue_id][transaction] = false;
            filled[queue_id][transaction] = false;
            return RESULT_OK;
        }
        else
        {
            return ERR_NOT_YET_AVAILABLE;
        }
    }
    else
    {
        return ERR_WRONG_STATE;
    }
}

void result_queue_free_result(uint32_t queue_id, uint32_t transaction)
{
    if((transaction > MAX_QUEUE_ENTRIES) || (0 == transaction))
    {
        // ignoring this wrong free.
        return;
    }
    transaction = transaction -1;
    busy[queue_id][transaction] = false;
    filled[queue_id][transaction] = false;
}

