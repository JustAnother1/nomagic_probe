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

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "target_info.h"
#include "arm/cortex-m.h"
#include "target_actions.h"
#include "target_info.h"
#include "result.h"
#include "debug_log.h"
#include "swd.h"
#include "arm/cortex-m.h"
#include "walk.h"
#include "cli.h"
#include "time.h"

#define MAX_SAFE_COUNT        0xfffffff0  // comparing against < 0xffffffff is always true -> we want to avoid 0xffffffff as end time of timeout
#define TIMEOUT_TIME_MS       300


// RP2040:
// Core 0: 0x01002927
// Core 1: 0x11002927
// Rescue DP: 0xf1002927
// Core0 and Core1 instance IDs can be changed
// so to be sure check also these end points:
// 0x21002927, 0x31002927, 0x41002927, 0x51002927, 0x61002927, 0x71002927
// 0x81002927, 0x91002927, 0xa1002927, 0xb1002927, 0xc1002927, 0xd1002927,
// 0xe1002927

// decoded:
// IDCODE:
// bit 0     = 1;
// bit 1-11  = Designer (JEP106)
// bit 27-12 = PartNo
// bit 28-31 = Version (implementation defined)

// Part Number : 0x1002
// Designer = Raspberry Pi Trading Ltd.
// JEP 106 = 9x 0x7f then 0x13

typedef struct{
    uint32_t target_id;
    uint32_t apsel;
} connect_param_typ;

static connect_param_typ connect_parameter[] = {
        // targetID | APSel |
        {0x01002927,      0 }, // RP2040 core 0
        {0x11002927,      0 }, // RP2040 core 1
        {0x21002927,      0 }, // RP2040 altered id
        {0x31002927,      0 }, // RP2040 altered id
        {0x41002927,      0 }, // RP2040 altered id
        {0x51002927,      0 }, // RP2040 altered id
        {0x61002927,      0 }, // RP2040 altered id
        {0x71002927,      0 }, // RP2040 altered id
        {0x81002927,      0 }, // RP2040 altered id
        {0x91002927,      0 }, // RP2040 altered id
        {0xa1002927,      0 }, // RP2040 altered id
        {0xb1002927,      0 }, // RP2040 altered id
        {0xc1002927,      0 }, // RP2040 altered id
        {0xd1002927,      0 }, // RP2040 altered id
        {0xe1002927,      0 }, // RP2040 altered id
        {0xf1002927,      0 }, // RP2040 rescue data port
};
#define NUM_CONNECT_LOCATIONS (sizeof(connect_parameter)/sizeof(connect_param_typ))

static bool test_swd_v1(void);
static bool test_swd_v2(void);

static walk_data_typ cur_walk;
static bool checked_swdv1;
static bool checked_swdv2;
static bool single_location;
static uint32_t step;
static uint32_t location;
static uint32_t timeout_time;
static bool wait_for_wrap_around;


void target_init(void)
{
    cur_walk.is_done = true;
    swd_init();
    walk_init();
}

bool cmd_target_info(uint32_t loop)
{
    (void)loop;
    debug_line("Target Status");
    debug_line("=============");
    debug_line("target: no target");
    // walk state
    if(true == cur_walk.is_done)
    {
        debug_line("SWD state: idle");
    }
    else
    {
        debug_line("SWD state: active");
        debug_line("type: %d", cur_walk.type);
        debug_line("phase: %ld", cur_walk.phase);

    }

    return true; // true == Done; false = call me again
}

void target_tick(void)
{
    swd_tick();
    if(false == cur_walk.is_done)
    {
        walk_execute(&cur_walk);
    }
}

bool target_is_connected(void)
{
    return false;
}

