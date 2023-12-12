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

#include "gdbserver_gdbserver_tests.h"
#include "../src/gdbserver/gdbserver.h"

void* gdbserver_gdbserver_setup(const MunitParameter params[], void* user_data) {
    (void)params;
    (void)user_data;
    return NULL;
}

// void reply_packet_add_hex(uint32_t data, uint32_t digits);
MunitResult test_gdbserver_gdbserver_reply_packet_add_hex(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;

    gdbserver_init();
    reply_packet_prepare();
    reply_packet_send();

    return MUNIT_OK;
}
