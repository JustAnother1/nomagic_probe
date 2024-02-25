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
#include "target_info.h"
#include "arm/cortex-m.h"
#include "target_actions.h"
#include "target_info.h"
#include "result.h"
#include "debug_log.h"
#include "swd.h"
#include "arm/cortex-m.h"
#include "walk.h"

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
    bool multi;
    uint8_t padding[3];
} connect_param_typ;

static connect_param_typ connect_parameter[] = {
        // SWDv1/SWDv2 | targetID | APSel | padding = , {0, 0,0}
        {false, 0, 0, {0, 0,0}}, // SWD v1
        {true, 0x01002927, 0, {0, 0,0}}, // RP2040 core 0
        {true, 0x11002927, 0, {0, 0,0}}, // RP2040 core 1
        {true, 0x21002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0x31002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0x41002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0x51002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0x61002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0x71002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0x81002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0x91002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0xa1002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0xb1002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0xc1002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0xd1002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0xe1002927, 0, {0, 0,0}}, // RP2040 altered id
        {true, 0xf1002927, 0, {0, 0,0}}, // RP2040 rescue data port
};
#define NUM_CONNECT_LOCATIONS (sizeof(connect_parameter)/sizeof(connect_param_typ))


static walk_data_typ cur_walk;


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
    debug_line(" target: no target");

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

// get called from CLI.
// loop is 0 on first call and will increase by 1 on each following call.
// return false means we are not finished,
// return true mean we finished.
// returning false leads to this function being called again by CLI
bool cmd_swd_test(uint32_t loop)
{
    static uint32_t step;
    static uint32_t location;
    if(0 == loop)
    {
        step = 0;
        location = 0;
        return false;
    }
    else
    {
        // open SWD connection
        if(0 == step)
        {
            if(true == cur_walk.is_done)
            {
                if(NUM_CONNECT_LOCATIONS > location)
                {
                    cur_walk.type = WALK_CONNECT;
                    cur_walk.par_b_0 = connect_parameter[location].multi;
                    cur_walk.par_i_0 = connect_parameter[location].target_id;
                    cur_walk.par_i_1 = connect_parameter[location].apsel;
                    cur_walk.phase = 0;
                    cur_walk.result = RESULT_OK;
                    cur_walk.is_done = false;
                    step = 1;
                }
                else
                {
                    // scanned all location -> we are done
                    debug_line("Done !");
                    return true;
                }
            }
            else
            {
                // currently busy -> try again
            }
            return false;
        }
        else if(1 == step)
        {
            if(true == cur_walk.is_done)
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
                    location++;
                    step = 0;
                }
            }
            else
            {
                // currently busy -> try again
            }
            return false;
        }
        else if(2 == step)
        {
            if(true == cur_walk.is_done)
            {
                location++;
                step = 0;
            }
            else
            {
                // currently busy -> try again
                return false;
            }
        }
        return true;
    }
}

