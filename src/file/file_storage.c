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

#include "file_storage.h"
#include "cfg/cli_cfg.h"
#include "file_system.h"
#include "fake_mbr.h"
#include "fake_boot_sector.h"
#include "fake_fat.h"
#include "fake_root_folder.h"
#include "fake_text_files.h"
#include "fake_favicon.h"

#ifdef FAVICON_16
/*

Block | FAT Sector | used for
------+------------+-----------------------------
    0 |            | Master Boot Record (MBR)
    1 |            | Boot Sector (FAT12)
    2 |            | FAT Table 1/16
    3 |            | FAT Table 2/16
    4 |            | FAT Table 3/16
    5 |            | FAT Table 4/16
    6 |            | FAT Table 5/16
    7 |            | FAT Table 6/16
    8 |            | FAT Table 7/16
    9 |            | FAT Table 8/16
   10 |            | FAT Table 9/16
   11 |            | FAT Table 10/16
   12 |            | FAT Table 11/16
   13 |            | FAT Table 12/16
   14 |            | FAT Table 13/16
   15 |            | FAT Table 14/16
   16 |            | FAT Table 15/16
   17 |            | FAT Table 16/16
   18 |            | root folder 1/8
   19 |            | root folder 1/8
   20 |            | root folder 1/8
   21 |            | root folder 1/8
   22 |            | root folder 1/8
   23 |            | root folder 1/8
   24 |            | root folder 1/8
   25 |            | root folder 1/8
   26 | 2          | Readme.txt 1/8
   27 | 2          | Readme.txt 2/8
   28 | 2          | Readme.txt 3/8
   29 | 2          | Readme.txt 4/8
   30 | 2          | Readme.txt 5/8
   31 | 2          | Readme.txt 6/8
   32 | 2          | Readme.txt 7/8
   33 | 2          | Readme.txt 8/8
   34 |  3         | autorun.inf 1/8
   35 |  3         | autorun.inf 2/8
   36 |  3         | autorun.inf 3/8
   37 |  3         | autorun.inf 4/8
   38 |  3         | autorun.inf 5/8
   39 |  3         | autorun.inf 6/8
   40 |  3         | autorun.inf 7/8
   41 |  3         | autorun.inf 8/8
   42 | 4          | favicon.ico  1/8
   43 | 4          | favicon.ico  2/8
   44 | 4          | favicon.ico  3/8
   45 | 4          | favicon.ico  4/8
   46 | 4          | favicon.ico  5/8
   47 | 4          | favicon.ico  6/8
   48 | 4          | favicon.ico  7/8
   49 | 4          | favicon.ico  8/8
*/
#define NUM_FAKED_BLOCKS  50
#endif

#ifdef FAVICON_32
/*

Block | FAT Sector | used for
------+------------+-----------------------------
    0 |            | Master Boot Record (MBR)
    1 |            | Boot Sector (FAT12)
    2 |            | FAT Table 1/16
    3 |            | FAT Table 2/16
    4 |            | FAT Table 3/16
    5 |            | FAT Table 4/16
    6 |            | FAT Table 5/16
    7 |            | FAT Table 6/16
    8 |            | FAT Table 7/16
    9 |            | FAT Table 8/16
   10 |            | FAT Table 9/16
   11 |            | FAT Table 10/16
   12 |            | FAT Table 11/16
   13 |            | FAT Table 12/16
   14 |            | FAT Table 13/16
   15 |            | FAT Table 14/16
   16 |            | FAT Table 15/16
   17 |            | FAT Table 16/16
   18 |            | root folder 1/8
   19 |            | root folder 1/8
   20 |            | root folder 1/8
   21 |            | root folder 1/8
   22 |            | root folder 1/8
   23 |            | root folder 1/8
   24 |            | root folder 1/8
   25 |            | root folder 1/8
   26 | 2          | Readme.txt 1/8
   27 | 2          | Readme.txt 2/8
   28 | 2          | Readme.txt 3/8
   29 | 2          | Readme.txt 4/8
   30 | 2          | Readme.txt 5/8
   31 | 2          | Readme.txt 6/8
   32 | 2          | Readme.txt 7/8
   33 | 2          | Readme.txt 8/8
   34 |  3         | autorun.inf 1/8
   35 |  3         | autorun.inf 2/8
   36 |  3         | autorun.inf 3/8
   37 |  3         | autorun.inf 4/8
   38 |  3         | autorun.inf 5/8
   39 |  3         | autorun.inf 6/8
   40 |  3         | autorun.inf 7/8
   41 |  3         | autorun.inf 8/8
   42 | 4          | favicon.ico  1/16
   43 | 4          | favicon.ico  2/16
   44 | 4          | favicon.ico  3/16
   45 | 4          | favicon.ico  4/16
   46 | 4          | favicon.ico  5/16
   47 | 4          | favicon.ico  6/16
   48 | 4          | favicon.ico  7/16
   49 | 4          | favicon.ico  8/16
   50 | 5          | favicon.ico  9/16
   51 | 5          | favicon.ico 10/16
   52 | 5          | favicon.ico 11/16
   53 | 5          | favicon.ico 12/16
   54 | 5          | favicon.ico 13/16
   55 | 5          | favicon.ico 14/16
   56 | 5          | favicon.ico 15/16
   57 | 5          | favicon.ico 16/16
*/
#define NUM_FAKED_BLOCKS  58
#endif

#define NUM_FAKED_BLOCKS  58

static int32_t faked_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
static int32_t faked_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);


uint32_t file_storage_get_block_count(void)
{
    return file_system_block_count();
}

uint16_t file_storage_getblock_size(void)
{
    return BLOCK_SIZE;
}

int32_t  file_storage_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    // debug_line("read: block:%ld, offset: %ld, size: %ld", block, offset, bufsize);
    while(offset >= BLOCK_SIZE)
    {
        offset = offset - BLOCK_SIZE;
        block++;
    }
    if(block >= file_system_block_count())
    {
        return -1;  // read outside of disk
    }
    if(block < NUM_FAKED_BLOCKS)
    {
        // read faked
        return faked_read(block, offset, buffer, bufsize);
    }
    else
    {
        // read from file system
        return file_system_read(block, offset, buffer, bufsize);
    }
}

int32_t  file_storage_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    if(block >= file_system_block_count())
    {
        return -1;  // write outside of disk
    }
    if(block < NUM_FAKED_BLOCKS)
    {
        return faked_write(block, offset, buffer, bufsize);
    }
    else
    {
        return file_system_write(block, offset, buffer, bufsize);
    }
}

static int32_t faked_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
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

static int32_t faked_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
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
