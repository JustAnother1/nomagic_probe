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
#include "fake_favicon.h"
#include "fake_fat.h"
#include "file/file_system.h"

// https://de.wikipedia.org/wiki/File_Allocation_Table

// FAT Table
// Sector  | content
// -       | FAT
//         | Root Directory
// 2       | Readme.txt
// 3       | autorun.inf
// 4       | favicon.ico
// 5       | favicon.ico

const uint8_t fat_table[] = {
        // free                        == 0x000
        // bad cluster                 == 0xff7
        // last cluster for file       == 0xff8..0xfff
        // cluster belonging to a file == 0x002 .. 0xff6
        0xF8, 0xFF, 0xFF, // 0 + 1 // first 2 entries must be F8FF
        0xFF, 0xFF, 0xFF, // 2 + 3
#ifdef FAVICON_16
        0xff, 0x0F, // 4
#endif
#ifdef FAVICON_32
        0x05, 0xf0, 0xff,  // 4 + 5
#endif
};

// data gets stored inverted in Flash as an empty FAT entry is all 0.
// This should make it possible to just overwrite the Flash memory if a new entry is created.

int32_t fake_fat_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t i;
    uint32_t some = 0;
    int32_t res = file_system_read((FS_SECTOR_FAT * FLASH_SECTOR_SIZE) + offset, buffer, bufsize);
    if(res != (int32_t)bufsize)
    {
        return -2;
    }
    if(offset < sizeof(fat_table))
    {
        // copy in the fixed bit
        some = sizeof(fat_table) - offset;
        if(some > bufsize)
        {
            some = bufsize;
        }
        memcpy(buffer, &fat_table[offset], some);
    }
    // invert everything else
    for(i = some; i < bufsize; i++)
    {
        buffer[i] = ~buffer[i];
    }
    return (int32_t)bufsize;
}

int32_t fake_fat_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t i;
    for(i = 0; i < bufsize; i++)
    {
        buffer[i] = ~buffer[i];
    }
    return file_system_write((FS_SECTOR_FAT * FLASH_SECTOR_SIZE) + offset, buffer, bufsize);
}
