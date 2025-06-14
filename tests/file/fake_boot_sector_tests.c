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
#include "../src/file/fake_boot_sector.h"
#include "unity.h"



void setUp(void)
{

}

void tearDown(void)
{

}

// int32_t fake_boot_sector(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
void test_fake_boot_sector_OK(void)
{
    // Objective: correct request reads the boot sector
    uint8_t res_buf[512] = {
            0xeb, 0x3c, 0x90, // skip boot sector
            0x4d, 0x53, 0x44, 0x4f, 0x53, 0x35, 0x2e, 0x30, // OEM name : MSDOS5.0
            0x00, 0x02,// 512 Bytes per block
            8, // number of blocks per sector (max 4086 sectors for FAT12! ( 1 -> max 2MB; 2 -> 4MB, 3 -> 6MB, 4 -> 8MB..  8 ->16MB)
            1, 0, // reserved sectors= only the boot sector -> 1
            1, // number of FAT -> only one FAT
            0x80, 0x00, // max number of entries in the root folder (32 Bytes per entry=16 entries per sector of 512 Bytes; 4096 Bytes -> 128 Entries = 0x80
            0xff, 0x07, // number of sectors in this partition  2047 Blocks (1MB)
            0xf8, // Media descriptor Byte - obsolete (0xf8 = hdd)
            0x10, 0x00, // blocks per FAT - 1.5 Bytes(12 bit) per file/directory - 16x512 = 8192 / 1.5 = 5461 Files and directories (8x512 = 4096 / 1.5 = 2730)
            0x01, 0x00, // sectors per track
            0x01, 0x00, // number of read/write heads
            0x00, 0x00, 0x00, 0x00, // number of hidden sectors (between MBR and start of partition
            0x00, 0x00, 0x00, 0x00, // number of sectors if bigger than 65535
            0x80, // physical drive number - 0x80 is first hdd) only important for booting
            0x00, // reserved
            0x29, // extended boot signature must be 0x29
            0x15, 0x08, 0x11, 0x47, // file system id (serial number)
            'n', 'o', 'm', 'a', 'g', 'i', 'c', ' ', 'p', 'r', 'o',  // name of file system - obsolete
            0x46, 0x41, 0x54, 0x31, 0x32, 0x20, 0x20, 0x20, // FAT Version 8 chars filled up with space -> "FAT12   "
            0, 0, // 64
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0, // 128
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0, // 192
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0, // 256
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0, // 320
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0, // 384
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0, // 448
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0,
            0x55, 0xaa, // 512
    };

    uint8_t buffer[512];
    memset(buffer, 0x23, 512);
    fake_boot_sector(0, buffer, 512);
    TEST_ASSERT_EQUAL_MEMORY(res_buf, buffer, 512);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_fake_boot_sector_OK);
    return UNITY_END();
}
