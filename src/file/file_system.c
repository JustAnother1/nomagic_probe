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
#include "file/fake_root_folder.h"
#include "hal/debug_uart.h"
#include "hal/flash.h"
#include "hal/watchdog.h"
#include "probe_api/debug_log.h"


// TODO dynamic size
#define FLASH_MAX_SECTORS         512

// TODO detect flash size
#define FILE_SYSTEM_END           0x10200000

extern uint32_t file_system_start;

union buf_type
{
    uint8_t bytes[FLASH_BLOCK_SIZE];
    uint16_t words[FLASH_BLOCK_SIZE/2];
};


static uint32_t sector_offset;
static uint32_t block_count;
static union buf_type buf;
static uint16_t sector_map[FLASH_MAX_SECTORS];
static uint32_t super_sector;
static uint32_t start_search_sector;

static uint32_t scan_flash(void);
static bool block_is_empty(const uint8_t* block);
static void create_file_system(void);
static uint32_t find_next_free_sector(void);
static void write_super_sector(const uint32_t sector_number);
static uint32_t getLocationOfSector(const uint32_t sector);
static int32_t write_block(const uint32_t location, const uint32_t block, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
static uint32_t erase_all_used_sectors(void);
static uint32_t erase_all_sectors(void);
static void read_block(const uint32_t sector, const uint32_t block);
static void open_file_system(void);
static void mark_as_used(const uint32_t sector);

void file_system_init(void)
{
    uint32_t last_sector;
    flash_init();
    block_count = (uint32_t)(1024*1024*1) / file_storage_getblock_size(); // TODO 1MB for now
    sector_offset = (0x00ffffff & file_system_start) >>12;
    last_sector = scan_flash();
    start_search_sector = 0;
    if(NO_SECTOR == super_sector)
    {
        erase_all_sectors();
        // first boot after Flash erase/ Firmware update -> create file system
        super_sector = last_sector;
        create_file_system();
    }
    else
    {
        open_file_system();
    }
}

uint32_t file_system_block_count(void)
{
    return block_count;
}

bool file_system_report(const uint32_t loop)
{
    if(0 == loop)
    {
        debug_line("file system starts at address 0x%08lx (sector %ld)", file_system_start, sector_offset);
    }
    else if(loop < (FLASH_MAX_SECTORS + 1))
    {
        uint32_t i = loop -1;
        if((i > 0) && (i %10 == 0))
        {
            debug_line("|");
        }
        switch(sector_map[i])
        {
            default:                       debug_msg("| %4d", sector_map[i]); break;
            case SECTOR_TYPE_EMPTY:        debug_msg("|empty"); break;
            case SECTOR_TYPE_UNKNOWN_USED: debug_msg("| used"); break;
            case SECTOR_TYPE_UNAVAILABLE:  debug_msg("|     "); break;
        }
    }
    else
    {
        debug_line("|");
        debug_line("super block in sector %ld", super_sector);
        return true;
    }
    return false;
}

int32_t file_system_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t bytes_to_go;
    uint32_t location;  // flash sector the data is located in
    uint32_t block; // block number in sector
    uint32_t len = 0; // number of bytes used in this read operation
    uint32_t read = 0; // number of bytes already read in previous read operation
    uint32_t sector = offset / FLASH_SECTOR_SIZE;
    uint32_t start  = offset - sector * FLASH_SECTOR_SIZE;
    block = start / FLASH_BLOCK_SIZE;
    start = start - block * FLASH_BLOCK_SIZE;

    if(1 > bufsize)
    {
        // another job well done ;-)
        return 0;
    }
    location = getLocationOfSector(sector);
    if(NO_SECTOR == location)
    {
        // sector not found in sectorMap
        // -> we never wrote to that sector
        // -> therefore it is still empty
        // debug_line("sector %ld, block %2ld, offset %ld - has never been written to !", sector, block, offset);
        memset(buffer, 0xff, bufsize);
        return (int32_t)bufsize;
    }
    // debug_line("reading %ld bytes from sector %ld, block %2ld, offset %ld.", bufsize, sector, block, offset);
    bytes_to_go = bufsize;
    do {
        read_block(location, block);
        if(bytes_to_go > FLASH_BLOCK_SIZE)
        {
            len = FLASH_BLOCK_SIZE - start;
        }
        else
        {
            len = bytes_to_go - start;
        }
        memcpy(&buffer[read], &buf.bytes[start], len);
        bytes_to_go = bytes_to_go - len;
        read = read + len;
        start = 0;
        block++;
        if(FLASH_BLOCKS_PER_SECTOR == block)
        {
            // next sector
            sector++;
            block = 0;
            location = getLocationOfSector(sector);
            if(NO_SECTOR == location)
            {
                // sector not found in sectorMap
                // -> we never wrote to that sector
                // -> therefore it is still empty
                memset(&buffer[read], 0xff, bytes_to_go);
                return (int32_t)(read + bytes_to_go);
            }
        }
    } while(0 < bytes_to_go);
    return (int32_t)read;
}

