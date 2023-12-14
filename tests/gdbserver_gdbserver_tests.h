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
#ifndef TESTS_GDBSERVER_GDBSERVER_TESTS_H_
#define TESTS_GDBSERVER_GDBSERVER_TESTS_H_

#include "munit.h"
#include <stdint.h>
#include <stdbool.h>

void* gdbserver_gdbserver_setup(const MunitParameter params[], void* user_data);

MunitResult test_gdbserver_empty_packet(const MunitParameter params[], void* user_data);
MunitResult test_gdbserver_hex(const MunitParameter params[], void* user_data);
MunitResult test_gdbserver_hex_sqish(const MunitParameter params[], void* user_data);

#endif /* TESTS_GDBSERVER_GDBSERVER_TESTS_H_ */
