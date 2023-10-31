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
#include "fake_boot_sector.h"

const uint8_t boot_sector[62] = {
        0xeb, 0x3c, 0x90, // skip boot sector
        0x4d, 0x53, 0x44, 0x4f, 0x53, 0x35, 0x2e, 0x30, // OEM name : MSDOS5.0
        0x00, 0x02,// 512 Bytes per block
        8, // number of blocks per sector (max 4086 sectors for FAT12! ( 1 -> max 2MB; 2 -> 4MB, 3 -> 6MB, 4 -> 8MB..  8 ->16MB)
        1, 0, // reserved sectors= only the boot sector -> 1
        1, // number of FAT -> only one FAT
        0x80, 0x00, // max number of entries in the root folder (32 Bytes per entry=16 entries per sector of 512 Bytes; 4096 Bytes -> 128 Entries = 0x80
        0xff, 0x00, // number of sectors in this partition  2047 Blocks -> 255 Sectors
        0xf8, // Media descriptor Byte - obsolete (0xf8 = hdd)
        0x10, 0x00, // blocks per FAT
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
};

int32_t fake_boot_sector(uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    uint32_t end = offset + (uint32_t)bufsize;

    if(offset < sizeof(boot_sector))
    {
        some = sizeof(boot_sector) - offset;
        if(some > bufsize)
        {
            some = bufsize;
        }
        memcpy(buffer, &boot_sector[offset], some);
    }
    memset(&buffer[some], 0, bufsize - some);
    if(512 == end)
    {
        buffer[bufsize -1] = 0xaa;
        buffer[bufsize -2 ] = 0x55;
    }
    if(511 == end)
    {
        buffer[bufsize -1] = 0x55;
    }
    return (int32_t)bufsize;
}

