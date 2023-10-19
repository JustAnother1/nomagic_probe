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

#include <assert.h>
#include <string.h>
#include "fake_root_folder.h"
#include "fake_favicon.h"
#include "fake_text_files.h"
#include "file/file_system.h"



typedef struct{
    char name[8];
    char extension[3];
    uint8_t attributes;
    uint16_t reserved;
    uint16_t creation_time;
    uint16_t creation_date;
    uint16_t last_access_date;
    uint16_t ignore;
    uint16_t last_write_time;
    uint16_t last_write_date;
    uint16_t first_logical_cluster; // sector
    uint32_t file_size;
} fat_entry;

_Static_assert(sizeof(fat_entry) == 32, "FAT entry size incorrect ! stuffing?");

#define NUM_ENTRIES_PER_BLOCK  8


fat_entry buf[NUM_ENTRIES_PER_BLOCK];  // 256 Bytes -> Flash Block size


// Root directory
const uint8_t root_directory[] = {
        // volume label
        'n', 'o', 'm', 'a', 'g', 'i', 'c', ' ', 'p', 'r', 'o',   // 11 chars (8+3)
        0x08, // Attribute :
        // Bit 0: write protected; //    1
        // Bit 1: hidden;          //    2
        // Bit 2: system file;     //    4
        // Bit 3: Volume-Label;    //    8
        // Bit 4: sub directory;   // 0x10
        // Bit 5: Archive;         // 0x20
        // Bit 6–7: not used
        // VFAT uses 0x0F
        0x00, // reserved
        0x00, // creation time ms (0..199
        0x00, 0x00, // creation time
        0x00, 0x00, // creation date
        0x00, 0x00, // date of last access
        0x00, 0x00, // FAT32 only
        0x00, 0x00, // time of last change (5 bit hour, 6 bit minute, 5 bit seconds
        0x00, 0x00, // date of last change (7 bit Year, 4 bit mounth, 5 bit day. Years is years since 1980. 2020 = 40, up to 2107)
        0x00, 0x00, // start cluster
        0x00, 0x00, 0x00, 0x00, // file size in byte

        'R' , 'E' , 'A' , 'D' , 'M' , 'E' , ' ' , ' ' , 'T' , 'X' , 'T' ,
        0x21,
        0x00,
        0xC6,
        0x52, 0x6D,
        0x65, 0x43,
        0x65, 0x43,
        0x00, 0x00,
        0x88, 0x6D,
        0x65, 0x43,
        0x02, 0x00,
        sizeof(README_CONTENTS)-1, 0x00, 0x00, 0x00, // readme's files size (4 Bytes)

        'a' , 'u' , 't' , 'o' , 'r' , 'u' , 'n' , ' ' , 'i' , 'n' , 'f' ,
        0x21,
        0x00,
        0xC6,
        0x52, 0x6D,
        0x65, 0x43,
        0x65, 0x43,
        0x00, 0x00,
        0x88, 0x6D,
        0x65, 0x43,
        0x03, 0x00,
        sizeof(autorun_inf_CONTENTS)-1, 0x00, 0x00, 0x00, // files size (4 Bytes)

        'f' , 'a' , 'v' , 'i' , 'c' , 'o' , 'n' , ' ' , 'i' , 'c' , 'o' ,
        0x21,
        0x00,
        0xC6,
        0x52, 0x6D,
        0x65, 0x43,
        0x65, 0x43,
        0x00, 0x00,
        0x88, 0x6D,
        0x65, 0x43,
        0x04, 0x00,
#ifdef FAVICON_16
        0x7e, 0x05, 0x00, 0x00, // files size (4 Bytes) 1406 Byte = 57e
#endif
#ifdef FAVICON_32
        0xbe, 0x10, 0x00, 0x00, // files size (4 Bytes) 4286 Byte = 10be
#endif
};

static fat_entry* get_entry_of_file(char* filename);

// data gets stored inverted in Flash as an empty FAT entry is all 0.
// This should make it possible to just overwrite the Flash memory if a new entry is created.

int32_t fake_root_folder_read(uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t i;
    uint32_t some = 0;
    int32_t res = file_system_read((FS_SECTOR_ROOT_FOLDER * FLASH_SECTOR_SIZE) + offset, buffer, bufsize);
    if(res != (int32_t)bufsize)
    {
        return -2;
    }
    if(offset < sizeof(root_directory))
    {
        // copy in the fixed bit
        some = sizeof(root_directory) - offset;
        if(some > bufsize)
        {
            some = bufsize;
        }
        memcpy(buffer, &root_directory[offset], some);
    }
    //invert everything else
    for(i = some; i < bufsize; i++)
    {
        buffer[i] = ~buffer[i];
    }
    return (int32_t)bufsize;
}

int32_t fake_root_folder_write(uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t i;
    for(i = 0; i < bufsize; i++)
    {
        buffer[i] = ~buffer[i];
    }
    return file_system_write((FS_SECTOR_ROOT_FOLDER * FLASH_SECTOR_SIZE) + offset, buffer, bufsize);
}

uint32_t fake_root_folder_get_first_sector_of(char* filename)
{
    fat_entry* file = get_entry_of_file(filename);
    if(NULL == file)
    {
        return NO_SECTOR;
    }
    else
    {
        return file->first_logical_cluster;
    }
}

uint32_t fake_root_folder_get_size_of(char* filename)
{
    fat_entry* file = get_entry_of_file(filename);
    if(NULL == file)
    {
        return 0;
    }
    else
    {
        return file->file_size;
    }
}

static fat_entry* get_entry_of_file(char* filename)
{
    // convert into name + extension
    char name[8];
    char ext[3];
    uint32_t dot_idx = 0;
    uint32_t i;
    for(i = 0; i < 8; i++)
    {
        if(filename[i] == '.')
        {
            dot_idx = i;
            break;
        }
        else if (0 == filename[i])
        {
            // file name already ended
            // -> lets fake a dot
            i = i -1;
            dot_idx = i;
            break;
        }
        else
        {
            name[i] = filename[i];
        }
    }
    // fill unused chars with space
    for(; i < 8; i++)
    {
        name[i] = 0x20; // space
    }
    // skip the dot
    dot_idx++;
    // extension
    for(i = 0; i < 3; i++)
    {
        if(0 == filename[dot_idx + i])
        {
            break;
        }
        else
        {
            ext[i] = filename[dot_idx + i];
        }
    }

    // read a block
    uint32_t offset = 0;
    while(offset < FLASH_SECTOR_SIZE)
    {
        int32_t res = fake_root_folder_read(offset, (uint8_t*)buf, sizeof(buf));
        if(res != sizeof(buf))
        {
            return NULL;
        }
        // check the entries if they match the filename
        for(i = 0; i < NUM_ENTRIES_PER_BLOCK; i++)
        {
            if(0 == buf[i].name[0])
            {
                // reached end of table
                return NULL;
            }
            else if(0 == strncmp(buf[i].name, name, 8))
            {
                // name is equal
                if(0 == strncmp(buf[i].extension, ext, 3))
                {
                    // extension is equal
                    // -> we found the file
                    return &buf[i];
                }
            }
            // else -> not the file we are looking for
        }
        offset = offset + sizeof(buf);
    }
    // file not found
    return NULL;
}
