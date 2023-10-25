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

#ifndef FILE_FAKE_ROOT_FOLDER_H_
#define FILE_FAKE_ROOT_FOLDER_H_

#include <stdint.h>

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

int32_t fake_root_folder_read(uint32_t offset, uint8_t* buffer, uint32_t bufsize);
int32_t fake_root_folder_write(uint32_t offset, uint8_t* buffer, uint32_t bufsize);

fat_entry* fake_root_get_entry_of_file_named(char* filename);
fat_entry* fake_root_get_entry_of_file_idx(uint32_t idx);

uint32_t fake_root_folder_get_first_sector_of(char* filename);
uint32_t fake_root_folder_get_size_of(char* filename);
char* fake_root_folder_get_filename_for(uint32_t idx);
char* fake_root_folder_get_extension_for(uint32_t idx);

#endif /* FILE_FAKE_ROOT_FOLDER_H_ */
