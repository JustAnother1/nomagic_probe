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

#ifndef NOMAGIC_PROBE_SRC_HAL_TARGET_UART_H_
#define NOMAGIC_PROBE_SRC_HAL_TARGET_UART_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "lib/printf.h"

// configure:
#define RECEIVE_BUFFER_SIZE      100
#define SEND_BUFFER_SIZE         500

// initialize:
void target_uart_initialize(void);
void target_uart_tick(void);
void target_uart_flush(void);

// send data:
void target_uart_send_bytes(const uint8_t *data, const uint32_t length);

// get received data:
uint32_t target_uart_get_num_received_bytes(void);
uint8_t target_uart_get_next_received_byte(void);
bool target_uart_get_received_bytes(uint8_t *buf, const uint32_t length);


#endif /* NOMAGIC_PROBE_SRC_HAL_TARGET_UART_H_ */
