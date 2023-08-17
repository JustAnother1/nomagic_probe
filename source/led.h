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
#ifndef LED_H_
#define LED_H_

#include <stdint.h>

// blink patterns
#define PATTERN_NORMAL 0
#define PATTERN_ERROR  1


void led_init(void);
void led_tick(void);
void led_set_pattern(uint32_t pattern);

#endif /* LED_H_ */
