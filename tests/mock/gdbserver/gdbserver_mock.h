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

#ifndef NOMAGIC_PROBE_TESTS_MOCK_GDBSERVER_GDBSERVER_MOCK_H_
#define NOMAGIC_PROBE_TESTS_MOCK_GDBSERVER_GDBSERVER_MOCK_H_

#include <stdint.h>

void mock_gdbserver_reset_replies(void);
uint32_t mock_gdbserver_get_num_send_replies(void);
char* mock_gdbserver_get_reply(uint32_t idx);

#endif /* NOMAGIC_PROBE_TESTS_MOCK_GDBSERVER_GDBSERVER_MOCK_H_ */
