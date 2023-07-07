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
#include "faked_disk.h"
#include "file_storage.h"

// https://de.wikipedia.org/wiki/Master_Boot_Record
// https://de.wikipedia.org/wiki/File_Allocation_Table

const uint8_t mbr_partition_table[66] = {
        // partition table (4 entries)

        // first entry:
        0x00, // do not boot
        0xff, 0xff, 0xff, // CHS first sector
        0x01, // type = FAT12
        0xff, 0xff, 0xff, // CHS last sector
        0x01, 0x00, 0x00, 0x00,// LBA start
        0xff, 0x07, 0x00, 0x00, // LBA length 0x7ff = 2047

        // second entry:
        0x00, // do not boot
        0x00, 0x00, 0x00, // CHS first sector
        0x00, // type unused
        0x00, 0x00, 0x00, // CHS last sector
        0x00, 0x00, 0x00, 0x00,// LBA start
        0x00, 0x00, 0x00, 0x00, // LBA length

        // third entry:
        0x00, // do not boot
        0x00, 0x00, 0x00, // CHS first sector
        0x00, // type unused
        0x00, 0x00, 0x00, // CHS last sector
        0x00, 0x00, 0x00, 0x00,// LBA start
        0x00, 0x00, 0x00, 0x00, // LBA length

        // fourth entry:
        0x00, // do not boot
        0x00, 0x00, 0x00, // CHS first sector
        0x00, // type unused
        0x00, 0x00, 0x00, // CHS last sector
        0x00, 0x00, 0x00, 0x00,// LBA start
        0x00, 0x00, 0x00, 0x00, // LBA length

        0x55, 0xaa // signature
};

const uint8_t boot_sector[62] = {
        0xeb, 0x3c, 0x90, // skip boot sector
        0x4d, 0x53, 0x44, 0x4f, 0x53, 0x35, 0x2e, 0x30, // OEM name : MSDOS5.0
        0x00, 0x02,// 512 Bytes per block
        8, // number of blocks per sector (max 4086 sectors for FAT12! ( 1 -> max 2MB; 2 -> 4MB, 3 -> 6MB, 4 -> 8MB..  8 ->16MB)
        1, 0, // reserved sectors= only the boot sector -> 1
        1, // number of FAT -> only one FAT
        0x80, 0x00, // max number of entries in the root folder (32 Bytes per entry=16 entries per sector of 512 Bytes; 4096 Bytes -> 128 Entries = 0x80
        0xff, 0x00, // number of sectors in this partition  2047 Blocks -> 255 Sectors
        0xf8, // Media descriptor Byte - obsolete (0xf8 = hdd)
        0x10, 0x00, // blocks per FAT
        0x01, 0x00, // sectors per track
        0x01, 0x00, // number of read/write heads
        0x00, 0x00, 0x00, 0x00, // number of hidden sectors (between MBR and start of partition
        0x00, 0x00, 0x00, 0x00, // number of sectors if bigger than 65535
        0x80, // physical drive number - 0x80 is first hdd) only important for booting
        0x00, // reserved
        0x29, // extended boot signature must be 0x29
        0x15, 0x08, 0x11, 0x47, // file system id (serial number)
        'n', 'o', 'm', 'a', 'g', 'i', 'c', ' ', 'p', 'r', 'o',  // name of file system - obsolete
        0x46, 0x41, 0x54, 0x31, 0x32, 0x20, 0x20, 0x20, // FAT Version 8 chars filled up with space -> "FAT12   "
};

// FAT Table
// Sector  | content
// -       | FAT
//         | Root Directory
// 2       | Readme.txt
// 3       | autorun.inf
// 4       | favicon.ico

const uint8_t fat_table[] = {
        // free                        == 0x000
        // bad cluster                 == 0xff7
        // last cluster for file       == 0xff8..0xfff
        // cluster belonging to a file == 0x002 .. 0xff6
        0xF8, 0xFF, 0xFF, // 0 + 1 // first 2 entries must be F8FF
        0xFF, 0xFF, 0xFF, // 2 + 3
        0xff, 0x0F, // 4
};