int32_t file_system_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t bytes_to_go;
    int32_t res;
    uint32_t len;
    uint32_t written = 0;
    uint32_t block; // block number in sector
    uint32_t sector = offset / FLASH_SECTOR_SIZE;
    uint32_t start =  offset - sector * FLASH_SECTOR_SIZE;
    block = start / FLASH_BLOCK_SIZE;
    start = start - block * FLASH_BLOCK_SIZE;

    if(1 > bufsize)
    {
        // another job well done ;-)
        return 0;
    }

    bytes_to_go = bufsize;
    do{
        len = FLASH_BLOCK_SIZE - start;
        if(len > bufsize)
        {
            len = bufsize;
        }
        // TODO somehow handle the situation that there not overwriteable changes in more than one block of this transaction
        res = write_block(sector, block, start, &buffer[written], len);
        if(0 > res)
        {
            return res;
        }
        bytes_to_go = bytes_to_go - len;
        written = written + len;
        start = 0;
        block++;
        if(FLASH_BLOCKS_PER_SECTOR == block)
        {
            // next sector
            sector++;
            block = 0;
        }
    }while(0 < bufsize);
    return (int32_t)written;
}

void file_system_format(void)
{
    erase_all_sectors();
    super_sector = 0;
    create_file_system();
}

static int32_t write_block(const uint32_t sector, const uint32_t block, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t num_bytes_to_copy;
    uint32_t i;
    uint32_t location;  // flash sector the data is located in
    bool changed = false; // data to be written is identical to what is already stored -> no change
    bool overwriteable = true; // data changes can be written to this already written to sector

    if(1 > bufsize)
    {
        // another job well done
        return 0;
    }
    location = getLocationOfSector(sector);
    if(NO_SECTOR == location)
    {
        // sector not found in sectorMap
        // -> we never wrote to that sector
        location = find_next_free_sector();
        if(NO_SECTOR == location)
        {
            return -1;  // disk full
        }
        else
        {
            sector_map[location] = (uint16_t)(sector & 0xffff);
            write_super_sector(super_sector);
        }
    }

    num_bytes_to_copy = bufsize;

    if(num_bytes_to_copy + offset > FLASH_BLOCK_SIZE)
    {
        num_bytes_to_copy = FLASH_BLOCK_SIZE - offset;
    }

    // read the block
    read_block(location, block);

    // write to the read buffer and
    // test if it actually changed data

    /*
    bit in | bit to be | is a   | can be      | needs new
    flash  | written   | change | overwritten | sector
    -------+-----------+--------+-------------+-----------
       0   |    0      |  no    |   yes       |   no
       0   |    1      |  yes   |   no        |   yes
       1   |    0      |  yes   |   yes       |   no
       1   |    1      |  no    |   yes       |   no
     */
    for(i = offset; i < num_bytes_to_copy; i++)
    {
        if(false == changed)
        {
            if(buffer[i] != buf.bytes[i])
            {
                changed = true;
            }
            else
            {
                continue;
            }
        }
        // else <- not an active else as the first byte that is different also needs to be tested
        if(0 != (buffer[i] & ~buf.bytes[i]))
        {
            overwriteable = false;
            break; // no need to check the rest
        }
    }

    // copy data (necessary due to offset)
    memcpy(buf.bytes, &buffer[offset], num_bytes_to_copy);

    if(true == changed)
    {
        if(true == overwriteable)
        {
            // over write able -> write data
            flash_write_block(file_system_start + location * FLASH_SECTOR_SIZE + block * FLASH_BLOCK_SIZE, buf.bytes, FLASH_BLOCK_SIZE);
        }
        else
        {
            // data changed -> find new sector
            uint32_t new_sector = find_next_free_sector();
            sector_map[location] = SECTOR_TYPE_UNKNOWN_USED;
            sector_map[new_sector] = (uint16_t)(sector & 0xffff);
            // write the changed block
            flash_write_block(file_system_start + new_sector * FLASH_SECTOR_SIZE + block * FLASH_BLOCK_SIZE, buf.bytes, FLASH_BLOCK_SIZE);
            // copy all the unchanged blocks
            for(i = 0; i < FLASH_BLOCKS_PER_SECTOR; i++)
            {
                if(i != block)
                {
                    // read block
                    read_block(location, i);
                    // write block
                    flash_write_block(file_system_start + new_sector * FLASH_SECTOR_SIZE + i * FLASH_BLOCK_SIZE, buf.bytes, FLASH_BLOCK_SIZE);
                }
                // else that block we already write with the modified content.
            }
            // mark previously used block as overwritten
            mark_as_used(location);

            write_super_sector(super_sector);
        }
    }
    else
    {
        // no change -> another job well done
    }
    return (int32_t)num_bytes_to_copy;
}

