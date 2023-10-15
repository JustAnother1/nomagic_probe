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


int32_t fake_fat(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    // TODO this needs to go into Flash memory
    if(0 == block)
    {
        if(offset < sizeof(fat_table))
        {
            some = sizeof(fat_table) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &fat_table[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}
