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
#include <stdlib.h>

#include "cli_memory.h"
#include "probe_api/cli.h"
#include "cli_cfg.h"
#include "hal/flash.h"
#include "hal/qspi.h"
#include "hal/boot_rom.h"
#include "hal/hw/TIMER.h"
#include "file/fake_fs.h"
#include "file/file_system.h"
#include "file/fake_root_folder.h"
#include "probe_api/debug_log.h"


static uint32_t addr;
static uint32_t num_loops = 0;
#ifdef FEAT_USB_MSC
static uint32_t file_size  = 0;
#endif

bool cmd_memory_display(const uint32_t loop)
{
    if(0 == loop)
    {
        // first call
        uint8_t* addr_str = cli_get_parameter(0);
        uint8_t* numBytes_str = cli_get_parameter(1);
        uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
        addr = (uint32_t)atoi((const char*)addr_str);
        num_loops = numBytes/4;
    }
    else
    {
        // max 16 MB (0x1 00 00 00)  starting at 0x 10 00 00 00
        if((addr > 0xfffffff) && (addr < 0x11000000))
        {
            // QSPI Flash
            uint32_t i;
            uint32_t line[4];
            flash_read(addr & 0xffffff, (uint8_t*)line, 16);
            for(i = 0; i < 4; i++)
            {
                debug_msg("Address 0x%08lx : 0x%08lx (%ld)\r\n", addr, line[i], line[i]);
                addr = addr + 4;
                num_loops--;
                if(0 == num_loops)
                {
                    break;
                }
            }
        }
        else
        {
            uint32_t val;
            uint32_t i;
            for(i = 0; i < 4; i++)
            {
                if(0 == num_loops)
                {
                    break;
                }
                val = *((uint32_t*)addr);
                debug_msg("Address 0x%08lx : 0x%08lx (%ld)\r\n", addr, val, val);
                addr = addr + 4;
                num_loops--;
            }
        }
        if(0 == num_loops)
        {
            return true; // we are done
        }
    }
    return false; // we need to do more
}

bool cmd_memory_dump(const uint32_t loop)
{
    uint8_t line_buffer[16];
    uint8_t* line;
    uint32_t i;

    if(0 == loop)
    {
        // first call
        uint8_t* addr_str = cli_get_parameter(0);
        uint8_t* numBytes_str = cli_get_parameter(1);
        uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
        addr = (uint32_t)atoi((const char*)addr_str);
        num_loops = numBytes;
    }
    else
    {
        if((addr > 0xfffffff) && (addr < 0x20000000))
        {
            // QSPI Flash
            flash_read(addr & 0xffffff, line_buffer, 16);
            line = line_buffer;
        }
        else
        {
            line = ((uint8_t*)addr);
        }

        debug_msg("Address 0x%08lx :", addr);
        for(i = 0; i < 16; i++)
        {
            if(0 == num_loops)
            {
                break;
            }
            debug_msg(" %02x", line[i]);
            num_loops --;
            addr++;
        }
    }

    debug_msg("\r\n");

    if(0 == num_loops)
    {
        return true; // we are done
    }
    else
    {
        return false; // we need to do more
    }
}

bool cmd_flash_memory_erase(const uint32_t loop)
{
    uint32_t diff;
    (void) loop;
    uint8_t* addr_str = cli_get_parameter(0);
    uint32_t number = (uint32_t)atoi((const char*)addr_str);
    diff = TIMER->TIMERAWL;
    flash_erase_page(number);
    diff = TIMER->TIMERAWL - diff;
    debug_line("operation took %lu µs", diff);
    return true; // we are done
}

bool cmd_flash_memory_write(const uint32_t loop)
{
    (void) loop;
    uint32_t i;
    uint32_t diff;
    uint8_t data[256];
    uint8_t* addr_str = cli_get_parameter(0);
    uint8_t* numBytes_str = cli_get_parameter(1);
    uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
    uint32_t address = (uint32_t)atoi((const char*)addr_str);

    address = address & 0xffffff;  // 16 MB max
    // limit length
    if(numBytes > 256)
    {
        numBytes = 256;
    }

    // initialize data
    for(i = 0; i < numBytes; i++)
    {
        data[i] = (uint8_t)(i & 0xff);
    }

    debug_line("writing to address: 0x%lx", address);
    debug_line("writing %lu bytes", numBytes);
    // write data
    diff = TIMER->TIMERAWL;
    flash_write_block(address, data, numBytes);
    diff = TIMER->TIMERAWL - diff;
    debug_line("operation took %lu µs", diff);
    return true; // we are done
}

#ifdef BOOT_ROM_ENABLED
bool cmd_flash_disable_XIP(const uint32_t loop)
{
    uint32_t diff;
    (void) loop;
    boot_rom_flash_functions* flash_funcs = NULL;
    diff = TIMER->TIMERAWL;
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        flash_funcs->_connect_internal_flash();
        flash_funcs->_flash_exit_xip();
        diff = TIMER->TIMERAWL - diff;
        debug_line("operation took %lu µs", diff);
    }
    return true; // we are done
}

