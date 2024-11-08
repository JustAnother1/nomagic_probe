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

Result step_connect(bool multi, uint32_t target, uint32_t AP_sel)
{
    (void) multi;
    (void) target;
    (void) AP_sel;
    return RESULT_OK;
}

Result step_disconnect(void)
{
    return RESULT_OK;
}

Result step_read_ap_reg(uint32_t bank, uint32_t reg)
{
    (void) bank;
    (void) reg;
    return RESULT_OK;
}

Result step_write_ap_reg(uint32_t bank, uint32_t reg, uint32_t data)
{
    (void) bank;
    (void) reg;
    (void) data;
    return RESULT_OK;
}

Result step_read_ap(volatile uint32_t* address)
{
    (void) address;
    return RESULT_OK;
}

Result step_write_ap(volatile uint32_t* address, uint32_t data)
{
    (void) address;
    (void) data;
    return RESULT_OK;
}

Result step_get_Result_OK(void)
{
    return RESULT_OK;
}

Result step_get_Result_data(uint32_t* data)
{
    (void) data;
    return RESULT_OK;
}
