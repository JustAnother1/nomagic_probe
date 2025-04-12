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

#include "unity.h"
#include "probe_api/util.h"

void setUp(void)
{

}

void tearDown(void)
{

}

// uint32_t hex_to_int(char* hex, uint32_t num_digits);
void test_gdbserver_util_hex_to_int(void)
{
    char val[] = "123"; // 0x123 == 291
    uint32_t res = hex_to_int(val, 3);
    TEST_ASSERT_EQUAL_UINT32(291, res);

    res = hex_to_int(val, 2); // only 2 digits = 0x12
    TEST_ASSERT_EQUAL_UINT32(18, res);

    res = hex_to_int(val, 4); // invalid
    TEST_ASSERT_EQUAL_UINT32(0, res);
}

// void int_to_hex(char* hex, uint32_t value, uint32_t num_digits)
void test_gdbserver_util_int_to_hex_16bit(void)
{
    uint32_t i;
    char string_val[10];

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }

    uint32_t intval = 51966; // 0xcafe = 51966
    int_to_hex(string_val, intval, 4);
    TEST_ASSERT_EQUAL_STRING("fecayyyyyy", string_val);
}

void test_gdbserver_util_int_to_hex_partof16bit(void)
{
    uint32_t i;
    char string_val[10];
    uint32_t intval = 51966; // 0xcafe = 51966

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }
    int_to_hex(string_val, intval, 2);
    TEST_ASSERT_EQUAL_STRING("feyyyyyyyy", string_val);
}

void test_gdbserver_util_int_to_hex_numDigits0(void)
{
    uint32_t i;
    char string_val[10];

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }
    int_to_hex(string_val, 500, 0);// 500 = 0x1f4
    TEST_ASSERT_EQUAL_STRING("f401yyyyyy", string_val);
}

void test_gdbserver_util_int_to_hex_leadingZero_16bit(void)
{
    uint32_t i;
    char string_val[10];
    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }
    int_to_hex(string_val, 500, 4);
    TEST_ASSERT_EQUAL_STRING("f401yyyyyy", string_val);
}

void test_gdbserver_util_int_to_hex_8bit(void)
{
    uint32_t i;
    char string_val[10];

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }

    uint32_t intval = 66; // 0x42 = 66
    int_to_hex(string_val, intval, 2);
    TEST_ASSERT_EQUAL_STRING("42yyyyyyyy", string_val);
}

void test_gdbserver_util_int_to_hex_8bit_numDigits0(void)
{
    uint32_t i;
    char string_val[10];

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }

    uint32_t intval = 18; // 0x12 = 18
    int_to_hex(string_val, intval, 0);
    TEST_ASSERT_EQUAL_STRING("12yyyyyyyy", string_val);
}

void test_gdbserver_util_int_to_hex_32bit(void)
{
    uint32_t i;
    char string_val[10];

    for(i = 0; i < 10; i++)
    {
        string_val[i] = 'y';
    }

    uint32_t intval = 2018915346; // 0x12345678 = 305419896 0x78563412 = 2018915346
    int_to_hex(string_val, intval, 8);
    TEST_ASSERT_EQUAL_STRING("12345678yy", string_val);
}

void test_gdbserver_util_binary_to_ascii_dump(void)
{
    uint32_t i;
    char binary[11] = {'A', '\n', '\r', 'h', 31, 12, 127, '1', '2', 0};

    binary_to_ascii_dump(&binary[0], 10);
    TEST_ASSERT_EQUAL_STRING("A..h... 12", binary);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_gdbserver_util_hex_to_int);
    RUN_TEST(test_gdbserver_util_int_to_hex_16bit);
    RUN_TEST(test_gdbserver_util_int_to_hex_partof16bit);
    RUN_TEST(test_gdbserver_util_int_to_hex_numDigits0);
    RUN_TEST(test_gdbserver_util_int_to_hex_leadingZero_16bit);
    RUN_TEST(test_gdbserver_util_int_to_hex_8bit);
    RUN_TEST(test_gdbserver_util_int_to_hex_8bit_numDigits0);
    RUN_TEST(test_gdbserver_util_int_to_hex_32bit);
    RUN_TEST(test_gdbserver_util_binary_to_ascii_dump);
    return UNITY_END();
}
