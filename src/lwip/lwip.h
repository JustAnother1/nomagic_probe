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

#ifndef NOMAGIC_PROBE_SRC_LWIP_LWIP_H_
#define NOMAGIC_PROBE_SRC_LWIP_LWIP_H_

#include <stdbool.h>
#include <stdint.h>

void network_stack_init(void);
void network_stack_tick(void);

// GDB server interface
void network_gdb_send_string(char * str);
void network_gdb_send_bytes(const uint8_t * data, const uint32_t length);
void network_gdb_flush(void);
uint32_t network_gdb_get_num_received_bytes(void);
uint8_t network_gdb_get_next_received_byte(void);
void network_gdb_putc(void* p, char c);
bool network_gdb_is_connected(void);

#endif /* NOMAGIC_PROBE_SRC_LWIP_LWIP_H_ */
