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

#include "walk.h"
#include "steps.h"
#include "cortex-m.h"
#include <stddef.h>
#include "debug_log.h"
#include "time.h"
#include "swd.h"
#include "target_walk.h"

#define MAX_SAFE_COUNT    0xfffffff0  // comparing against < 0xffffffff is always true -> we want to avoid 0xffffffff as end time of timeout
#define WALK_TIMEOUT_TIME_MS  300

static uint32_t val_DHCSR;
static uint32_t val_DEMCR;

static uint32_t timeout_time;
static bool wait_for_wrap_around;

static void handle_connect(walk_data_typ* data);
static void handle_disconnect(walk_data_typ* data);
static void handle_read_special_register(walk_data_typ* data);
static void handle_write_special_register(walk_data_typ* data);
static void handle_read_memory(walk_data_typ* data);
static void handle_write_memory(walk_data_typ* data);


typedef void (*walk_handler)(walk_data_typ* data);

static const walk_handler walks_look_up[NUM_WALKS_DEFINED] = {
        handle_connect,
        handle_disconnect,
        handle_read_special_register,
        handle_write_special_register,
        handle_read_memory,
        handle_write_memory,
        TARGET_LOOKUP_HANDLERS
};

void walk_init(void)
{
}

void walk_execute(walk_data_typ* data)
{
    if(NULL == data)
    {
        return;
    }
    if(false == data->cur_step.is_done)
    {
        // we are not done -> do it now
        steps_execute(&(data->cur_step));
    }
    if(false == data->cur_step.is_done)
    {
        uint32_t cur_time = time_get_ms();
        if(true == wait_for_wrap_around)
        {
            if(10 > cur_time)
            {
                // wrap around happened
                wait_for_wrap_around = false;
            }
            // else continue waiting
        }
        else
        {
            if(cur_time > timeout_time)
            {
                // Timeout !!!
                debug_line("ERROR: Target walk(%d): timeout in running step %ld !", data->type, data->phase );
                // TODO can we do something better than to just skip this command?
                debug_line("walk(pi0:0x%08lX, pi1:0x%08lX, p:%ld, r:%ld, i:%ld, t:%d, d:%d, pb:%d)",
                           data->par_i_0,
                           data->par_i_1,
                           data->phase,
                           data->result,
                           data->intern_0,
                           data->type,
                           data->is_done,
                           data->par_b_0);
                debug_line("step(pi0:0x%08lX, pi1:0x%08lX, p:%ld, r:%ld, i:%ld, t:%d, d:%d, pb:%d)",
                           data->cur_step.par_i_0,
                           data->cur_step.par_i_1,
                           data->cur_step.phase,
                           data->cur_step.result,
                           data->cur_step.intern_0,
                           data->cur_step.type,
                           data->cur_step.is_done,
                           data->cur_step.par_b_0);

                // do not try anymore
                data->result = ERR_TIMEOUT;
                data->is_done = true;
                data->cur_step.is_done = true;
            }
            // else not a timeout, yet.
        }
    }
    else
    {
        // step is done, next step?
        if(RESULT_OK != data->cur_step.result)
        {
            // something went wrong !
            data->result = data->cur_step.result;
            data->is_done = true;
        }
        if(false == data->is_done)
        {
            // take the next step on this walk
            uint32_t start_time = time_get_ms();

            (*walks_look_up[data->type])(data);
            timeout_time = start_time + WALK_TIMEOUT_TIME_MS;
            if(timeout_time > MAX_SAFE_COUNT)
            {
                // an end time of 0xffffffff would not work as all values are always < 0xffffffff
                uint32_t remainder = 100 - (MAX_SAFE_COUNT - start_time);
                timeout_time = 2 + remainder;
                wait_for_wrap_around = true;
            }
            else if(timeout_time < start_time)
            {
                // wrap around
                wait_for_wrap_around = true;
            }
            else
            {
                wait_for_wrap_around = false;
            }
        }
    }
}

