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

#ifndef FILE_FILE_SYSTEM_H_
#define FILE_FILE_SYSTEM_H_

#include <stdint.h>
#include <stdbool.h>

/*

nomagic file system on disc format
==================================

The file system works with sectors. Each sector has a size of 4096 Bytes. That
is the same as the smallest unit that can be erased by the flash memory. All
sectors are treated equally except the "super block". The super block is a
sector that stores the file system control data. The super block can be located
in any sector of the flash memory. The super block can be found by reading the
first bytes of each sector. The super block starts with the bytes "nomagic fs
version " followed by the version number (currently "0.1"). At offset 0x100 in
the super block the sectorMap starts.The sectorMap is an array of uint16 with
one entry for each _used_ block in the flash memory. The first entry is for the
first used sector. If the flash also contains firmware or if for another reason
only part of the flash should be used then this first sector is not the first
sector of the flash. The same might be true for the last _used_sector.

The sectorMap can have these values for a sector:

  * 0x0fff - empty        : this sector has all bytes at the value 0xff
  * 0x0000 - used         : this sector has some data (not all bytes are 0xff)
                            but the file system does not know why this data is
                            there or the data is not valid anymore.
  * 0xffff - unavailable  : this sector can not be used. This is used if the
                            sectorMap is bigger than the available sectors in
                            flash memory.
  * 0x0001 - super block  : this sector contains the super block.
  * 0x0002 - FAT 1/2      : first data sector of the File Allocation Table (FAT12)
  * 0x0003 - FAT 2/2      : second data sector of the File Allocation Table (FAT12)
  * 0x0004-  root folder  : file names and sizes for files in the root folder.
  * 0x0005 - user data    : first data sector. User put some data into the file system.

The super block is not fixed to a special position as this way the flash area
could be used evenly. (wear leveling)
The file system assumes that a byte in flash can be overwritten in flash as long
a the new value has more bits at value 0 than the old value and all bits the old
value had being a 0 are still a 0. With this assumption the flash containing
0x0fff can be overwritten with the value 0x0123. And the value 0x0001 can be
overwritten with the value 0x0000. But the value 0x0fff can not overwritten to
0xf000.
On a newly created file system all sectors are empty. only the super block uses
one sector. Each new write to a new sector will take one sector from the flash
to store the data. The sectorMap will be updated. So with the first write one
sectorMap entry goes from empty(0x0fff) to the written sector Number.
If a sector get written again then the file system can either detect that an
overwriting is possible and just store the data, or if a overwrite is not
possible it will use a new sector to store the data. The old sector is then
marked as used (0x0000) and the new sector will get the sector number as entry
in the sectorMap.
 */

#define FLASH_BLOCK_SIZE         256
#define FLASH_BLOCKS_PER_SECTOR  16
#define FLASH_SECTOR_SIZE        4096

#define SECTOR_TYPE_EMPTY         0x0fff
#define SECTOR_TYPE_UNKNOWN_USED  0
#define SECTOR_TYPE_SUPER_BLOCK   1
#define SECTOR_TYPE_UNAVAILABLE   0xffff

#define NO_SECTOR                 0xffffffff

#define FS_BLOCK_SIGNATURE        "nomagic fs version 0.1"

#define FS_SECTOR_FAT            2
#define FS_SECTOR_ROOT_FOLDER    4

void file_system_init(void);
bool file_system_report(const uint32_t loop);
uint32_t file_system_block_count(void);

// returns the number of bytes read or a negative number to indicate an error
int32_t file_system_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);

// returns the number of bytes read or a negative number to indicate an error
int32_t file_system_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);

void file_system_format(void);

#endif /* FILE_FILE_SYSTEM_H_ */
