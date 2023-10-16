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

#include <string.h>
#include "fake_mbr.h"

// https://de.wikipedia.org/wiki/Master_Boot_Record

const uint8_t mbr_partition_table[66] = {
        // partition table (4 entries)

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

int32_t fake_mbr(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    uint32_t end = offset + (uint32_t)bufsize -1;
    (void) block;

    if(end < 446)
    {
        // all Zeros
        memset(buffer, 0, (size_t)bufsize);
        return (int32_t)bufsize;
    }
    if(offset < 446)
    {
        // some zeros
        some = 446 - offset; // some will be smaller than bufsize, as end is bufsize + offset
        memset(buffer, 0, some);
        offset = 446;
    }
    memcpy(&buffer[some], &mbr_partition_table[offset-446], bufsize- some);
    return (int32_t)bufsize;
}