static void handle_connect(walk_data_typ* data)
{
    if(0 == data->phase)
    {
        data->cur_step.type = STEP_DISCONNECT;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->phase++;
    }
    else if(1 == data->phase)
    {
        data->cur_step.type = STEP_CONNECT;
        data->cur_step.par_b_0 = data->par_b_0;
        data->cur_step.par_i_0 = data->par_i_0;
        data->cur_step.par_i_1 = data->par_i_1;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->phase++;
    }
    else if(2 == data->phase)
    {
        // write DEBUGEN in DHCSR
        if(RESULT_OK == data->cur_step.result)
        {
            // cortex-M init
            val_DHCSR = 1;  // C_DEBUGEN = 1; C_HALT = b10;
            data->cur_step.type = STEP_AP_WRITE;
            data->cur_step.par_i_0 = DHCSR;
            data->cur_step.par_i_1 = DBGKEY | (0xffff & val_DHCSR);
            data->cur_step.phase = 0;
            data->cur_step.result = RESULT_OK;
            data->cur_step.is_done = false;
            data->phase++;
        }
        else
        {
            // step failed
            data->result = data->cur_step.result;
            data->is_done = true;
        }
    }
    else if(3 == data->phase)
    {
        // init DEMCR
        if(RESULT_OK == data->cur_step.result)
        {
            // bit 24: DWTENA:       0= DWT disabled;                 1= DWT enabled.
            // bit 10: VC_HARDERR:   0= haling on HardFault disabled; 1= halting on HardFault enabled.
            // bit 0:  VC_CORERESET: 0= Reset Vector Catch disabled;  1= Reset Vector Catch enabled.
            val_DEMCR = (1 << 24) | (1 << 10) | 1;
            data->cur_step.type = STEP_AP_WRITE;
            data->cur_step.par_i_0 = DEMCR;
            data->cur_step.par_i_1 = val_DEMCR;
            data->cur_step.phase = 0;
            data->cur_step.result = RESULT_OK;
            data->cur_step.is_done = false;
            data->phase++;
        }
        else
        {
            // step failed
            data->result = data->cur_step.result;
            data->is_done = true;
        }
    }
    else if(4 == data->phase)
    {
        if(RESULT_OK == data->cur_step.result)
        {
            // bit 3: C_MASKINTS: 0= do not mask;                       1= Mask PendSV, SysTick and external configurable interrupts.
            // bit 2: C_STEP:     0= single stepping disabled;          1= single stepping enabled.
            // bit 1: C_HALT:     0= Request a halted processor to run; 1= Request a running processor to halt.
            // bit 0: C_DEBUGEN:  0= Halting debug disabled;            1= Halting debug enabled.
            val_DHCSR = 0xf;
            data->cur_step.type = STEP_AP_WRITE;
            data->cur_step.par_i_0 = DHCSR;
            data->cur_step.par_i_1 = DBGKEY | (0xffff & val_DHCSR);
            data->cur_step.phase = 0;
            data->cur_step.result = RESULT_OK;
            data->cur_step.is_done = false;
            data->phase++; // todo add more steps?
            data->result = RESULT_OK;
            data->is_done = true;
        }
        else
        {
            // step failed
            data->result = data->cur_step.result;
            data->is_done = true;
        }
    }
    else if(5 == data->phase)
    {
        data->phase++; // todo add more steps?
        data->result = RESULT_OK;
        data->is_done = true;
    }
    else
    {
        // invalid phase
        debug_line("invalid phase in handle_connect() walk");
        data->result = ERR_WRONG_STATE;
        data->is_done = true;
    }
}

static void handle_disconnect(walk_data_typ* data)
{
    if(0 == data->phase)
    {
        data->cur_step.type = STEP_DISCONNECT;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->phase++;
    }
    else if(1 == data->phase)
    {
        if(RESULT_OK == data->cur_step.result)
        {
            data->result = RESULT_OK;
            data->is_done = true;
        }
        else
        {
            // step failed
            data->result = data->cur_step.result;
            data->is_done = true;
        }
    }
}

