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
#include "../src/file/fake_mbr.h"
#include "unity.h"

// https://en.wikipedia.org/wiki/Master_boot_record
// Address         Description               Size(bytes)
// 0x0000 (0)      Bootstrap code area       446
// Partition table (for primary partitions)
// 0x01BE (446)    Partition entry 1         16
// 0x01CE (462)    Partition entry 2         16
// 0x01DE (478)    Partition entry 3         16
// 0x01EE (494)    Partition entry 4         16
// Boot signature                            2
// 0x01FE (510)    0x55
// 0x01FF (511)    0xAA
//
// Total size: 446 + 4×16 + 2 = 512



void setUp(void)
{

}

void tearDown(void)
{

}

// int32_t fake_mbr(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
void test_fake_mbr_OK(void)
{
    // Objective: correct request reads the boot sector
    uint8_t res_buf[512] = {
            // partition table (4 entries)
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0, // 64
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
            0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, // 446

            // first entry:
            0x00, // do not boot
            0xff, 0xff, 0xff, // CHS first sector
            0x01, // type = FAT12
            0xff, 0xff, 0xff, // CHS last sector
            0x01, 0x00, 0x00, 0x00,// LBA start
            0xff, 0x07, 0x00, 0x00, // LBA length 0x7ff = 2047

            // second entry:
            0x00, // do not boot
            0x00, 0x00, 0x00, // CHS first sector
            0x00, // type unused
            0x00, 0x00, 0x00, // CHS last sector
            0x00, 0x00, 0x00, 0x00,// LBA start
            0x00, 0x00, 0x00, 0x00, // LBA length

            // third entry:
            0x00, // do not boot
            0x00, 0x00, 0x00, // CHS first sector
            0x00, // type unused
            0x00, 0x00, 0x00, // CHS last sector
            0x00, 0x00, 0x00, 0x00,// LBA start
            0x00, 0x00, 0x00, 0x00, // LBA length

            // fourth entry:
            0x00, // do not boot
            0x00, 0x00, 0x00, // CHS first sector
            0x00, // type unused
            0x00, 0x00, 0x00, // CHS last sector
            0x00, 0x00, 0x00, 0x00,// LBA start
            0x00, 0x00, 0x00, 0x00, // LBA length

            0x55, 0xaa // signature
    };

    int32_t res;
    uint8_t buffer[512];
    memset(buffer, 0x23, 512);
    res = fake_mbr(0, buffer, 512);
    TEST_ASSERT_EQUAL_INT32(res, 512);
    TEST_ASSERT_EQUAL_MEMORY(res_buf, buffer, 512);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_fake_mbr_OK);
    return UNITY_END();
}
