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

#ifndef NOMAGIC_PROBE_TESTS_MOCK_SERIAL_GDB_H_
#define NOMAGIC_PROBE_TESTS_MOCK_SERIAL_GDB_H_

#define TST_GDB_RECEIVE_BUFFER_SIZE      1000
#define TST_GDB_SEND_BUFFER_SIZE         5000

void gdb_reset_send_receive_buffers(void);
uint32_t gdb_get_num_bytes_in_recv_buffer(void);
void gdb_dump_send_buffer(void);
uint32_t gdb_get_num_bytes_in_send_buffer(void);
bool gdb_mock_get_received_bytes(uint8_t *buf, uint32_t length);
void gdb_send_bytes_to_cli(uint8_t *buf, uint32_t length);
void gdb_dump_buffer_ascii(char* buffer, uint32_t length);

#endif /* NOMAGIC_PROBE_TESTS_MOCK_SERIAL_GDB_H_ */
