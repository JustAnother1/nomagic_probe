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
#include "probe_api/result.h"

Result step_connect(action_data_typ* const action)
{
    (void) action;
    return RESULT_OK;
}

Result step_disconnect(action_data_typ* const action)
{
    (void) action;
    return RESULT_OK;
}

Result step_read_ap_reg(action_data_typ* const action, uint32_t bank, uint32_t reg)
{
    (void) action;
    (void) bank;
    (void) reg;
    return RESULT_OK;
}

Result step_write_ap_reg(action_data_typ* const action, uint32_t bank, uint32_t reg, uint32_t data)
{
    (void) action;
    (void) bank;
    (void) reg;
    (void) data;
    return RESULT_OK;
}

Result step_read_ap(action_data_typ* const action, volatile uint32_t* address)
{
    (void) action;
    (void) address;
    return RESULT_OK;
}

Result step_write_ap(action_data_typ* const action, volatile uint32_t* address, uint32_t data)
{
    (void) action;
    (void) address;
    (void) data;
    return RESULT_OK;
}

Result step_get_Result_OK(action_data_typ* const action)
{
    (void) action;
    return RESULT_OK;
}

Result step_get_Result_data(action_data_typ* const action)
{
    (void) action;
    return RESULT_OK;
}