#define README_CONTENTS \
"This is tinyusb's MassStorage Class demo.\r\n\r\n\
If you find any bugs or get any questions, feel free to file an\r\n\
issue at github.com/hathach/tinyusb"

#define autorun_inf_CONTENTS \
"[autorun]\r\n\
icon=favicon.ico\r\n"


// created using "xxd -i favicon.ico"
uint8_t favicon_ico_start[] = {
  0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, 0x10, 0x00, 0x00, 0x01, 0x00,
  0x08, 0x00, 0x68, 0x05, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x28, 0x00,
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00,
  0x52, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xbd, 0x00, 0x00, 0x00,
  0xc6, 0x00, 0x00, 0x00, 0xde, 0x00, 0x03, 0x03, 0xdb, 0x00, 0x00, 0x00,
  0xe8, 0x00, 0x00, 0x00, 0xeb, 0x00, 0x03, 0x04, 0xeb, 0x00, 0x00, 0x00,
  0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x02, 0x02, 0xff, 0x00, 0x0b, 0x06,
  0xf7, 0x00, 0x43, 0x43, 0x43, 0x00, 0x1d, 0x1d, 0xd1, 0x00, 0x27, 0x27,
  0xe9, 0x00, 0x61, 0x62, 0x62, 0x00, 0x4b, 0x4b, 0xd2, 0x00, 0x59, 0x59,
  0xd4, 0x00, 0x52, 0x52, 0xff, 0x00, 0x63, 0x63, 0xca, 0x00, 0x87, 0x82,
  0x81, 0x00, 0x84, 0x84, 0x95, 0x00, 0x83, 0x83, 0xb0, 0x00, 0x83, 0x83,
  0xb7, 0x00, 0x90, 0x90, 0x90, 0x00, 0x8d, 0x8d, 0xad, 0x00, 0x9f, 0x9f,
  0x9e, 0x00, 0x9c, 0x9c, 0xbe, 0x00, 0xb4, 0xb4, 0xa8, 0x00, 0xb3, 0xb3,
  0xb4, 0x00, 0xa9, 0xae, 0xc9, 0x00, 0xb4, 0xb4, 0xb3, 0x00, 0xb5, 0xb5,
  0xb5, 0x00, 0xbc, 0xbc, 0xbc, 0x00, 0xc1, 0xc1, 0xbf, 0x00, 0xc2, 0xc2,
  0xc2, 0x00, 0xc8, 0xc8, 0xc8, 0x00, 0xca, 0xca, 0xc4, 0x00, 0xeb, 0xc9,
  0xbf, 0x00, 0xce, 0xce, 0xc7, 0x00, 0xd6, 0xd6, 0xd6, 0x00, 0xf7, 0xe2,
  0xdd, 0x00, 0xed, 0xed, 0xed, 0x00, 0xfa, 0xf2, 0xf1, 0x00, 0xfa, 0xf9,
  0xf8, 0x00, 0xf9, 0xf9, 0xfc, 0x00, 0xfe, 0xfd, 0xfd,};