static uint32_t scan_flash(void)
{
    uint32_t last_sector = 0;
    uint32_t num_blocks = 0;
    uint32_t num_sectors = 0;
    uint32_t num_super_sectors = 0;
    super_sector = NO_SECTOR;  // no super block
    do{
        watchdog_feed();
        read_block(num_sectors, num_blocks);
        if(false == block_is_empty(buf.bytes))
        {
            // there is something here
            if(0 == num_blocks)
            {
                // first block in this sector
                // -> might be the FS super block
                if(0 == strncmp(FS_BLOCK_SIGNATURE, (char *)buf.bytes, strlen(FS_BLOCK_SIGNATURE)))
                {
                    super_sector = num_sectors;
                    num_super_sectors ++;
                    sector_map[num_sectors] = SECTOR_TYPE_SUPER_BLOCK;
                    debug_line("FS: found super block at sector %ld, block %ld", num_sectors, num_blocks);
                }
                else
                {
                    uint32_t i;
                    bool allTero = true;
                    for(i = 0; i < FLASH_BLOCK_SIZE; i++)
                    {
                        if(0 != buf.bytes[i])
                        {
                            allTero = false;
                            break;
                        }
                    }
                    if(false == allTero)
                    {
                        debug_line("FS: found sector with unknown data at sector %ld, block %ld", num_sectors, num_blocks);
                        sector_map[num_sectors] = SECTOR_TYPE_UNKNOWN_USED;
                        for(i = 0; i < 16; i++)
                        {
                            debug_msg(" %02x", buf.bytes[i]);
                        }
                        debug_msg("\r\n");
                    }
                    else
                    {
                        // sector is marked as used
                        sector_map[num_sectors] = SECTOR_TYPE_UNKNOWN_USED;
                    }

                }
            }
            else
            {
                debug_line("FS: found sector with unknown data at sector %ld, block %ld", num_sectors, num_blocks);
                sector_map[num_sectors] = SECTOR_TYPE_UNKNOWN_USED;
            }
            // we are done with this sector
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
        }
    }while((num_sectors * FLASH_SECTOR_SIZE) < (FILE_SYSTEM_END - file_system_start));
    last_sector = num_sectors -1;
    for(;num_sectors < FLASH_MAX_SECTORS; num_sectors ++)
    {
        // debug_line("FS: marking sector %ld as unavailable.", num_sectors);
        sector_map[num_sectors] = SECTOR_TYPE_UNAVAILABLE;
    }
    if(1 != num_super_sectors)
    {
        // no super sector or more than one
        // -> there is something wrong!
        super_sector = NO_SECTOR;  // no super block
    }
    return last_sector;
}

