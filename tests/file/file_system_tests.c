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
#include "unity.h"
#include "../src/file/file_system.h"

// the linker file provides these:
uint32_t linker_data_start = 0;
uint32_t linker_data_end = 10;
uint32_t linker_data_in_flash = 0;

uint32_t linker_code_start = 11;
uint32_t linker_code_end = 20;
uint32_t linker_code_in_flash = 20;

uint32_t linker_ro_data_start = 21;
uint32_t linker_ro_data_end = 25;
uint32_t linker_ro_data_in_flash = 30;



void setUp(void)
{

}

void tearDown(void)
{

}

void test_file_sytem_init(void)
{
    file_system_init();
    TEST_ASSERT_EQUAL_INT32(2048, file_system_block_count());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_file_sytem_init);
    return UNITY_END();
}
