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

#include "execute.h"
#include "target.h"

typedef enum {
    IDLE,
    LOADING,
    STARTING,
    RUNNING,
    STOPPED,
} stateEnum_typ;

static stateEnum_typ state;
static uint32_t prog_length;
static uint8_t* prog_code;

void target_execute_init(void)
{
    state = IDLE;
}

Result target_execute(progs_typ prog)
{
    Result res;
    switch(state)
    {
    case IDLE:
        prog_length = target_progs_get_size(prog);
        prog_code =  target_progs_get_code(prog);
        state = LOADING;
        res = ERR_NOT_COMPLETED;
        return res;

    case LOADING:
        res = target_write(TARGET_RAM_START, prog_code, prog_length);
        if(RESULT_OK == res)
        {
            state = STARTING;
            res = ERR_NOT_COMPLETED;
        }
        return res;

    case STARTING:
        res = RESULT_OK; // TODO
        // write Start address of code to Register15 (PC)
        // write parameters to Registers first parameter goes into R0, second in R1,...
        // switch CPU from halt to run
        // start timeout
        return res;

    case RUNNING:
        // test if CPU is still running
        // test if timeout has occurred
        // if timeout then halt CPU
        // in both cases goto STOPPED

    case STOPPED:
        // if cause was timeout -> report error
        // report result of function
        // then go back to idle

    default:
        return ERR_WRONG_STATE;
    }
}


