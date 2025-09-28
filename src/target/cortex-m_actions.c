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

bool target_command_release_cortex_m_cpu(void)
{
    return add_action(RELEASE_CORTEX_M_CPU);
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
            // send_stopped_reply();  // TODO this action gets "called" from the SWD connect -> stop reply not necessary in that situation.
            return RESULT_OK;
        }
        else
        {
            return res;
        }
    }

    return ERR_WRONG_STATE;
}

Result handle_cortex_m_release(action_data_typ* const action)
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

    if(0 == action->cur_phase)
    {
        res = step_write_ap(AIRCR, VECTKEY | (1 << AIRCR_SYSRESETREQ_OFFSET));  // VECTKEY to enable write and request system reset
        if(RESULT_OK == res)
        {
            action->cur_phase++;
        }
        else
        {
            return res;
        }
    }


    // DHCSR
    // bit 3: C_MASKINTS: 0= do not mask;                       1= Mask PendSV, SysTick and external configurable interrupts.
    // bit 2: C_STEP:     0= single stepping disabled;          1= single stepping enabled.
    // bit 1: C_HALT:     0= Request a halted processor to run; 1= Request a running processor to halt.
    // bit 0: C_DEBUGEN:  0= Halting debug disabled;            1= Halting debug enabled.
    if(1 == action->cur_phase)
    {
        res = step_write_ap(DHCSR, DBGKEY);  // DBGKEY to enable write and all other bits 0
        if(RESULT_OK == res)
        {
            return RESULT_OK;
        }
        else
        {
            return res;
        }
    }

    return ERR_WRONG_STATE;
}
