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

#ifndef FILE_FAKE_FS_H_
#define FILE_FAKE_FS_H_

#include <stdint.h>
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
#define NUM_FAKED_BLOCKS        50
#define FIRST_FREE_FAT_SECTOR   5
#endif

#ifdef FAVICON_32
/*
 ! ! ! B L O C K   S I Z E   =   5 1 2   B y t e s ! ! !

lba sector | lba start address | lba end address | Block | FAT Sector | fs sector | used for
-----------+-------------------+-----------------+-------+------------+-----------+------------------
         0 |           0x0     |       0x200     |     0 |            |     -     | Master Boot Record (MBR)
         0 |         0x200     |       0x400     |     1 |            |     -     | Boot Sector (FAT12)
         0 |         0x400     |       0x600     |     2 |            |     2     | FAT Table 1/16
         0 |         0x600     |       0x800     |     3 |            |     2     | FAT Table 2/16
         0 |         0x800     |       0xa00     |     4 |            |     2     | FAT Table 3/16
         0 |         0xa00     |       0xc00     |     5 |            |     2     | FAT Table 4/16
         0 |         0xc00     |       0xe00     |     6 |            |     2     | FAT Table 5/16
         0 |         0xe00     |      0x1000     |     7 |            |     2     | FAT Table 6/16
        1  |        0x1000     |      0x1200     |     8 |            |     2     | FAT Table 7/16
        1  |        0x1200     |      0x1400     |     9 |            |     2     | FAT Table 8/16
        1  |        0x1400     |      0x1600     |    10 |            |      3    | FAT Table 9/16
        1  |        0x1600     |      0x1800     |    11 |            |      3    | FAT Table 10/16
        1  |        0x1800     |      0x1a00     |    12 |            |      3    | FAT Table 11/16
        1  |        0x1a00     |      0x1c00     |    13 |            |      3    | FAT Table 12/16
        1  |        0x1c00     |      0x1e00     |    14 |            |      3    | FAT Table 13/16
        1  |        0x1e00     |      0x2000     |    15 |            |      3    | FAT Table 14/16
         2 |        0x2000     |      0x2200     |    16 |            |      3    | FAT Table 15/16
         2 |        0x2200     |      0x2400     |    17 |            |      3    | FAT Table 16/16
         2 |        0x2400     |      0x2600     |    18 |            |     4     | root folder 1/8
         2 |        0x2600     |      0x2800     |    19 |            |     4     | root folder 1/8
         2 |        0x2800     |      0x2a00     |    20 |            |     4     | root folder 1/8
         2 |        0x2a00     |      0x2c00     |    21 |            |     4     | root folder 1/8
         2 |        0x2c00     |      0x2e00     |    22 |            |     4     | root folder 1/8
         2 |        0x2e00     |      0x3000     |    23 |            |     4     | root folder 1/8
        3  |        0x3000     |      0x3200     |    24 |            |     4     | root folder 1/8
        3  |        0x3200     |      0x3400     |    25 |            |     4     | root folder 1/8
        3  |        0x3400     |      0x3600     |    26 |     2      |     -     | Readme.txt 1/8
        3  |        0x3600     |      0x3800     |    27 |     2      |     -     | Readme.txt 2/8
        3  |        0x3800     |      0x3a00     |    28 |     2      |     -     | Readme.txt 3/8
        3  |        0x3a00     |      0x3c00     |    29 |     2      |     -     | Readme.txt 4/8
        3  |        0x3c00     |      0x3e00     |    30 |     2      |     -     | Readme.txt 5/8
        3  |        0x3e00     |      0x4000     |    31 |     2      |     -     | Readme.txt 6/8
         4 |        0x4000     |      0x4200     |    32 |     2      |     -     | Readme.txt 7/8
         4 |        0x4200     |      0x4400     |    33 |     2      |     -     | Readme.txt 8/8
         4 |        0x4400     |      0x4600     |    34 |      3     |     -     | autorun.inf 1/8
         4 |        0x4600     |      0x4800     |    35 |      3     |     -     | autorun.inf 2/8
         4 |        0x4800     |      0x4a00     |    36 |      3     |     -     | autorun.inf 3/8
         4 |        0x4a00     |      0x4c00     |    37 |      3     |     -     | autorun.inf 4/8
         4 |        0x4c00     |      0x4e00     |    38 |      3     |     -     | autorun.inf 5/8
         4 |        0x4e00     |      0x5000     |    39 |      3     |     -     | autorun.inf 6/8
        5  |        0x5000     |      0x5200     |    40 |      3     |     -     | autorun.inf 7/8
        5  |        0x5200     |      0x5400     |    41 |      3     |     -     | autorun.inf 8/8
        5  |        0x5400     |      0x5600     |    42 |     4      |     -     | favicon.ico  1/16
        5  |        0x5600     |      0x5800     |    43 |     4      |     -     | favicon.ico  2/16
        5  |        0x5800     |      0x5a00     |    44 |     4      |     -     | favicon.ico  3/16
        5  |        0x5a00     |      0x5c00     |    45 |     4      |     -     | favicon.ico  4/16
        5  |        0x5c00     |      0x5e00     |    46 |     4      |     -     | favicon.ico  5/16
        5  |        0x5e00     |      0x6000     |    47 |     4      |     -     | favicon.ico  6/16
         6 |        0x6000     |      0x6200     |    48 |     4      |     -     | favicon.ico  7/16
         6 |        0x6200     |      0x6400     |    49 |     4      |     -     | favicon.ico  8/16
         6 |        0x6400     |      0x6600     |    50 |      5     |     -     | favicon.ico  9/16
         6 |        0x6600     |      0x6800     |    51 |      5     |     -     | favicon.ico 10/16
         6 |        0x6800     |      0x6a00     |    52 |      5     |     -     | favicon.ico 11/16
         6 |        0x6a00     |      0x6c00     |    53 |      5     |     -     | favicon.ico 12/16
         6 |        0x6c00     |      0x6e00     |    54 |      5     |     -     | favicon.ico 13/16
         6 |        0x6e00     |      0x7000     |    55 |      5     |     -     | favicon.ico 14/16
        7  |        0x7000     |      0x7200     |    56 |      5     |     -     | favicon.ico 15/16
        7  |        0x7200     |      0x7400     |    57 |      5     |     -     | favicon.ico 16/16
-------------- End of faked area - file system direct access starts here -----------------------------
        7  |        0x7400     |      0x7600     |    58 |     6      |      6    | user data
        7  |        0x7600     |      0x7800     |    59 |     6      |      6    | user data
        7  |        0x7800     |      0x7a00     |    60 |     6      |      6    | user data
        7  |        0x7a00     |      0x7c00     |    61 |     6      |      6    | user data
        7  |        0x7c00     |      0x7e00     |    62 |     6      |      6    | user data
        7  |        0x7e00     |      0x8000     |    63 |     6      |      6    | user data
         8 |        0x8000     |      0x8200     |    64 |     6      |      6    | user data
         0 |        0x8200     |      0x8400     |    65 |     6      |      6    | user data
         8 |        0x8400     |      0x8600     |    66 |      7     |     7     | user data
         8 |        0x8600     |      0x8800     |    67 |      7     |     7     | user data
         8 |        0x8800     |      0x8a00     |    68 |      7     |     7     | user data
         8 |        0x8a00     |      0x8c00     |    69 |      7     |     7     | user data
         8 |        0x8c00     |      0x8e00     |    70 |      7     |     7     | user data
         8 |        0x8e00     |      0x9000     |    71 |      7     |     7     | user data
        9  |        0x9000     |      0x9200     |    72 |      7     |     7     | user data
        9  |        0x9200     |      0x9400     |    73 |      7     |     7     | user data
        9  |        0x9400     |      0x9600     |    74 |     8      |      8    | user data
        9  |        0x9600     |      0x9800     |    75 |     8      |      8    | user data
        9  |        0x9800     |      0x9a00     |    76 |     8      |      8    | user data
        9  |        0x9a00     |      0x9c00     |    77 |     8      |      8    | user data
      ...  |          ...      |        ...      |  ...  |    ...     |    ....   | user data
*/
#define NUM_FAKED_BLOCKS        58
#define FIRST_FREE_FAT_SECTOR   6
#endif

int32_t fake_fs_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
int32_t fake_fs_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
int32_t fake_fs_read_fat_sector(const uint32_t sector, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);


#endif /* FILE_FAKE_FS_H_ */
