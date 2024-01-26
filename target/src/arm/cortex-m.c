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
static Result read_specialRegisters(bool first_call, uint32_t regsel, uint32_t* data);

static uint32_t val_DHCSR;
static uint32_t val_DEMCR;


Result cortex_m_init(bool first_call)
{
    static Result phase = 0;
    Result res;
    if(true == first_call)
    {
        phase = 1;
    }
    // initialize the registers to the values needed.

    if(1 == phase)
    {
        val_DHCSR = 1;  // C_DEBUGEN = 1; C_HALT = b10;
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

    if(2 == phase)
    {
        // TODO DEMCR.DWTENA bit to 1 to enable Watch points
        val_DEMCR = (1 << 24) | (1 << 10) | 1;
        res = swd_write_ap(DEMCR, val_DEMCR);
        if(RESULT_OK == res)
        {
            phase = 3;
        }
        else
        {
            return res;
        }
    }

    if(3 == phase)
    {
        val_DHCSR = 0xf;
        res = swd_write_ap(DHCSR, DBGKEY | (0xffff & val_DHCSR));
        if(RESULT_OK == res)
        {
            phase = 4;
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

    debug_line("cortex m init: invalid phase!");
    return ERR_WRONG_STATE;
}


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

Result cortex_m_add_general_registers(bool first_call)
{
    static uint32_t phase = 0;
    static uint32_t i;
    static uint32_t read;

    if(true == first_call)
    {
        i = 0;
        read = 0;
        phase = 1;
    }

    if((1 == phase) || (2 == phase))
    {
        // write i to DCRSR
        Result res;
        if(1 == phase)
        {
            res = read_specialRegisters(true, i, &read);
            phase = 2;
        }
        else
        {
            res = read_specialRegisters(false, i, &read);
        }
        if(RESULT_OK == res)
        {
            char buf[9];
            buf[8] = 0;
            int_to_hex(buf, read, 8);
            reply_packet_add(buf);
            i++;
            phase = 1;
            if(17 == i)
            {
                // finished
                return RESULT_OK;
            }
            else
            {
                // continue with next register
                return ERR_NOT_COMPLETED;
            }
        }
        else
        {
            return res;
        }
    }

    debug_line("add general registers: invalid phase!");
    return ERR_WRONG_STATE;
}

/*
static Result write_specialRegisters(bool first_call, uint32_t regsel, uint32_t data)
{

    // 1. write data to DCRDR
    // 2. write to DCRSR the REGSEL + REGWnR = 1
    // 3. read DHCSR until S_REGRDY is 1

    return ERR_WRONG_STATE;
}
*/

static Result read_specialRegisters(bool first_call, uint32_t regsel, uint32_t* data)
{
    static Result phase = 0;
    static Result transaction_id = 0;
    Result res;
    if(true == first_call)
    {
        phase = 1;
    }

    // 1. write to DCRSR the REGSEL value and REGWnR = 0
    if(1 == phase)
    {
        res = swd_write_ap(DCRSR, regsel);
        if(RESULT_OK == res)
        {
            phase = 2;
        }
        else
        {
            return res;
        }
    }

    // 2. read DHCSR until S_REGRDY is 1
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

    // ...until S_REGRDY is 1
    if(3 == phase)
    {
        res = swd_get_result(transaction_id, &val_DHCSR);
        if(RESULT_OK == res)
        {
            if(0 == (val_DHCSR & (1<<16)))
            {
                // no data available -> read again
                phase = 2;
            }
            else
            {
                // data available -> read data
                phase = 4;
            }
        }
        else
        {
            return res;
        }
    }

    // 3. read data from DCRDR
    if(4 == phase)
    {
        res = swd_read_ap(DCRDR);
        if(RESULT_OK < res)
        {
            transaction_id = res;
            phase = 5;
        }
        else
        {
            return res;
        }
    }

    // read the data
    if(5 == phase)
    {
        uint32_t reg_data;
        res = swd_get_result(transaction_id, &reg_data);
        if(RESULT_OK == res)
        {
            *data = reg_data;
            phase = 6;
        }
        else
        {
            return res;
        }
    }

    if(6 == phase)
    {
        return RESULT_OK;
    }

    debug_line("read special registers: invalid phase!");
    return ERR_WRONG_STATE;
}
