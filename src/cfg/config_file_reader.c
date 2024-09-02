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

#include "config_file_reader.h"
#include "read_ini.h"
#ifdef FEAT_USB_NCM
#include "lwip.h"
#include "cfg/network_cfg.h"
#endif
#include "cfg/serial_cfg.h"
#include "cfg/swd_cfg.h"
#include "file/fake_fs.h"
#include "file/fake_root_folder.h"
#include "probe_api/debug_log.h"

#define SERIAL_SECTION_NAME  "serial"
#define NETWORK_SECTION_NAME "network"
#define SWD_SECTION_NAME     "swd"

#ifdef FEAT_USB_MSC
static uint32_t file_pos;
static uint32_t file_read_upto;
static uint32_t block_offset;
static uint8_t buf[FILE_READ_BUFFER_SIZE];
static uint16_t fat_offset;
static uint32_t file_size;

static configuration_setter get_section_handler(char * section);
static char * next_char(void);
#endif

void read_config_file(void)
{
#ifdef FEAT_USB_MSC
    fat_entry* entry;
#endif

    // all configs reset to default
    serial_cfg_reset_to_default();
    swd_cfg_reset_to_default();
#ifdef FEAT_USB_NCM
    network_cfg_reset_to_default();
#endif

#ifdef FEAT_USB_MSC
    entry = fake_root_get_entry_of_file_named(CONFIGURATION_INI_FILE_NAME);
    if(NULL != entry)
    {
        debug_line("CFG: configuration INI file found!");
        file_pos = 0;
        file_read_upto = 0;
        fat_offset = entry->first_logical_cluster;
        file_size = entry->file_size;
        read_ini_read(next_char, get_section_handler);
    }
    else
#endif
    {
        // file not found
        debug_line("CFG: no configuration INI file found!");
    }

    // apply all configurations
    serial_cfg_apply();
    swd_cfg_apply();
#ifdef FEAT_USB_NCM
    network_cfg_apply();
#endif
}

#ifdef FEAT_USB_MSC
static configuration_setter get_section_handler(char * section)
{
    if(0 == strncmp(section, SERIAL_SECTION_NAME, sizeof(SERIAL_SECTION_NAME)))
    {
        return serial_cfg_set;
    }
#ifdef FEAT_USB_NCM
    if(0 == strncmp(section, NETWORK_SECTION_NAME, sizeof(NETWORK_SECTION_NAME)))
    {
        return network_cfg_set;
    }
#endif
    if(0 == strncmp(section, SWD_SECTION_NAME, sizeof(SWD_SECTION_NAME)))
    {
        return swd_cfg_set;
    }

    return NULL; // not interested in that section
}

static char * next_char(void)
{
    char * data;
    int32_t res;
    if(file_pos >= file_size)
    {
        return 0;
    }
    if(file_pos >= file_read_upto)
    {
        // read next chunk
        uint32_t chunk_size = FILE_READ_BUFFER_SIZE;
        if(chunk_size + file_pos > file_size)
        {
            // last chunk
            chunk_size = file_size - file_pos;
        }
        block_offset = file_pos;
        res = fake_fs_read_fat_sector(fat_offset, block_offset, buf, chunk_size);
        if(0 > res)
        {
            return 0;
        }
        file_read_upto += chunk_size;
    }
    data = (char *)&buf[file_pos - block_offset];
    file_pos++;
    return data;
}
#endif