static void handle_read_special_register(walk_data_typ* data)
{
    // 1. write to DCRSR the REGSEL value and REGWnR = 0
    if(0 == data->phase)
    {
        data->cur_step.type = STEP_AP_WRITE;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->cur_step.par_i_0 = DCRSR;
        data->cur_step.par_i_1 = data->par_i_0;
        data->phase++;
        data->intern_0 = 0;  // retry counter
    }
    // 2. read DHCSR until S_REGRDY is 1
    else if(1 == data->phase)
    {
        data->cur_step.type = STEP_AP_READ;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->cur_step.par_i_0 = DHCSR;
        data->phase++;
    }
    // 3. read data from DCRDR
    else if(2 == data->phase)
    {
        if(0 == (data->cur_step.read_0 & (1<<16)))
        {
            data->intern_0++;
            if(100 < data->intern_0)
            {
                // no data available -> read again
                data->phase = 1;
            }
            else
            {
                // too many retries
                debug_line("ERROR: too many retries !");
                data->result = ERR_TIMEOUT;
                data->is_done = true;
            }
        }
        else
        {
            // data available -> read data
            data->cur_step.type = STEP_AP_READ;
            data->cur_step.phase = 0;
            data->cur_step.result = RESULT_OK;
            data->cur_step.is_done = false;
            data->cur_step.par_i_0 = DCRDR;
            data->phase++;
        }
    }

    else if(3 == data->phase)
    {
        data->read_0 = data->cur_step.read_0;
        data->result = RESULT_OK;
        data->is_done = true;
    }
}

static void handle_write_special_register(walk_data_typ* data)
{
    // 1. write value to DCRDR.
    if(0 == data->phase)
    {
        data->cur_step.type = STEP_AP_WRITE;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->cur_step.par_i_0 = DCRDR ;
        data->cur_step.par_i_1 = data->par_i_0 | (1<<16); //  REGWnR = 1
        data->phase++;
        data->intern_0 = 0;  // retry counter
    }
    // 2. write to DCRSR the REGSEL value and REGWnR = 1
    else if(1 == data->phase)
    {
        data->cur_step.type = STEP_AP_WRITE;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->cur_step.par_i_0 = DCRSR ;
        data->cur_step.par_i_1 = data->par_i_0 | (1<<16); //  REGWnR = 1
        data->phase++;
        data->intern_0 = 0;  // retry counter
    }
    // 2. read DHCSR until S_REGRDY is 1
    else if(2 == data->phase)
    {
        data->cur_step.type = STEP_AP_READ;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->cur_step.par_i_0 = DHCSR;
        data->phase++;
    }
    else if(3 == data->phase)
    {
        if(0 == (data->cur_step.read_0 & (1<<16)))
        {
            // write not finished
            data->intern_0++;
            if(100 < data->intern_0)
            {
                // write not finished -> read again
                data->phase = 2;
            }
            else
            {
                // too many retries
                debug_line("ERROR: too many retries !");
                data->result = ERR_TIMEOUT;
                data->is_done = true;
            }
        }
        else
        {
            // write finished
            data->result = RESULT_OK;
            data->is_done = true;
        }
    }
}

static void handle_read_memory(walk_data_typ* data)
{
    if(0 == data->phase)
    {
        data->cur_step.type = STEP_AP_READ;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->cur_step.par_i_0 = data->par_i_0;
        data->phase++;
    }
    else
    {
        data->read_0 = data->cur_step.read_0;
        data->result = RESULT_OK;
        data->is_done = true;
    }
}

static void handle_write_memory(walk_data_typ* data)
{
    if(0 == data->phase)
    {
        data->cur_step.type = STEP_AP_WRITE;
        data->cur_step.phase = 0;
        data->cur_step.result = RESULT_OK;
        data->cur_step.is_done = false;
        data->cur_step.par_i_0 = data->par_i_0; // address
        data->cur_step.par_i_1 = data->par_i_1; // value
        data->phase++;
    }
    else
    {
        data->result = RESULT_OK;
        data->is_done = true;
    }
}