static bool block_is_empty(const uint8_t* block)
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

static uint32_t find_next_free_sector(void)
{
    uint32_t res = start_search_sector;
    erase_all_used_sectors();  // make sure that we can use all the sectors
    for(;res < FLASH_MAX_SECTORS; res ++)
    {
        if(SECTOR_TYPE_EMPTY == sector_map[res])
        {
            start_search_sector = res;
            return res;
        }
    }
    if(0 < start_search_sector)
    {
        // wrap around -> there might be a empty sector before the start
        for(res = 0; res < start_search_sector; res ++)
        {
            if(SECTOR_TYPE_EMPTY == sector_map[res])
            {
                start_search_sector = res;
                return res;
            }
        }
    }
    // we searched everywhere but found nothing
    return NO_SECTOR;
}

static void write_super_sector(const uint32_t sector_number)
{
    uint32_t offset = 0;
    uint32_t map_size = sizeof(sector_map);
    uint32_t block = 0;
    // keep unused bytes at 0xff
    memset(buf.bytes, 0xff, FLASH_BLOCK_SIZE);
    // signature
    memcpy(buf.bytes, FS_BLOCK_SIGNATURE, strlen(FS_BLOCK_SIGNATURE));
    flash_write_block(file_system_start + sector_number * FLASH_SECTOR_SIZE + block * FLASH_BLOCK_SIZE, buf.bytes, FLASH_BLOCK_SIZE);
    sector_map[sector_number] = SECTOR_TYPE_SUPER_BLOCK;
    // sectorMap
    while(offset < map_size)
    {
        uint32_t len = map_size;
        block++;
        if(FLASH_BLOCKS_PER_SECTOR == block)
        {
            // this may not happen !
            debug_line("FS: sectorMap does not fit the super block ! Check your configuration!");
            return;
        }
        if(len > FLASH_BLOCK_SIZE)
        {
            len = FLASH_BLOCK_SIZE;
        }
        flash_write_block(file_system_start + sector_number * FLASH_SECTOR_SIZE + block * FLASH_BLOCK_SIZE, (uint8_t *)&sector_map[offset/2], len);
        offset = offset + len;
    }
}

static void create_file_system(void)
{
    debug_line("FS: creating new file system !");
    // write super block
    write_super_sector(super_sector);
}

// returns the number of erased sectors
static uint32_t erase_all_used_sectors(void)
{
    uint32_t i;
    uint32_t num_erased = 0;
    for(i = 0; i < FLASH_MAX_SECTORS; i ++)
    {
        if(SECTOR_TYPE_UNKNOWN_USED == sector_map[i])
        {
            debug_line("FS: erasing sector %ld (%ld)", i, i + sector_offset);
            watchdog_feed();
            flash_erase_page(i + sector_offset);
            sector_map[i] = SECTOR_TYPE_EMPTY;
            num_erased++;
        }
    }
    return num_erased;
}

static uint32_t erase_all_sectors(void)
{
    uint32_t i;
    uint32_t num_erased = 0;
    for(i = 0; i < FLASH_MAX_SECTORS; i ++)
    {
        if(   (SECTOR_TYPE_EMPTY != sector_map[i])
           && (SECTOR_TYPE_UNAVAILABLE != sector_map[i]))
        {
            debug_line("FS: erasing sector %ld (%ld)", i, i + sector_offset);
            watchdog_feed();
            flash_erase_page(i + sector_offset);
            sector_map[i] = SECTOR_TYPE_EMPTY;
            num_erased++;
        }
    }
    return num_erased;
}

static uint32_t getLocationOfSector(const uint32_t sector)
{
    uint32_t i;
    // scan sectorMap for the sector
    for(i = 0; i < FLASH_MAX_SECTORS; i++)
    {
        if(sector == sector_map[i])
        {
            return i;
        }
    }
    return NO_SECTOR;
}

