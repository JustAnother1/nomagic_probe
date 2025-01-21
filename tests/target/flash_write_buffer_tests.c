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

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "unity.h"
#include "flash_write_buffer.h"

uint8_t data[1000];

void setUp(void)
{
    memset(data, 0x23, sizeof(data));
    // void flash_write_buffer_init(void);
    flash_write_buffer_init(256);
}

void tearDown(void)
{

}

void test_initialized(void)
{
    // Objective: test initialized default behavior of unused buffer
    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(0, flash_write_buffer_get_write_address());
    TEST_ASSERT_EQUAL_PTR(NULL, flash_write_buffer_get_data_block());
    TEST_ASSERT_EQUAL_UINT32(0, flash_write_buffer_get_length_available_no_waiting());
}

void test_parameter_check(void)
{
    // Objective: move one packet in and out of buffer
    Result res = flash_write_buffer_add_data(1000, 0, &data[0]);
    TEST_ASSERT_EQUAL_INT32(ERR_INVALID_PARAMETER, res);
    res = flash_write_buffer_add_data(1000, 256, NULL);
    TEST_ASSERT_EQUAL_INT32(ERR_INVALID_PARAMETER, res);
}

void test_one_packet(void)
{
    // Objective: move one packet in and out of buffer
    Result res = flash_write_buffer_add_data(1000, 256, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1000, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());

    flash_write_buffer_remove_block();
    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(0, flash_write_buffer_get_length_available_waiting());
}

void test_double_add_packet(void)
{
    // Objective: move one packet in and out of buffer
    Result res = flash_write_buffer_add_data(1000, 256, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);

    res = flash_write_buffer_add_data(1000, 256, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1000, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());

    res = flash_write_buffer_add_data(1000, 256, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
    flash_write_buffer_remove_block();
    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(0, flash_write_buffer_get_length_available_waiting());
}

void test_one_big_packet(void)
{
    // Objective: one gdb packet has enough data for two flash blocks
    Result res = flash_write_buffer_add_data(1000, 512, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1000, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1256, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();

    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(0, flash_write_buffer_get_length_available_waiting());
}

void test_one_bigger_packet(void)
{
    // Objective: one gdb packet has enough data for two flash blocks and some extra bytes
    Result res = flash_write_buffer_add_data(1000, 520, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1000, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1256, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();

    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(8, flash_write_buffer_get_length_available_waiting());
    TEST_ASSERT_EQUAL_UINT32(1512, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();

    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(0, flash_write_buffer_get_length_available_waiting());
}

// !!! assumes buffer size 2048  !!!
void test_fill_buffer(void)
{
    // Objective: we can only accept so many gdb packets
    Result res = flash_write_buffer_add_data(1000, 200, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
    res = flash_write_buffer_add_data(1200, 900, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
    res = flash_write_buffer_add_data(2100, 900, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
    res = flash_write_buffer_add_data(3000, 100, &data[0]);
    TEST_ASSERT_EQUAL_INT32(ERR_TOO_LONG, res);
}

// !!! assumes buffer size 2048  !!!
void test_wrap_around_big_packets(void)
{
    // Objective: let the buffer wrap around with big incoming packets
    Result res = flash_write_buffer_add_data(1000, 950, &data[0]);
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
// Buffer: Start Address = 1000, bytes in Buffer = 950

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1000, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 1256, bytes in Buffer = 950 - 256 = 694

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1256, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 1512, bytes in Buffer = 694 - 256 = 438

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1512, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 1768, bytes in Buffer = 438 - 256 = 182

    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(182, flash_write_buffer_get_length_available_waiting());

    res = flash_write_buffer_add_data(1950, 950, &data[0]); // 1950 = 1000 + 950
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
// Buffer: Start Address = 1768, bytes in Buffer = 182 + 950 = 1132

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(1768, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 2024, bytes in Buffer = 1132 - 256 = 876

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(2024, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 2280, bytes in Buffer = 876 - 256 = 620

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(2280, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 2536, bytes in Buffer = 620 - 256 = 364

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(2536, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 2792, bytes in Buffer = 364 - 256 = 108

    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(108, flash_write_buffer_get_length_available_waiting());

    res = flash_write_buffer_add_data(2900, 950, &data[0]); // 2900 = 1950 + 950
    TEST_ASSERT_EQUAL_INT32(RESULT_OK, res);
// Buffer: Start Address = 2792, bytes in Buffer = 108 + 950 = 1058

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(2792, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 3048, bytes in Buffer = 1058 - 256 = 802

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(3048, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 3304, bytes in Buffer = 802 - 256 = 546

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(3304, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 3560, bytes in Buffer = 546 - 256 = 290

    TEST_ASSERT_TRUE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(3560, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();
// Buffer: Start Address = 3816, bytes in Buffer = 290 - 256 = 34

    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(34, flash_write_buffer_get_length_available_waiting());
    TEST_ASSERT_EQUAL_UINT32(3816, flash_write_buffer_get_write_address());
    TEST_ASSERT_NOT_NULL(flash_write_buffer_get_data_block());
    flash_write_buffer_remove_block();

    TEST_ASSERT_FALSE(flash_write_buffer_has_data_block());
    TEST_ASSERT_EQUAL_UINT32(0, flash_write_buffer_get_length_available_waiting());
}

// void flash_write_buffer_init(uint32_t block_size_bytes);
// Result flash_write_buffer_add_data(uint32_t start_address, uint32_t length, uint8_t* data);
// bool flash_write_buffer_has_data_block(void);
// uint32_t flash_write_buffer_get_write_address(void);
// uint8_t* flash_write_buffer_get_data_block(void);
// void flash_write_buffer_remove_block(void);
// uint32_t flash_write_buffer_get_length_available_no_waiting(void);
// uint32_t flash_write_buffer_get_length_available_waiting(void);


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_initialized);
    RUN_TEST(test_parameter_check);
    RUN_TEST(test_one_packet);
    RUN_TEST(test_double_add_packet);
    RUN_TEST(test_one_big_packet);
    RUN_TEST(test_one_bigger_packet);
    RUN_TEST(test_fill_buffer);
    RUN_TEST(test_wrap_around_big_packets);

    // RUN_TEST(newTest);
    return UNITY_END();
}
