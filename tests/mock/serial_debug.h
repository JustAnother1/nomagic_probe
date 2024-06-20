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

#ifndef NOMAGIC_PROBE_TESTS_MOCK_SERIAL_DEBUG_H_
#define NOMAGIC_PROBE_TESTS_MOCK_SERIAL_DEBUG_H_

#define TST_RECEIVE_BUFFER_SIZE      100
#define TST_SEND_BUFFER_SIZE         500


void reset_send_receive_buffers(void);
bool mock_echo(void);
void set_echo_enabled(bool val);
uint32_t get_num_bytes_in_recv_buffer(void);
void dump_send_buffer(void);
uint32_t get_num_bytes_in_send_buffer(void);
bool mock_get_received_bytes(uint8_t *buf, uint32_t length);
void send_bytes_to_cli(uint8_t *buf, uint32_t length);
void dump_buffer_ascii(char* buffer, uint32_t length);
void serial_debug_send_string(char * str);
void serial_debug_send_bytes(const uint8_t * data, const uint32_t length);
uint32_t serial_debug_get_num_received_bytes(void);
uint8_t serial_debug_get_next_received_byte(void);
void serial_debug_putc(void* p, char c);


#endif /* NOMAGIC_PROBE_TESTS_MOCK_SERIAL_DEBUG_H_ */