bool cmd_flash_enable_XIP(const uint32_t loop)
{
    uint32_t diff;
    (void)loop;
    boot_rom_flash_functions* flash_funcs = NULL;
    diff = TIMER->TIMERAWL;
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        flash_funcs->_flash_flush_cache();
        flash_funcs->_flash_enter_cmd_xip();
        diff = TIMER->TIMERAWL - diff;
        debug_line("operation took %lu µs", diff);
    }
    return true; // we are done
}
#else


bool cmd_flash_init(const uint32_t loop)
{
    (void)loop;
    qspi_init();
    return true; // we are done
}

bool cmd_flash_detect(const uint32_t loop)
{
    return qspi_detect(loop);
}

#endif

#ifdef FEAT_USB_MSC

bool cmd_file_dump(const uint32_t loop)
{
    (void) loop;
    if(0 == loop)
    {
        // first call
        char* filename = (char*)cli_get_parameter(0);

        fat_entry* entry = fake_root_get_entry_of_file_named(filename);
        if(NULL == entry)
        {
            debug_line("file(%s) not found !", filename);
            num_loops = 0;
        }
        else
        {
            debug_line("The file %s  has %ld bytes. Attributes 0x%02x.", filename, entry->file_size, entry->attributes);
            debug_line("created: date 0x%04x, time 0x%04x", entry->creation_date, entry->creation_time);
            debug_line("last write: date 0x%04x, time 0x%04x", entry->last_write_date, entry->last_write_time);
            debug_line("last access date 0x%04x.", entry->last_access_date);
            debug_line("first cluster 0x%04x.", entry->first_logical_cluster);
            num_loops = entry->first_logical_cluster;
            file_size = entry->file_size;
            addr = 0;
        }
    }
    else
    {
        uint32_t i;
        uint32_t chunk_size = 256;
        uint8_t buf[256];
        char ascii_line[17] = {0};
        // TODO handle files bigger than one sector (4096 Bytes)
        int32_t res = fake_fs_read_fat_sector(num_loops, addr, buf, 256);
        if(0 > res)
        {
            debug_line("ERROR: failed to read content(%ld)", res);
            return true;
        }
        if(chunk_size + addr > file_size)
        {
            // last chunk
            chunk_size = file_size - addr;
            num_loops = 0;
        }
        for(i = 0; i < chunk_size; i++)
        {
            if((i != 0) && (i%16 == 0))
            {
                uint32_t j;
                debug_line(" %s", ascii_line);
                for(j = 0; j < 16; j++)
                {
                    ascii_line[j] = 0;
                }
            }
            debug_msg(" %02x", buf[i]);
            if((buf[i] > 31) && (buf[i] < 127))
            {
                ascii_line[i%16] = (char)buf[i];
            }
            else
            {
                ascii_line[i%16] = '.';
            }
        }
        addr = addr + chunk_size;
        // if(0 != chunk_size%16)
        {
            // we have a not completely filled hex dump line at the end
            // -> fill it up
            while(0 != chunk_size%16)
            {
                debug_msg("   ");
                chunk_size++;
            }
            debug_line(" %s", ascii_line);
        }
    }

    if(0 == num_loops)
    {
        return true; // we are done
    }
    else
    {
        return false; // we need to do more
    }
}

bool cmd_file_ls(const uint32_t loop)
{
    if(0 == loop)
    {
        num_loops = 0;
    }
    fat_entry* entry =fake_root_get_entry_of_file_idx(loop);
    if(NULL == entry)
    {
        debug_line("%ld files.", loop);
        return true; // we are done
    }
    else
    {
        if(0 == entry->name[0])
        {
            debug_line("%ld files.", num_loops);
            return true; // we are done
        }
        else
        {
            if(0 == (entry->attributes & 0x08))
            {
                if(0xe5 == entry->name[0])
                {
                    debug_line("%ld : deleted %c%c%c%c%c%c%c%c.%c%c%c", loop,
                               '_', entry->name[1], entry->name[2], entry->name[3], entry->name[4], entry->name[5], entry->name[6], entry->name[7],
                               entry->extension[0], entry->extension[1], entry->extension[2]);
                }
                else
                {
                    debug_line("%ld : %c%c%c%c%c%c%c%c.%c%c%c", loop,
                               entry->name[0], entry->name[1], entry->name[2], entry->name[3], entry->name[4], entry->name[5], entry->name[6], entry->name[7],
                               entry->extension[0], entry->extension[1], entry->extension[2]);
                }
                num_loops++;
            }
            // else this is the Volume label -> skip
            return false; // we need to do more
        }
    }
}

bool cmd_file_format(const uint32_t loop)
{
    (void) loop;
    file_system_format();
    return true; // we are done
}

#endif // FEAT_USB_MSC
