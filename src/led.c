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

#include "led.h"
#include "hal/led_pin.h"
#ifdef LOOP_MONITOR
#include "hal/loop_monitor_pin.h"
#endif
#include "hal/time_base.h"

#define NUM_MAX_STEPS  2

#define LED_OFF_ACTION 0
#define LED_ON_ACTION  1

typedef struct {
    uint32_t duration;
    uint32_t action;
}step_typ;

typedef struct {
    uint32_t num_steps;
    step_typ steps[NUM_MAX_STEPS];
}pattern_typ;

static const pattern_typ patterns[] = {
        // 0 : Normal Operation
        {
                2,
                {
                        { 600, LED_ON_ACTION},
                        { 400, LED_OFF_ACTION},
                }
        },
        // 1 : Error Situation
        {
                2,
                {
                        { 100, LED_ON_ACTION},
                        { 100, LED_OFF_ACTION},
                }
        },
};


static uint32_t nextActionTime;
static uint32_t lastTime;
static uint32_t curPattern;
static uint32_t next_step;


// on pico the LED is connected to GPIO 25

void led_init(void)
{
    led_pin_init();
    led_set_pattern(PATTERN_NORMAL);
#ifdef LOOP_MONITOR
    loop_monitor_pin_init();
#endif
}

void led_set_pattern(uint32_t pattern)
{
    curPattern = pattern;
    next_step = 0;
    nextActionTime = 0;
    lastTime = 0;
}

void led_tick(void)
{
    uint32_t curTime = time_get_ms();
    if(curTime != lastTime)
    {
        lastTime = curTime;
        if(0 == nextActionTime)
        {
            // execute next step
            nextActionTime = patterns[curPattern].steps[next_step].duration;
            switch(patterns[curPattern].steps[next_step].action)
            {
            case LED_OFF_ACTION :
                led_pin_off();
                break;

            case LED_ON_ACTION :
                led_pin_on();
                break;

            default:
                led_set_pattern(PATTERN_ERROR);
                return;
            }
            next_step++;
            if(next_step >= patterns[curPattern].num_steps)
            {
                next_step = 0;
            }
        }
        else
        {
            nextActionTime--;
        }
    }
    // else nothing to do
#ifdef LOOP_MONITOR
    loop_monitor_pin_toggle();
#endif
}

