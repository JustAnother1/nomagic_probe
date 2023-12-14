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

#include "gdbserver_util_tests.h"
#include "../src/gdbserver/util.h"

void* gdbserver_util_setup(const MunitParameter params[], void* user_data) {
    (void)params;
    (void)user_data;
    return NULL;
}

// uint32_t hex_to_int(char* hex, uint32_t num_digits);
MunitResult test_gdbserver_util_hex_to_int(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;

    char val[] = "123"; // 0x123 == 291
    uint32_t res = hex_to_int(val, 3);
    munit_assert_uint32(res, ==, 291);

    res = hex_to_int(val, 2); // only 2 digits = 0x12
    munit_assert_uint32(res, ==, 18);

    res = hex_to_int(val, 4); // invalid
    munit_assert_uint32(res, ==, 0);

    return MUNIT_OK;
}

// void int_to_hex(char* hex, uint32_t value, uint32_t num_digits)
MunitResult test_gdbserver_util_int_to_hex(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;

    uint32_t i;
    char string_val[10];

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }

    uint32_t intval = 51966; // 0xcafe = 51966
    int_to_hex(string_val, intval, 4);
    munit_assert_char(string_val[4], ==, 'y');
    munit_assert_char(string_val[3], ==, 'c');
    munit_assert_char(string_val[2], ==, 'a');
    munit_assert_char(string_val[1], ==, 'f');
    munit_assert_char(string_val[0], ==, 'e');

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }
    int_to_hex(string_val, intval, 2);
    munit_assert_char(string_val[4], ==, 'y');
    munit_assert_char(string_val[3], ==, 'y');
    munit_assert_char(string_val[2], ==, 'y');
    munit_assert_char(string_val[1], ==, 'f');
    munit_assert_char(string_val[0], ==, 'e');

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }
    int_to_hex(string_val, 500, 0);
    munit_assert_char(string_val[4], ==, 'y');
    munit_assert_char(string_val[3], ==, 'y');
    munit_assert_char(string_val[2], ==, 'y');
    munit_assert_char(string_val[1], ==, 'y');
    munit_assert_char(string_val[0], ==, 'y');

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }
    int_to_hex(string_val, 500, 4);
    munit_assert_char(string_val[4], ==, 'y');
    munit_assert_char(string_val[3], ==, '0');
    munit_assert_char(string_val[2], ==, '1');
    munit_assert_char(string_val[1], ==, 'f');
    munit_assert_char(string_val[0], ==, '4');


    return MUNIT_OK;
}