uint8_t favicon_ico_end[] = {
  0x0f,
  0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0f, 0x0e, 0x0f, 0x0b, 0x07, 0x08, 0x00, 0x0f, 0x0e, 0x0f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x0f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f,
  0x0f, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
  0x09, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x06, 0x0f, 0x0f, 0x0c, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f,
  0x00, 0x00, 0x02, 0x2a, 0x04, 0x0f, 0x0f, 0x10, 0x05, 0x00, 0x00, 0x00,
  0x0f, 0x0f, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0a, 0x0f, 0x0f, 0x18, 0x33,
  0x12, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f,
  0x11, 0x24, 0x2c, 0x32, 0x26, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x0f,
  0x0f, 0x0f, 0x0f, 0x0d, 0x2f, 0x34, 0x31, 0x1a, 0x00, 0x00, 0x00, 0x00,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x00, 0x0f, 0x00, 0x15, 0x30, 0x2e, 0x1e,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x13, 0x16, 0x0f, 0x00, 0x00,
  0x29, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00,
  0x1d, 0x23, 0x25, 0x2b, 0x22, 0x00, 0x00, 0x00, 0x28, 0x1c, 0x0f, 0x0f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x19, 0x14, 0x00, 0x0f, 0x00, 0x0f,
  0x17, 0x2d, 0x21, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0e,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x20, 0x00, 0x00, 0x00, 0xf8, 0x3f,
  0x00, 0x00, 0xe0, 0x47, 0x00, 0x00, 0xe8, 0x33, 0x00, 0x00, 0x90, 0x11,
  0x00, 0x00, 0xb8, 0xb1, 0x00, 0x00, 0x3c, 0x04, 0x00, 0x00, 0x30, 0x0e,
  0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0xb8, 0x1e, 0x00, 0x00, 0x30, 0x1c,
  0x00, 0x00, 0x80, 0x3c, 0x00, 0x00, 0x14, 0x3d, 0x00, 0x00, 0x8d, 0xbb,
  0x00, 0x00, 0xc1, 0xc3, 0x00, 0x00, 0xe2, 0x83, 0x00, 0x00, 0xf0, 0x17,
};

// unsigned int favicon_ico_len = 1406;




/*
00000000   00 00 01 00  01 00 10 10  00 00 01 00  08 00 68 05  ..............h.
00000010   00 00 16 00  00 00 28 00  00 00 10 00  00 00 20 00  ......(....... .
00000020   00 00 01 00  08 00 00 00  00 00 00 00  00 00 00 00  ................
00000030   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000040   00 00 00 00  02 00 01 01  01 00 00 00  11 00 00 00  ................
00000050   1D 00 00 00  52 00 00 00  70 00 00 00  BD 00 00 00  ....R...p.......
00000060   C6 00 00 00  DE 00 03 03  DB 00 00 00  E8 00 00 00  ................
00000070   EB 00 03 04  EB 00 00 00  FE 00 00 00  FF 00 02 02  ................
00000080   FF 00 0B 06  F7 00 43 43  43 00 1D 1D  D1 00 27 27  ......CCC.....''
00000090   E9 00 61 62  62 00 4B 4B  D2 00 59 59  D4 00 52 52  ..abb.KK..YY..RR
000000A0   FF 00 63 63  CA 00 87 82  81 00 84 84  95 00 83 83  ..cc............
000000B0   B0 00 83 83  B7 00 90 90  90 00 8D 8D  AD 00 9F 9F  ................
000000C0   9E 00 9C 9C  BE 00 B4 B4  A8 00 B3 B3  B4 00 A9 AE  ................
000000D0   C9 00 B4 B4  B3 00 B5 B5  B5 00 BC BC  BC 00 C1 C1  ................
000000E0   BF 00 C2 C2  C2 00 C8 C8  C8 00 CA CA  C4 00 EB C9  ................
000000F0   BF 00 CE CE  C7 00 D6 D6  D6 00 F7 E2  DD 00 ED ED  ................
00000100   ED 00 FA F2  F1 00 FA F9  F8 00 F9 F9  FC 00 FE FD  ................
00000110   FD 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000120   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000130   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000140   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000150   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000160   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000170   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000180   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000190   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000001A0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000001B0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000001C0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000001D0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000001E0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000001F0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................

00000200   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000210   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000220   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000230   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000240   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000250   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000260   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000270   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000280   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000290   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000002A0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000002B0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000002C0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000002D0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000002E0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000002F0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000300   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000310   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000320   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000330   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000340   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000350   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000360   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000370   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000380   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000390   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000003A0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000003B0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000003C0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000003D0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000003E0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
000003F0   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................

00000400   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000410   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000420   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000430   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  ................
00000440   00 00 00 0F  0F 0F 0F 0F  00 00 00 00  00 00 00 00  ................
00000450   00 0F 0E 0F  0B 07 08 00  0F 0E 0F 00  00 00 00 00  ................
00000460   00 0F 00 00  00 00 00 00  00 00 0F 0F  00 00 00 0F  ................
00000470   0F 00 00 00  00 00 00 00  00 00 0F 0F  0F 00 00 0F  ................
00000480   00 00 00 00  00 00 00 00  00 00 0F 0F  0F 00 0F 0F  ................
00000490   00 00 00 00  00 00 00 03  09 0F 0F 00  0F 0F 0F 0F  ................
000004A0   00 00 00 00  00 01 06 0F  0F 0C 00 00  00 0F 0F 0F  ................
000004B0   00 00 02 2A  04 0F 0F 10  05 00 00 00  0F 0F 00 0F  ...*............
000004C0   00 00 00 0A  0F 0F 18 33  12 00 00 00  00 0F 0F 0F  .......3........
000004D0   00 00 0F 0F  11 24 2C 32  26 00 00 00  0F 0F 00 0F  .....$,2&.......
000004E0   0F 0F 0F 0D  2F 34 31 1A  00 00 00 00  0F 0F 0F 0F  ..../41.........
000004F0   0E 00 0F 00  15 30 2E 1E  00 00 00 00  0F 00 00 13  .....0..........
00000500   16 0F 00 00  29 00 00 27  00 00 00 0F  00 00 00 00  ....)..'........
00000510   1D 23 25 2B  22 00 00 00  28 1C 0F 0F  00 00 00 00  .#%+"...(.......
00000520   00 1F 19 14  00 0F 00 0F  17 2D 21 1B  00 00 00 00  .........-!.....
00000530   00 00 0F 0E  0F 0F 0F 0F  0F 00 20 00  00 00 F8 3F  .......... ....?
00000540   00 00 E0 47  00 00 E8 33  00 00 90 11  00 00 B8 B1  ...G...3........
00000550   00 00 3C 04  00 00 30 0E  00 00 20 04  00 00 B8 1E  ..<...0... .....
00000560   00 00 30 1C  00 00 80 3C  00 00 14 3D  00 00 8D BB  ..0....<...=....
00000570   00 00 C1 C3  00 00 E2 83  00 00 F0 17  00 00        ..............
00000580
00000590
*/



