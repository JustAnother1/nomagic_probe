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
#include "file/file_storage.h"
#include "file/file_system.h"
#include "hal/debug_uart.h"
#include "hal/flash.h"
#include "hal/watchdog.h"


#define FLASH_BLOCK_SIZE         256
#define FLASH_BLOCKS_PER_SECTOR  16
#define FLASH_SECTOR_SIZE        4096

// TODO dynamic size
#define FLASH_MAX_SECTORS         512

#define SECTOR_TYPE_EMPTY         0xffff
#define SECTOR_TYPE_UNKNOWN_USED  0x0fff
#define SECTOR_TYPE_SUPER_BLOCK   1
#define SECTOR_TYPE_UNAVAILABLE   0

#define NO_SECTOR                 0xffffffff

#define FS_BLOCK_SIGNATURE  "nomagic fs version 0.1"

extern uint32_t file_system_start;
static uint32_t sector_offset;
static uint32_t block_count;
static uint8_t buf[FLASH_BLOCK_SIZE];
static uint16_t sector_map[FLASH_MAX_SECTORS];
static uint32_t super_sector;

static void scan_flash(void);
static bool block_is_empty(uint8_t* block);
static void create_file_system(void);
//static uint32_t find_next_free_sector(uint32_t start_search_sector);
static void write_super_sector(uint32_t sector_number);

void file_system_init(void)
{
    flash_init();
    block_count = (uint32_t)(1024*1024*1) / file_storage_getblock_size(); // TODO 1MB for now
    sector_offset = (0x00ffffff & file_system_start) >>12;
    scan_flash();
    if(NO_SECTOR == super_sector)
    {
        // first boot after Flash erase/ Firmware update -> create file system
        create_file_system();
    }
}

uint32_t file_system_block_count(void)
{
    return block_count;
}

void file_system_report(void)
{
    uint32_t i;
    debug_line("file system starts at address 0x%08lx (sector %ld)", file_system_start, sector_offset);

    for(i = 0; i < FLASH_MAX_SECTORS; i++)
    {
        debug_line("sector %3ld : type %d", i, sector_map[i]);
    }
    debug_line("super block in sector %ld", super_sector);
}

// returns bufsize or a negative number to indicate an error
int32_t file_system_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;
    /*
    #define BLOCK_COUNT 2048
    #define DATA_FLASH_BASE_ADDRESS (0x13000000 + MAX_FIRMWARE_SIZE)
    memcpy(buffer,
           (void*)(DATA_FLASH_BASE_ADDRESS + ((block - NUM_FAKED_BLOCKS) * BLOCK_SIZE) + offset),
           (size_t)bufsize);
    */
    return (int32_t)bufsize;
}

// returns bufsize or a negative number to indicate an error
int32_t file_system_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;
    // write flash sector
    // flash_write(block - NUM_FAKED_BLOCKS, offset, buffer, bufsize);
    return (int32_t)bufsize;
}

/*

static void flash_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);

static void flash_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;
    // TODO flash_range_erase() flash_range_program() FLASH_PAGE_SIZE
}
*/

static void scan_flash(void)
{
    super_sector = NO_SECTOR;  // no super block
    uint32_t num_blocks = 0;
    uint32_t num_sectors = 0;
    uint32_t cur_address = file_system_start;
    do{
        watchdog_feed();
        flash_read(cur_address, buf, FLASH_BLOCK_SIZE);
        if(false == block_is_empty(buf))
        {
            // there is something here
            if(0 == num_blocks)
            {
                // first block in this sector
                // -> might be the FS super block
                if(0 == strncmp(FS_BLOCK_SIGNATURE, (char *)buf, strlen(FS_BLOCK_SIGNATURE)))
                {
                    super_sector = num_sectors;
                    sector_map[num_sectors] = SECTOR_TYPE_SUPER_BLOCK;
                    debug_line("FS: found super block at 0x%08lx", cur_address);
                }
                else
                {
                    debug_line("FS: found sector with unknown data at 0x%08lx", cur_address);
                    sector_map[num_sectors] = SECTOR_TYPE_UNKNOWN_USED;
                }
            }
            else
            {
                debug_line("FS: found sector with unknown data at 0x%08lx", cur_address);
                sector_map[num_sectors] = SECTOR_TYPE_UNKNOWN_USED;
            }
            // we are done with this sector
            cur_address = ((FLASH_BLOCKS_PER_SECTOR - num_blocks) * FLASH_BLOCK_SIZE) + cur_address;
            num_blocks = 0;
            num_sectors++;
        }
        else
        {
            // another empty block
            num_blocks++;
            if(FLASH_BLOCKS_PER_SECTOR == num_blocks)
            {
                // found end of sector
                num_blocks = 0;
                sector_map[num_sectors] = SECTOR_TYPE_EMPTY;
                num_sectors ++;
            }
            cur_address = cur_address + FLASH_BLOCK_SIZE;
        }
    }while(cur_address < 0x10200000); // TODO detect flash size
    for(;num_sectors < FLASH_MAX_SECTORS; num_sectors ++)
    {
        // debug_line("FS: marking sector %ld as unavailable.", num_sectors);
        sector_map[num_sectors] = SECTOR_TYPE_UNAVAILABLE;
    }
}

static bool block_is_empty(uint8_t* block)
{
    uint32_t i;
    for(i = 0; i < FLASH_BLOCK_SIZE; i++)
    {
        if(0xff != block[i])
        {
            return false;
        }
    }
    return true;
}

// static
uint32_t find_next_free_sector(uint32_t start_search_sector)
{
    uint32_t res = start_search_sector;
    for(;res < FLASH_MAX_SECTORS; res ++)
    {
        if(SECTOR_TYPE_EMPTY == sector_map[res])
        {
            return res;
        }
    }
    return NO_SECTOR;
}

static void write_super_sector(uint32_t sector_number)
{
    // keep unused bytes at 0xff
    memset(buf, 0xff, FLASH_BLOCK_SIZE);
    // signature
    memcpy(buf, FS_BLOCK_SIGNATURE, strlen(FS_BLOCK_SIGNATURE));
    flash_write_block(file_system_start + sector_number * FLASH_SECTOR_SIZE, buf, FLASH_BLOCK_SIZE);
    sector_map[sector_number] = SECTOR_TYPE_SUPER_BLOCK;
}

static void create_file_system(void)
{
    uint32_t i;
    debug_line("FS: creating new file system !");
    // erase all used sectors
    super_sector = 0;
    for(i = 0; i < FLASH_MAX_SECTORS; i ++)
    {
        if((SECTOR_TYPE_EMPTY != sector_map[i]) && (SECTOR_TYPE_UNAVAILABLE != sector_map[i]))
        {
            debug_line("FS: erasing sector %ld (%ld)", i, i + sector_offset);
            watchdog_feed();
            flash_erase_page(i + sector_offset);
            sector_map[i] = SECTOR_TYPE_EMPTY;
        }
    }
    // write super block
    write_super_sector(super_sector);
}
