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

#ifndef FILE_FAKED_DISK_H_
#define FILE_FAKED_DISK_H_

// #define FAVICON_16    1
#define FAVICON_32    1

#include <stdint.h>
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
int32_t faked_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
int32_t faked_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);

#endif /* FILE_FAKED_DISK_H_ */