static void read_block(const uint32_t sector, const uint32_t block)
{
    uint32_t start_address = file_system_start + (sector * FLASH_SECTOR_SIZE) + (block * FLASH_BLOCK_SIZE);
    flash_read(start_address, buf.bytes, FLASH_BLOCK_SIZE);
}

static void mark_as_used(const uint32_t sector)
{
    uint8_t empty[FLASH_BLOCK_SIZE] = {0};
    flash_write_block(file_system_start + sector * FLASH_SECTOR_SIZE + 0 * FLASH_BLOCK_SIZE, empty, FLASH_BLOCK_SIZE);
}

static void open_file_system(void)
{
    /*
    * 0x0fff - empty        : this sector has all bytes at the value 0xff
    * 0x0000 - used         : this sector has some data (not all bytes are 0xff) but the file system does not know why this data is there or the data is not valid anymore.
    * 0xffff - unavailable  : this sector can not be used. This is used if the sectorMap is bigger than the available sectors in flash memory.
    * 0x0001 - super block  : this sector contains the super block.
    * 0x0002 - data         : first data sector. User put some data into the file system and expects to read it back from sector 0.
    * */
    /*
      Scan      |             read sector Map from super block is                     |
      detected  |    empty    | used        | unavailable | super block | data        |
    ------------+-------------+-------------+-------------+-------------+-------------+
    empty       | empty       | empty       | empty       | empty       | empty       |
    used        | used        | used        | used        | used        | data        |
    unavailable | unavailable | unavailable | unavailable | unavailable | unavailable |
    super block | super block | super block | super block | super block | super block |
    */

    bool changed = false;
    bool overwriteable = true;
    // read super block
    uint32_t sec_idx = 0;
    uint32_t block = 1;
    uint32_t num_erased;
    while(sec_idx < FLASH_MAX_SECTORS)
    {
        uint32_t i;
        read_block(super_sector, block);
        for(i = 0; i < FLASH_BLOCK_SIZE/2; i++)
        {
            uint16_t sec_type = buf.words[i];
            if(sec_type != sector_map[sec_idx + i])
            {
                // scan detected
                switch(sector_map[sec_idx + i])
                {
                default:
                    // fall through
                case SECTOR_TYPE_EMPTY:
                    if((SECTOR_TYPE_SUPER_BLOCK < sec_type) && (sec_type < SECTOR_TYPE_EMPTY))
                    {
                        // data
                        sector_map[sec_idx + i] = sec_type;
                    }
                    else
                    {
                        changed = true;
                        overwriteable = false;
                    }
                    break;

                case SECTOR_TYPE_UNKNOWN_USED:
                    if((SECTOR_TYPE_SUPER_BLOCK < sec_type) && (sec_type < SECTOR_TYPE_EMPTY))
                    {
                        // data
                        sector_map[sec_idx + i] = sec_type;
                        changed = true;
                    }
                    else
                    {
                        changed = true;
                    }
                    break;

                case SECTOR_TYPE_UNAVAILABLE:
                    // no change
                    break;

                case SECTOR_TYPE_SUPER_BLOCK:
                    // no change
                    break;
                }
            }
            // else OK
        }
        sec_idx = sec_idx + FLASH_BLOCK_SIZE/2;
        block++;
    }

    num_erased = erase_all_used_sectors();
    if(0 < num_erased)
    {
        changed = true;
        overwriteable = false;
    }
    if(true == changed)
    {
        // write super block
        if(true == overwriteable)
        {
            // overwrite
            write_super_sector(super_sector);
        }
        else
        {
            // relocate super block to empty sector
            uint32_t sector = find_next_free_sector();
            sector_map[super_sector] = SECTOR_TYPE_UNKNOWN_USED;
            sector_map[sector] = SECTOR_TYPE_SUPER_BLOCK;
            write_super_sector(sector);
            // overwrite old super sector
            mark_as_used(super_sector);
            super_sector = sector;
        }
    }
}
