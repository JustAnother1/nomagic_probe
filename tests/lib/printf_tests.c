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

#define STRING_BUFFER_LENGTH  100

char str_buffer[100];
unsigned int buf_idx;
bool putc_issue;

static void test_putc(void* p, char c)
{
    (void) p; // not used
    str_buffer[buf_idx] = c;
    buf_idx++;
    if(STRING_BUFFER_LENGTH == buf_idx)
    {
        buf_idx = 0;
        putc_issue = true;
    }
}

void setUp(void)
{
    putc_issue = false;
    buf_idx = 0;
    init_printf(NULL, test_putc);
}

void tearDown(void)
{

}

void test_printf_init(void)
{
    // init_printf()  <-- part of setUp()
    TEST_ASSERT_FALSE(putc_issue);
}

void test_printf_printf_str(void)
{
    my_printf("Hello World !\r\n");
    TEST_ASSERT_EQUAL_UINT32(15, buf_idx);
    str_buffer[buf_idx] = 0;
    TEST_ASSERT_EQUAL_STRING("Hello World !\r\n", str_buffer);
}

void test_printf_printf_int(void)
{
    uint32_t val = 5;
    my_printf("Value = %d", val);
    TEST_ASSERT_EQUAL_UINT32(9, buf_idx);
    str_buffer[buf_idx] = 0;
    TEST_ASSERT_EQUAL_STRING("Value = 5", str_buffer);
}

void test_printf_printf_digits(void)
{
    const char* expected = "Value = 54321";
    uint32_t val = 54321;
    my_printf("Value = %d", val);
    TEST_ASSERT_EQUAL_UINT32(strlen(expected), buf_idx);
    str_buffer[buf_idx] = 0;
    TEST_ASSERT_EQUAL_STRING(expected, str_buffer);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_printf_init);
    RUN_TEST(test_printf_printf_str);
    RUN_TEST(test_printf_printf_int);
    RUN_TEST(test_printf_printf_digits);
    return UNITY_END();
}
