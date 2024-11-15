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

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "../src/lib/printf.h"
#include "unity.h"
#include "mock/lib/printf_mock.h"


void setUp(void)
{
    init_printf_mock();
}

void tearDown(void)
{

}

void test_printf_init(void)
{
    // init_printf()  <-- part of setUp()
    TEST_ASSERT_FALSE(printf_mock_had_putc_issue());
}

void test_printf_printf_str(void)
{
    my_printf("Hello World !\r\n");
    TEST_ASSERT_EQUAL_UINT32(15, printf_mock_get_write_idx());
    TEST_ASSERT_EQUAL_STRING("Hello World !\r\n", printf_mock_get_as_String());
}

void test_printf_printf_int(void)
{
    uint32_t val = 5;
    my_printf("Value = %d", val);
    TEST_ASSERT_EQUAL_UINT32(9, printf_mock_get_write_idx());
    TEST_ASSERT_EQUAL_STRING("Value = 5", printf_mock_get_as_String());
}

void test_printf_printf_digits(void)
{
    const char* expected = "Value = 54321";
    uint32_t val = 54321;
    my_printf("Value = %d", val);
    TEST_ASSERT_EQUAL_UINT32(strlen(expected), printf_mock_get_write_idx());
    TEST_ASSERT_EQUAL_STRING(expected, printf_mock_get_as_String());
}

void test_printf_printf_width(void)
{
    const char* expected = "Value =   1";
    uint32_t val = 1;
    my_printf("Value = %3d", val);
    TEST_ASSERT_EQUAL_UINT32(strlen(expected), printf_mock_get_write_idx());
    TEST_ASSERT_EQUAL_STRING(expected, printf_mock_get_as_String());
}

void test_printf_printf_width_long(void)
{
    const char* expected = "Value =   5";
    uint32_t val = 5;
    my_printf("Value = %3ld", val);
    TEST_ASSERT_EQUAL_UINT32(strlen(expected), printf_mock_get_write_idx());
    TEST_ASSERT_EQUAL_STRING(expected, printf_mock_get_as_String());
}



int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_printf_init);
    RUN_TEST(test_printf_printf_str);
    RUN_TEST(test_printf_printf_int);
    RUN_TEST(test_printf_printf_digits);
    RUN_TEST(test_printf_printf_width);
    RUN_TEST(test_printf_printf_width_long);
    return UNITY_END();
}
