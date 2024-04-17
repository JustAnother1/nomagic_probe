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
#ifndef CLI_CLI_CFG_H_
#define CLI_CLI_CFG_H_

#include <stdbool.h>
#include <stdint.h>
#ifdef FEAT_DEBUG_UART
#include "../hal/debug_uart.h"
#endif
#ifdef FEAT_DEBUG_CDC
#include "tinyusb/usb_cdc.h"
#endif


typedef bool (*cmd_func_typ)(const uint32_t loop);

typedef struct {
    char name[12];
    char help[100];
    cmd_func_typ func;
}cmd_typ;

#ifdef FEAT_DEBUG_UART
#define SERIAL_SEND_BYTES             debug_uart_send_bytes
#define SERIAL_NUM_RECEIVED_BYTES     debug_uart_get_num_received_bytes
#define SERIAL_GET_NEXT_RECEIVED_BYTE debug_uart_get_next_received_byte
#define SERIAL_TICK                   debug_uart_tick();
#endif

#ifdef FEAT_DEBUG_CDC
#define SERIAL_SEND_BYTES             usb_cdc_send_bytes
#define SERIAL_NUM_RECEIVED_BYTES     usb_cdc_get_num_received_bytes
#define SERIAL_GET_NEXT_RECEIVED_BYTE usb_cdc_get_next_received_byte
#define SERIAL_TICK
// CDC is driven from the USB task, therefore no tick necessary.
#endif


#define MAX_LINE_LENGTH   100
#define MAX_PARAMETERS    10
#define ECHO_ENABLED      true

#define PROMPT "\r\n$ "
#define WELCOME "\r\n\r\n\r\n\r\n\r\nnomagic probe command line interface\r\n"
#define ERROR_LINE_TOO_LONG "\r\n The command is too long! please try again!\r\n"


#endif /* CLI_CLI_CFG_H_ */
