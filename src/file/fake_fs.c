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

#include "fake_fs.h"

#include "cfg/cli_cfg.h"
#include "file_system.h"
#include "fake_mbr.h"
#include "fake_boot_sector.h"
#include "fake_fat.h"
#include "fake_root_folder.h"
#include "fake_text_files.h"
#include "file_storage.h"
#include "fake_favicon.h"
#include "probe_api/debug_log.h"

static int32_t faked_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
static int32_t faked_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);



int32_t fake_fs_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    if(offset < (NUM_FAKED_BLOCKS * BLOCK_SIZE))
    {
        // read faked
        // debug_line("reading faked @0x%08lx(sector %ld)", offset, offset/FLASH_SECTOR_SIZE);
        return faked_read(offset, buffer, bufsize);
    }
    else
    {
        // read from file system
        // the faked area uses the file system sectors 2-4 -> first used sector is 6 (FIRST_FREE_FAT_SECTOR)
        uint32_t fs_offset = offset - (NUM_FAKED_BLOCKS * BLOCK_SIZE) + FIRST_FREE_FAT_SECTOR * FLASH_SECTOR_SIZE;
        // debug_line("reading file system @0x%08lx(sector %ld)", offset, offset/FLASH_SECTOR_SIZE);
        return file_system_read(fs_offset, buffer, bufsize);
    }
}

int32_t fake_fs_read_fat_sector(const uint32_t sector, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    // MBR + boot sector + fat + root folder - 2 sectors (sector 0 and sector 1 are not used) => 5120 Bytes
    uint32_t abs_offset = 5120 + (sector * FLASH_SECTOR_SIZE) + offset;
    return fake_fs_read(abs_offset, buffer, bufsize);
}

int32_t fake_fs_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    if(offset < (NUM_FAKED_BLOCKS * BLOCK_SIZE))
    {
        // debug_line("writing faked @0x%08lx(lba sector %ld)", offset, offset/FLASH_SECTOR_SIZE);
        return faked_write(offset, buffer, bufsize);
    }
    else
    {
        // write to file system
        int32_t res;
        // the faked area uses the file system sectors 2-4 -> first used sector is 6 (FIRST_FREE_FAT_SECTOR)
        uint32_t fs_offset = offset - (NUM_FAKED_BLOCKS * BLOCK_SIZE) + FIRST_FREE_FAT_SECTOR * FLASH_SECTOR_SIZE;
        // debug_line("writing file system @0x%08lx(lba sector %ld)", offset, offset/FLASH_SECTOR_SIZE);
        res = file_system_write(fs_offset, buffer, bufsize);
        return res;
    }
}

static int32_t faked_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t start = offset;
    uint32_t end = (offset % BLOCK_SIZE) + (uint32_t)bufsize - 1;
    if(end >= BLOCK_SIZE)
    {
        // read outside of block requested
        return -2;
    }

    // Master Boot Record (MBR)
    if(BLOCK_SIZE > start)
    {
        // MBR
        return fake_mbr(start, buffer, bufsize);
    }
    else
    {
        start = start - BLOCK_SIZE;
    }

    // boot sector
    if(BLOCK_SIZE > start)
    {
        // boot sector
        return fake_boot_sector(start, buffer, bufsize);
    }
    start = start - BLOCK_SIZE;

    // FAT
    if(16 * BLOCK_SIZE > start)
    {
        // FAT - File Allocation Table
        return fake_fat_read(start, buffer, bufsize);
    }
    else
    {
        start = start - 16 * BLOCK_SIZE;
    }

    // root folder
    if(8 * BLOCK_SIZE > start)
    {
        // root folder
        return fake_root_folder_read(start, buffer, bufsize);
    }
    else
    {
        start = start - 8 * BLOCK_SIZE;
    }

    // read me file
    if(8 * BLOCK_SIZE > start)
    {
        // read me file
        return fake_readme_file(start, buffer, bufsize);
    }
    else
    {
        start = start - 8 * BLOCK_SIZE;
    }

    // autorun.inf
    if(8 * BLOCK_SIZE > start)
    {
        return fake_autorun_inf_file(start, buffer, bufsize);
    }
    else
    {
        start = start - 8 * BLOCK_SIZE;
    }

    // favicon.ico
    if(FAVICON_BLOCKS_USED * BLOCK_SIZE > start)
    {
        return fake_favicon_ico_file(start, buffer, bufsize);
    }
    else
    {
        start = start - FAVICON_BLOCKS_USED * BLOCK_SIZE;
    }

    // read outside of faked blocks
    return -1;
}

static int32_t faked_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    if((offset >= 2*BLOCK_SIZE) && (offset < 18 * BLOCK_SIZE))
    {
        // FAT Table
        // debug_line("fake_fs: FAT write");
        return fake_fat_write(offset - (2 * BLOCK_SIZE), buffer, bufsize);
    }
    else if((offset >= 18 * BLOCK_SIZE) && (offset < 26 * BLOCK_SIZE))
    {
        // root directory
        return fake_root_folder_write(offset - (18 * BLOCK_SIZE), buffer, bufsize);
    }
    else
    {
        // user want to change MBR, boot sector, or faked files
        // -> yeah no!
        // debug_line("fake_fs: ignoring write");
        return (int32_t)bufsize;
    }
}
