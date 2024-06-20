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

#ifndef NOMAGIC_PROBE_SRC_CFG_SERIAL_CFG_H_
#define NOMAGIC_PROBE_SRC_CFG_SERIAL_CFG_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tinyusb/usb_cdc.h"
#include "tinyusb/src/class/cdc/cdc_device.h"

// configuration settings
#define CDC_ENABLED_SETTING "cdc"

// DEBUG CLI interface
void serial_debug_send_string(char * str);
void serial_debug_send_bytes(const uint8_t * data, const uint32_t length);
uint32_t serial_debug_get_num_received_bytes(void);
uint8_t serial_debug_get_next_received_byte(void);
void serial_debug_putc(void* p, char c);

// GDB Interface
#define MAX_COMMAND_LENGTH    1025
#define MAX_REPLY_LENGTH      2000

void serial_gdb_send_string(char * str);
void serial_gdb_send_bytes(const uint8_t * data, const uint32_t length);
uint32_t serial_gdb_get_num_received_bytes(void);
uint8_t serial_gdb_get_next_received_byte(void);
void serial_gdb_putc(void* p, char c);
bool serial_gdb_is_connected(void);
void serial_gdb_flush(void);


// load configuration
void serial_cfg_reset_to_default(void);
void serial_cfg_set(char * setting, char * value);
void serial_cfg_apply(void);
bool serial_cfg_is_USB_CDC_enabled(void);


#endif /* NOMAGIC_PROBE_SRC_CFG_SERIAL_CFG_H_ */