// get called from CLI.
// loop is 0 on first call and will increase by 1 on each following call.
// return false means we are not finished,
// return true mean we finished.
// returning false leads to this function being called again by CLI
bool cmd_swd_test(uint32_t loop)
{
    if(0 == loop)
    {
        uint8_t* para_str = cli_get_parameter(0);
        uint32_t start_time = time_get_ms();
        timeout_time = start_time + TIMEOUT_TIME_MS;
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
        checked_swdv1 = false;
        checked_swdv2 = false;
        step = 0;
        location = 0;
        single_location = false;
        cur_walk.result = RESULT_OK;
        cur_walk.is_done = true;
        if('1' == *para_str)
        {
            // SWDv1 only
            checked_swdv2 = true;
        }
        else if('2' == *para_str)
        {
            // SWDv2 only
            checked_swdv1 = true;
            para_str = cli_get_parameter(1);
            if(NULL != para_str)
            {
                location = (uint32_t)atoi((char*)para_str);
                single_location = true;
            }
        }
        return false;
    }
    else
    {
        // check timeout
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
                cur_walk.result = RESULT_OK;
                cur_walk.is_done = true;
                debug_line("ERROR: TIMEOUT !!!!");
                return true;
            }
            // else not a timeout, yet.
        }

        if(false == cur_walk.is_done)
        {
            return false;
        }
        if(false == checked_swdv1)
        {
            // check if we can connect using SWDv1
            return test_swd_v1();
        }
        else if(false == checked_swdv2)
        {
            // check if we can connect using SWDv1
            return test_swd_v2();
        }
        else
        {
            return true;
        }
    }
}

static bool test_swd_v1(void)
{
    // open SWD connection
    if(RESULT_OK != cur_walk.result)
    {
        debug_line("Failed to connect!");
        step = 0;
        checked_swdv1 = true;
        return false;
    }
    if(0 == step)
    {
        debug_line(" ");
        debug_line("trying to connect using SWDv1 ....");
        walk_init();
        cur_walk.type = WALK_CONNECT;
        cur_walk.par_b_0 = false; // multi = SWDv2 -> false
        cur_walk.par_i_0 = 0;
        cur_walk.par_i_1 = 0;
        cur_walk.phase = 0;
        cur_walk.result = RESULT_OK;
        cur_walk.is_done = false;
        step = 1;
        return false;
    }
    else if(1 == step)
    {
        if(RESULT_OK == cur_walk.result)
        {
            cur_walk.type = WALK_SCAN;
            cur_walk.phase = 0;
            cur_walk.is_done = false;
            step = 2;
        }
        else
        {
            debug_line("ERROR: SWDv1: failed to connect!");
            checked_swdv1 = true;
            step = 0;
        }
        return false;
    }
    else // if(2 == step)
    {
        debug_line("Done with SWDv1...");
        checked_swdv1 = true;
        step = 0;
        return false;
    }
}

static bool test_swd_v2(void)
{
    // open SWD connection
    if(0 == step)
    {
        if(NUM_CONNECT_LOCATIONS > location)
        {
            debug_line(" ");
            debug_line("trying to connect on location %ld/%d ....", location + 1, NUM_CONNECT_LOCATIONS);
            walk_init();
            cur_walk.type = WALK_CONNECT;
            cur_walk.par_b_0 = true; // multi = SWDv2 -> true
            cur_walk.par_i_0 = connect_parameter[location].target_id;
            cur_walk.par_i_1 = connect_parameter[location].apsel;
            cur_walk.phase = 0;
            cur_walk.result = RESULT_OK;
            cur_walk.is_done = false;
            step++;
        }
        else
        {
            // scanned all location -> we are done
            debug_line("Done !");
            return true;
        }
        return false;
    }
    else if(1 == step)
    {
        if(RESULT_OK == cur_walk.result)
        {
            cur_walk.type = WALK_SCAN;
            cur_walk.phase = 0;
            cur_walk.is_done = false;
            step++;
        }
        else
        {
            debug_line("ERROR: connect failed (%ld) !", cur_walk.result);
            location++;
            step = 0;
            if(true == single_location)
            {
                return true;
            }
        }
        return false;
    }
    else // if(2 == step)
    {
        if(RESULT_OK == cur_walk.result)
        {
            location++;
            step = 0;
            if(true == single_location)
            {
                return true;
            }
            return false;
        }
        else
        {
            debug_line("ERROR: scan failed (%ld) !", cur_walk.result);
            location++;
            step = 0;
            if(true == single_location)
            {
                return true;
            }
            return false;
        }
    }
}

