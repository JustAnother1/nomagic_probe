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
#include "faked_disk.h"
#include "file_storage.h"

#include "fake_mbr.h"
#include "fake_boot_sector.h"
#include "fake_fat.h"
#include "fake_root_folder.h"
#include "fake_text_files.h"
#include "fake_favicon.h"




int32_t faked_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t end = offset + (uint32_t)bufsize -1;
    if(end >= BLOCK_SIZE)
    {
        // read outside of block requested
        return -2;
    }

    // MBR + boot sector
    if(0 == block)
    {
        // MBR
        return fake_mbr(block, offset, buffer, bufsize);
    }
    else if(1 == block)
    {
        // boot sector
        return fake_boot_sector(block, offset, buffer, bufsize);
    }
    block = block -2;

    // FAT
    if(16 > block)
    {
        // FAT - File Allocation Table
        return fake_fat(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -16;
    }

    // root folder
    if(8 > block)
    {
        // root folder
        return fake_root_folder(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // read me file
    if(8 > block)
    {
        // read me file
        return fake_readme_file(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // autorun.inf
    if(8 > block)
    {
        return fake_autorun_inf_file(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // favicon.ico
    if(16 > block)
    {
        return fake_favicon_ico_file(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // read outside of blocks requested
    return -1;
}

int32_t faked_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void) buffer; // TODO
    (void) offset; // TODO
    if((block > 1) && (block < 18))
    {
        // FAT Table
        // TODO user created a new file,..
    }
    else if((block > 17) && (block < 26))
    {
        // root directory
        // TODO user created a new file or directory in the root directory
    }
    else
    {
        // user want to change MBR, boot sector, or faked files
        // yeah no!
    }
    return (int32_t)bufsize;
}
