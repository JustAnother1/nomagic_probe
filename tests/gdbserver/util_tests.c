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
    char binary[11] = {'A', '\n', '\r', 'h', 31, 12, 127, ' ', '1', '2', 0};

    binary_to_ascii_dump(&binary[0], 10);
    TEST_ASSERT_EQUAL_STRING("A..h... 12", binary);
}

void test_gdbserver_util_encode_text_to_hex_string(void)
{
    char hex[20];

    encode_text_to_hex_string("bla", 20, hex);
    TEST_ASSERT_EQUAL_STRING("626c61", hex);
}

void test_gdbserver_util_encode_text_to_hex_string_buf_is_null(void)
{
    char hex[20];

    hex[0] = 'a';
    hex[1] = 0;
    encode_text_to_hex_string("bla", 20, NULL);
    TEST_ASSERT_EQUAL_STRING("a", hex);
}

void test_gdbserver_util_encode_text_to_hex_string_text_is_null(void)
{
    char hex[20];

    hex[0] = 'a';
    hex[1] = 0;
    encode_text_to_hex_string(NULL, 20, hex);
    TEST_ASSERT_EQUAL_STRING("", hex);
}

void test_gdbserver_util_encode_text_to_hex_string_buffer_too_short(void)
{
    char hex[20];

    hex[0] = 'a';
    hex[1] = 0;
    encode_text_to_hex_string("foobar", 7, hex);
    TEST_ASSERT_EQUAL_STRING("666f6f", hex);
}

void test_gdbserver_util_decode_hex_string_to_text(void)
{
    char text[20];

    decode_hex_string_to_text("626c61", 20, text);

    TEST_ASSERT_EQUAL_STRING("bla", text);
}

void test_gdbserver_util_decode_hex_string_to_text_hex_is_null(void)
{
    char text[20];
    text[0] = 'a';
    text[1] = 0;

    decode_hex_string_to_text(NULL, 20, text);

    TEST_ASSERT_EQUAL_STRING("", text);
}

void test_gdbserver_util_decode_hex_string_to_text_buf_is_null(void)
{
    char text[20];
    text[0] = 'a';
    text[1] = 0;

    decode_hex_string_to_text("626c61", 20, NULL);

    TEST_ASSERT_EQUAL_STRING("a", text);
}

void test_gdbserver_util_decode_hex_string_to_text_buffer_too_short(void)
{
    char text[20];

    text[0] = 'a';
    text[1] = 0;
    decode_hex_string_to_text("666f6f626172", 4, text); // 4 = 3 characters + \0
    TEST_ASSERT_EQUAL_STRING("foo", text);
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
    RUN_TEST(test_gdbserver_util_encode_text_to_hex_string);
    RUN_TEST(test_gdbserver_util_encode_text_to_hex_string_buf_is_null);
    RUN_TEST(test_gdbserver_util_encode_text_to_hex_string_text_is_null);
    RUN_TEST(test_gdbserver_util_encode_text_to_hex_string_buffer_too_short);
    // RUN_TEST(test_gdbserver_util_decode_hex_string_to_text);
    // RUN_TEST(test_gdbserver_util_decode_hex_string_to_text_hex_is_null);
    // RUN_TEST(test_gdbserver_util_decode_hex_string_to_text_buf_is_null);
    RUN_TEST(test_gdbserver_util_decode_hex_string_to_text_buffer_too_short);
    return UNITY_END();
}
