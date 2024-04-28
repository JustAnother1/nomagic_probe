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

#include <stdint.h>
#include "gdb_packets.h"
#include "hex.h"
#include "result.h"
#include "swd.h"
#include "debug_log.h"
#include "cortex-m.h"

// static Result write_specialRegisters(bool first_call, uint32_t regsel, uint32_t data);
// static Result read_specialRegisters(bool first_call, uint32_t regsel, uint32_t* data);

static uint32_t val_DHCSR;

Result cortex_m_halt_cpu(bool first_call)
{
    // halt target DHCSR.C_HALT = 1 + check that DHCSR.S_HALT is 1
    static Result phase = 0;
    static Result transaction_id = 0;
    static uint32_t retries = 0;
    Result res;
    if(true == first_call)
    {
        phase = 1;
        retries = 0;
    }

    // write the halt command
    if(1 == phase)
    {
        uint32_t new_val = val_DHCSR | (1 <<1);
        if(new_val != val_DHCSR)
        {
            res = swd_write_ap(DHCSR, DBGKEY | (0xffff & val_DHCSR));
            if(RESULT_OK == res)
            {
                phase = 2;
            }
            else
            {
                return res;
            }
        }
        else
        {
            // already commanded to halt
            phase = 2;
        }
    }

    // read the status register
    if(2 == phase)
    {
        res = swd_read_ap(DHCSR);
        if(RESULT_OK < res)
        {
            transaction_id = res;
            phase = 3;
        }
        else
        {
            return res;
        }
    }

    // check if Halt status bit is set.
    if(3 == phase)
    {
        uint32_t data;
        res = swd_get_result(transaction_id, &data);
        if(RESULT_OK == res)
        {
            if(0 == (data & (1<<17)))
            {
                if(100 > retries)
                {
                    debug_line("TIMEOUT: when setting halt bit!");
                    return ERR_TIMEOUT;
                }
                else
                {
                    // not yet halted -> read again
                    phase = 2;
                    retries++;
                    return ERR_NOT_COMPLETED;
                }
            }
            else
            {
                // halted !
                phase = 4;
            }
        }
        else
        {
            return res;
        }
    }

    if(4 == phase)
    {
        return RESULT_OK;
    }

    debug_line("halt cpu: invalid phase (%ld)!", phase);
    return ERR_WRONG_STATE;
}



