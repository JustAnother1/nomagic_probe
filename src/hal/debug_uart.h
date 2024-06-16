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
#ifndef HAL_DEBUG_UART_H
#define HAL_DEBUG_UART_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "lib/printf.h"

// configure:
#define RECEIVE_BUFFER_SIZE      100
#define SEND_BUFFER_SIZE         500

// initialize:
void debug_uart_initialize(void);
void debug_uart_tick(void);
void debug_uart_flush(void);

// send data:
uint32_t debug_uart_send_bytes(const uint8_t *data, const uint32_t length);
void debug_uart_send_String(char* str);
void debug_putc(void* p, char c);

// get received data:
uint32_t debug_uart_get_num_received_bytes(void);
uint8_t debug_uart_get_next_received_byte(void);
bool debug_uart_get_received_bytes(uint8_t *buf, const uint32_t length);

#endif // HAL_DEBUG_UART_H
