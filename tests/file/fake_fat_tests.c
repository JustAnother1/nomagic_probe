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

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "../src/file/fake_fat.h"
#include "unity.h"



void setUp(void)
{

}

void tearDown(void)
{

}

// int32_t fake_fat_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
void test_fake_fat_read_OK(void)
{
    // Objective: correct request reads the FAT
    int32_t res = 0;
    uint8_t res_buf[512] = {
            0xF8, 0xFF, 0xFF, // 0 + 1 // first 2 entries must be F8FF
            0xFF, 0xFF, 0xFF, // 2 + 3
            0x05, 0xf0, 0xff,  // 4 + 5
            0
    };

    uint8_t buffer[512];
    memset(buffer, 0x23, 512);
    res = fake_fat_read(0, buffer, 512);
    TEST_ASSERT_EQUAL_INT32(res, 512);
    TEST_ASSERT_EQUAL_MEMORY(res_buf, buffer, 512);
}

// int32_t fake_fat_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
void test_fake_fat_write_OK(void)
{
    // Objective: correct request writes the FAT
    int32_t res = 0;
    uint8_t res_buf[512] = { 0

    };

    uint8_t buffer[512];
    memset(buffer, 0x23, 512);
    res = fake_fat_write(0, buffer, 512);
    TEST_ASSERT_EQUAL_INT32(res, 512);
    // TEST_ASSERT_EQUAL_MEMORY(res_buf, buffer, 512);  TODO
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_fake_fat_read_OK);
    RUN_TEST(test_fake_fat_write_OK);
    return UNITY_END();
}
