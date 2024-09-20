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

#ifndef NOMAGIC_PROBE_TESTS_MOCK_GDBSERVER_COMMANDS_MOCK_H_
#define NOMAGIC_PROBE_TESTS_MOCK_GDBSERVER_COMMANDS_MOCK_H_

#define CALL_IDX_COMMANDS_INIT      0
#define CALL_IDX_COMMANDS_EXECUTE   1
#define NUM_COMMANDS_CALL_COUNTER   2

void mock_commands_reset_call_counts(void);
uint32_t mock_commands_get_call_counter_of(uint32_t idx);

void mock_commands_reset_commands(void);
uint32_t mock_commands_get_num_received_commands(void);
char* mock_commands_get_command(uint32_t idx);
uint32_t mock_commands_get_length(uint32_t idx);

#endif /* NOMAGIC_PROBE_TESTS_MOCK_GDBSERVER_COMMANDS_MOCK_H_ */
