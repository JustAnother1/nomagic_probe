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
#include "../src/file/fake_root_folder.h"
#include "../src/file/fake_text_files.h"
#include "unity.h"



void setUp(void)
{

}

void tearDown(void)
{

}

// int32_t fake_root_folder_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
void test_fake_fat_read_OK(void)
{
    // Objective: correct request reads the FAT
    int32_t res = 0;
    uint8_t res_buf[512] = {
            // volume label
            'n', 'o', 'm', 'a', 'g', 'i', 'c', ' ', 'p', 'r', 'o',   // 11 chars (8+3)
            0x08, // Attribute :
            // Bit 0: write protected; //    1
            // Bit 1: hidden;          //    2
            // Bit 2: system file;     //    4
            // Bit 3: Volume-Label;    //    8
            // Bit 4: sub directory;   // 0x10
            // Bit 5: Archive;         // 0x20
            // Bit 6–7: not used
            // VFAT uses 0x0F
            0x00, // reserved
            0x00, // creation time ms (0..199
            0x00, 0x00, // creation time
            0x00, 0x00, // creation date
            0x00, 0x00, // date of last access
            0x00, 0x00, // FAT32 only
            0x00, 0x00, // time of last change (5 bit hour, 6 bit minute, 5 bit seconds
            0x00, 0x00, // date of last change (7 bit Year, 4 bit mounth, 5 bit day. Years is years since 1980. 2020 = 40, up to 2107)
            0x00, 0x00, // start cluster
            0x00, 0x00, 0x00, 0x00, // file size in byte

            'R' , 'E' , 'A' , 'D' , 'M' , 'E' , ' ' , ' ' , 'T' , 'X' , 'T' ,
            0x21,
            0x00,
            0xC6,
            0x52, 0x6D,
            0x65, 0x43,
            0x65, 0x43,
            0x00, 0x00,
            0x88, 0x6D,
            0x65, 0x43,
            0x02, 0x00,
            sizeof(README_CONTENTS)-1, 0x00, 0x00, 0x00, // readme's files size (4 Bytes)

            'a' , 'u' , 't' , 'o' , 'r' , 'u' , 'n' , ' ' , 'i' , 'n' , 'f' ,
            0x21,
            0x00,
            0xC6,
            0x52, 0x6D,
            0x65, 0x43,
            0x65, 0x43,
            0x00, 0x00,
            0x88, 0x6D,
            0x65, 0x43,
            0x03, 0x00,
            sizeof(autorun_inf_CONTENTS)-1, 0x00, 0x00, 0x00, // files size (4 Bytes)

            'f' , 'a' , 'v' , 'i' , 'c' , 'o' , 'n' , ' ' , 'i' , 'c' , 'o' ,
            0x21,
            0x00,
            0xC6,
            0x52, 0x6D,
            0x65, 0x43,
            0x65, 0x43,
            0x00, 0x00,
            0x88, 0x6D,
            0x65, 0x43,
            0x04, 0x00,
            0xbe, 0x10, 0x00, 0x00, // files size (4 Bytes) 4286 Byte = 10be

            0,
    };

    uint8_t buffer[512];
    memset(buffer, 0x23, 512);
    res = fake_root_folder_read(0, buffer, 512);
    TEST_ASSERT_EQUAL_INT32(res, 512);
    TEST_ASSERT_EQUAL_MEMORY(res_buf, buffer, 512);
}

// int32_t fake_root_folder_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
void test_fake_fat_write_OK(void)
{
    // Objective: correct request writes the FAT
    int32_t res = 0;
    uint8_t res_buf[512] = { 0

    };

    uint8_t buffer[512];
    memset(buffer, 0x23, 512);
    res = fake_root_folder_write(0, buffer, 512);
    TEST_ASSERT_EQUAL_INT32(res, 512);
    // TEST_ASSERT_EQUAL_MEMORY(res_buf, buffer, 512);  TODO
}

// fat_entry* fake_root_get_entry_of_file_named(const char* filename);
// fat_entry* fake_root_get_entry_of_file_idx(const uint32_t idx);

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_fake_fat_read_OK);
    RUN_TEST(test_fake_fat_write_OK);
    return UNITY_END();
}
