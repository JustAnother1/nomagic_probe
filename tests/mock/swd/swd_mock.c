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

#include "probe_api/swd.h"

bool swd_info(uint32_t which)
{
    (void) which;
    return true;
}


void swd_init(void)
{

}

void swd_tick(void)
{

}

void swd_protocol_set_AP_sel(uint32_t val)
{
    (void) val;
}

Result swd_connect(bool multi, uint32_t target, uint32_t AP_sel)
{
    (void) multi;
    (void) target;
    (void) AP_sel;
    return RESULT_OK;
}

Result swd_read_ap(uint32_t addr)
{
    (void) addr;
    return RESULT_OK;
}

Result swd_write_ap(uint32_t addr, uint32_t data)
{
    (void) addr;
    (void) data;
    return RESULT_OK;
}

Result swd_read_ap_reg(uint32_t bank, uint32_t reg)
{
    (void) bank;
    (void) reg;
    return RESULT_OK;
}

Result swd_write_ap_reg(uint32_t bank, uint32_t reg, uint32_t data)
{
    (void) bank;
    (void) reg;
    (void) data;
    return RESULT_OK;
}

Result swd_disconnect(void)
{
    return RESULT_OK;
}

Result swd_get_result(Result transaction, uint32_t* data)
{
    (void) transaction;
    (void) data;
    return RESULT_OK;
}

void swd_reset_error_condition(void)
{

}