// Root directory
const uint8_t root_directory[] = {
        // volume label
        'n', 'o', 'm', 'a', 'g', 'i', 'c', ' ', 'p', 'r', 'o',   // 11 chars (8+3)
        0x08, // Attribute :
        // Bit 0: write protected;
        // Bit 1: hidden;
        // Bit 2: system file;
        // Bit 3: Volume-Label;
        // Bit 4: sub directory;
        // Bit 5: Archive;
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
        0x7e, 0x05, 0x00, 0x00, // files size (4 Bytes) 1406 Byte = 57e
};

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
   42 | 4          | favicon.ico 1/8
   43 | 4          | favicon.ico 2/8
   44 | 4          | favicon.ico 3/8
   45 | 4          | favicon.ico 4/8
   46 | 4          | favicon.ico 5/8
   47 | 4          | favicon.ico 6/8
   48 | 4          | favicon.ico 7/8
   49 | 4          | favicon.ico 8/8

*/

static int32_t fake_mbr(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
static int32_t fake_boot_sector(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
static int32_t fake_fat(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
static int32_t fake_root_folder(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
static int32_t fake_readme_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
static int32_t fake_autorun_inf_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
static int32_t fake_favicon_ico_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);

static int32_t fake_mbr(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    uint32_t end = offset + (uint32_t)bufsize -1;
    (void) block;

    if(end < 446)
    {
        // all Zeros
        memset(buffer, 0, (size_t)bufsize);
        return (int32_t)bufsize;
    }
    if(offset < 446)
    {
        // some zeros
        some = 446 - offset; // some will be smaller than bufsize, as end is bufsize + offset
        memset(buffer, 0, some);
        offset = 446;
    }
    memcpy(&buffer[some], &mbr_partition_table[offset-446], bufsize- some);
    return (int32_t)bufsize;
}

static int32_t fake_boot_sector(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    uint32_t end = offset + (uint32_t)bufsize;
    (void) block;

    if(offset < sizeof(boot_sector))
    {
        some = sizeof(boot_sector) - offset;
        if(some > bufsize)
        {
            some = bufsize;
        }
        memcpy(buffer, &boot_sector[offset], some);
    }
    memset(&buffer[some], 0, bufsize - some);
    if(512 == end)
    {
        buffer[bufsize -1] = 0xaa;
        buffer[bufsize -2 ] = 0x55;
    }
    if(511 == end)
    {
        buffer[bufsize -1] = 0x55;
    }
    return (int32_t)bufsize;
}

static int32_t fake_fat(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    // TODO this needs to go into Flash memory
    if(0 == block)
    {
        if(offset < sizeof(fat_table))
        {
            some = sizeof(fat_table) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &fat_table[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}

static int32_t fake_root_folder(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    // TODO this probably needs to go into Flash memory
    uint32_t some = 0;
    if(0 == block)
    {
        if(offset < sizeof(root_directory))
        {
            some = sizeof(root_directory) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &root_directory[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}

static int32_t fake_readme_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    if(0 == block)
    {
        if(offset < sizeof(README_CONTENTS))
        {
            some = sizeof(README_CONTENTS) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &README_CONTENTS[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}

static int32_t fake_autorun_inf_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    if(0 == block)
    {
        if(offset < sizeof(autorun_inf_CONTENTS))
        {
            some = sizeof(autorun_inf_CONTENTS) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &autorun_inf_CONTENTS[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}

static int32_t fake_favicon_ico_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    if(0 == block)
    {
        if(offset < sizeof(favicon_ico_start))
        {
            some = sizeof(favicon_ico_start) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &favicon_ico_start[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else if(2 == block)
    {
        uint32_t end = offset + (uint32_t)bufsize -1;
        if(end < 67)
        {
            // all Zeros
            memset(buffer, 0, (size_t)bufsize);
            return (int32_t)bufsize;
        }
        if(offset < 67)
        {
            // some zeros
            some = 67 - offset; // some will be smaller than bufsize, as end is bufsize + offset
            memset(buffer, 0, some);
            offset = 67;
        }
        if(bufsize - some > sizeof(favicon_ico_end))
        {
            uint32_t len = sizeof(favicon_ico_end) - (offset - 67);
            // copy all of favicon_ico_end
            memcpy(&buffer[some], &favicon_ico_end[offset - 67], len);
            // add some zeros
            some = some + len;
            memset(&buffer[some], 0, bufsize - some);
        }
        else
        {
            memcpy(&buffer[some], &favicon_ico_end[offset-67], bufsize - some);
        }
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}

int32_t faked_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t end = offset + (uint32_t)bufsize -1;
    if(end >= BLOCK_SIZE)
    {
        // read outside of block requested
        return -2;
    }

    // MBR + boot sector
    if(0 == block)
    {
        // MBR
        return fake_mbr(block, offset, buffer, bufsize);
    }
    else if(1 == block)
    {
        // boot sector
        return fake_boot_sector(block, offset, buffer, bufsize);
    }
    block = block -2;

    // FAT
    if(16 > block)
    {
        // FAT - File Allocation Table
        return fake_fat(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -16;
    }

    // root folder
    if(8 > block)
    {
        // root folder
        return fake_root_folder(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // read me file
    if(8 > block)
    {
        // read me file
        return fake_readme_file(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // autorun.inf
    if(8 > block)
    {
        return fake_autorun_inf_file(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // favicon.ico
    if(8 > block)
    {
        return fake_favicon_ico_file(block, offset, buffer, bufsize);
    }
    else
    {
        block = block -8;
    }

    // read outside of blocks requested
    return -1;
}

int32_t faked_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void) buffer; // TODO
    (void) offset; // TODO
    if((block > 1) && (block < 18))
    {
        // FAT Table
        // TODO user created a new file,..
    }
    else if((block > 17) && (block < 26))
    {
        // root directory
        // TODO user created a new file or directory in the root directory
    }
    else
    {
        // user want to change MBR, boot sector, or faked files
        // yeah no!
    }
    return (int32_t)bufsize;
}
