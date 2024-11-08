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

#include "probe_api/steps.h"
#include "probe_api/swd.h"
#include "probe_api/debug_log.h"


static Result transaction_id;

Result step_read_ap_reg(uint32_t bank, uint32_t reg)
{
    Result res = swd_read_ap_reg(bank, reg);
    if(RESULT_OK < res)
    {
        transaction_id = res;
        return RESULT_OK;
    }
    else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
    {
        // try again
        return ERR_NOT_COMPLETED;
    }
    else
    {
        // some error
        return res;
    }
}

Result step_write_ap_reg(uint32_t bank, uint32_t reg, uint32_t data)
{
    Result res = swd_write_ap_reg(bank, reg, data);
    if(RESULT_OK == res)
    {
        transaction_id = 0;
        return RESULT_OK;
    }
    else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
    {
        // try again
        return ERR_NOT_COMPLETED;
    }
    else
    {
        // some error
        return res;
    }
}

Result step_write_ap(volatile uint32_t* address, uint32_t data)
{
    Result res = swd_write_ap((uint32_t)address, data);
    if(RESULT_OK == res)
    {
        transaction_id = 0;
        return RESULT_OK;
    }
    else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
    {
        // try again
        return ERR_NOT_COMPLETED;
    }
    else
    {
        // some error
        return res;
    }
}

Result step_read_ap(volatile uint32_t* address)
{
    Result res;
    // debug_line("do_read_ap(0x%08lx)", address);
    res = swd_read_ap((uint32_t)address);
    if(RESULT_OK < res)
    {
        transaction_id = res;
        return RESULT_OK;
    }
    else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
    {
        // try again
        return ERR_NOT_COMPLETED;
    }
    else if(RESULT_OK == res)
    {
        return ERR_WRONG_VALUE;
    }
    else
    {
        // some error
        return res;
    }
}

Result step_disconnect(void)
{
    Result res = swd_disconnect();
    if(RESULT_OK < res)
    {
        transaction_id = res;
        return RESULT_OK;
    }
    else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
    {
        // try again
        return ERR_NOT_COMPLETED;
    }
    else
    {
        // some error
        return res;
    }
}

Result step_connect(bool multi, uint32_t target, uint32_t AP_sel)
{
    Result res = swd_connect(multi, target, AP_sel);
    if(RESULT_OK < res)
    {
        transaction_id = res;
        return RESULT_OK;
    }
    else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
    {
        // try again
        return ERR_NOT_COMPLETED;
    }
    else
    {
        // some error
        return res;
    }
}

Result step_get_Result_OK(void)
{
    uint32_t data;
    Result res = swd_get_result(transaction_id, &data);
    if(RESULT_OK == res)
    {
        if(RESULT_OK == data)
        {
            return RESULT_OK;
        }
        else
        {
            debug_line("target: step failed (0x%08lx)", data);
            return ERR_WRONG_VALUE;
        }
    }
    else
    {
        if(ERR_NOT_COMPLETED == res)
        {
            // try again
            return ERR_NOT_COMPLETED;
        }
        else
        {
            // some error
            return res;
        }
    }
}

Result step_get_Result_data(uint32_t* data)
{
    return swd_get_result(transaction_id, data);
}

