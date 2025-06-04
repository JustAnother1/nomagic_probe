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

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "cfg/target_specific_actions.h"
#include "probe_api/common.h"
#include "probe_api/cortex-m.h"
#include "probe_api/cortex-m_actions.h"
#include "probe_api/result.h"
#include "probe_api/steps.h"
#include "target/common_actions.h"



bool target_command_halt_cortex_m_cpu(void)
{
    return add_action(HALT_CORTEX_M_CPU);
}


Result handle_cortex_m_halt(action_data_typ* const action)
{
    Result res;

    if(NULL == action)
    {
        return ERR_ACTION_NULL;
    }

    if(true == action->first_call)
    {
        action->cur_phase = 0;
        action->first_call = false;
    }


    // DHCSR
    // bit 3: C_MASKINTS: 0= do not mask;                       1= Mask PendSV, SysTick and external configurable interrupts.
    // bit 2: C_STEP:     0= single stepping disabled;          1= single stepping enabled.
    // bit 1: C_HALT:     0= Request a halted processor to run; 1= Request a running processor to halt.
    // bit 0: C_DEBUGEN:  0= Halting debug disabled;            1= Halting debug enabled.
    if(0 == action->cur_phase)
    {
        res = step_write_ap(DHCSR, DBGKEY
                         | (1 << DHCSR_C_MASKINTS_OFFSET)   // TODO configure ?
                         | (1 << DHCSR_C_HALT_OFFSET)       // TODO configure ?
                         | (1 << DHCSR_C_DEBUGEN_OFFSET) );
        if(RESULT_OK == res)
        {
            send_stopped_reply();
            return RESULT_OK;
        }
        else
        {
            return res;
        }
    }

    return ERR_WRONG_STATE;
}


/*
#include <stdint.h>
#include <string.h>
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "probe_api/result.h"
#include "probe_api/swd.h"
#include "probe_api/debug_log.h"
#include "probe_api/cortex-m.h"

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
                    debug_error("TIMEOUT: when setting halt bit!");
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

    debug_error("halt cpu: invalid phase (%ld)!", phase);
    return ERR_WRONG_STATE;
}
*/

