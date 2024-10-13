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

#ifndef NOMAGIC_PROBE_SRC_HAL_QSPI_FLASH_H_
#define NOMAGIC_PROBE_SRC_HAL_QSPI_FLASH_H_


// Status Register
// ===============

// Bit 0: Write in Progress (Read only) 1 = busy; 0 = idle
#define STATUS_REGISTER_BUSY    1
// Bit 1: write enable latch (Read only) 1 = writing is possible; 0 = read only
#define STATUS_REGISTER_WEL     2
// Bit 2: Block protect bit (non volatile; read write)
#define STATUS_REGISTER_BP0     4
// Bit 3: Block protect bit (non volatile; read write)
#define STATUS_REGISTER_BP1     8
// Bit 4: Block protect bit (non volatile; read write)
#define STATUS_REGISTER_BP2     0x10
// Bit 5: Top/Bottom protect (non volatile; read write) 0 = block protect bits work from the top(high addresses); 1 = from the bottom (low addresses)
#define STATUS_REGISTER_TB      0x20
// Bit 6: sector protect (non volatile; read write) block protect bits work on 0 = block(64kB); 1 = sector (4KB)
#define STATUS_REGISTER_SEC     0x40
// Bit 7: status Register protect
#define STATUS_REGISTER_SRP     0x80
// Bit 8 : status register lock
#define STATUS_REGISTER_SRL     0x100
// bit 9 : Quad enable 0 = SPI; 1 = QSPI ( fixed to 1 )
#define STATUS_REGISTER_QE      0x200
// bit 10: reserved
// bit 11: security register lock bit OTP 1 = write protected
#define STATUS_REGISTER_LB1     0x800
// bit 12: security register lock bit OTP 1 = write protected
#define STATUS_REGISTER_LB2     0x1000
// bit 13: security register lock bit OTP 1 = write protected
#define STATUS_REGISTER_LB3     0x2000
// bit 14: complement protect
#define STATUS_REGISTER_CMP     0x4000
// bit 15: suspend status (read only) 1 = erase suspended; 0 = not suspended
#define STATUS_REGISTER_SUS     0x8000
// bit 16: reserved
// bit 17: reserved
// bit 18: write protect selection 0 = CMP + SEC + TB + BP0 + BP1 + BP2; 1 = individual block lockouts
#define STATUS_REGISTER_WPS     0x40000
// bit 19: reserved
// bit 20: reserved
// bit 21: output drive strength 00 = 100%; 01 = 75%; 10 = 50%, 11 = 25%
#define STATUS_REGISTER_DRV2    0x200000
// bit 22: output drive strength
#define STATUS_REGISTER_DRV1    0x400000
// bit 23: reserved


// QSPI commands
// =============

#define FLASHCMD_WRITE_STATUS              0x01
#define FLASHCMD_PAGE_PROGRAM              0x02  // These are supported by almost any SPI flash
#define FLASHCMD_READ_DATA                 0x03  // These are supported by almost any SPI flash
#define FLASHCMD_WRITE_DISABLE             0x04
#define FLASHCMD_READ_STATUS               0x05  // These are supported by almost any SPI flash
#define FLASHCMD_WRITE_ENABLE              0x06  // These are supported by almost any SPI flash
#define FLASHCMD_FAST_READ                 0x0B
#define FLASHCMD_WRITE_STATUS_3            0x11
#define FLASHCMD_READ_STATUS_3             0x15
#define FLASHCMD_SECTOR_ERASE              0x20  // These are supported by almost any SPI flash
#define FLASHCMD_WRITE_STATUS_2            0x31
#define FLASHCMD_QUAD_INPUT_PAGE_PROGRAM   0x32
#define FLASHCMD_READ_STATUS_2             0x35
#define FLASHCMD_INDIVIDUAL_BLOCK_LOCK     0x36
#define FLASHCMD_INDIVIDUAL_BLOCK_UNLOCK   0x39
#define FLASHCMD_FAST_READ_DUAL_OUTPUT     0x3B  // Dual SPI
#define FLASHCMD_READ_BLOCK_LOCK           0x3D
#define FLASHCMD_PROGRAM_SECURITY          0x42
#define FLASHCMD_ERASE_SECURITY            0x44
#define FLASHCMD_READ_SECURITY             0x48
#define FLASHCMD_READ_UNIQUE_ID            0x4B
#define FLASHCMD_VOLATILE_SR_WRITE_ENABLE  0x50
#define FLASHCMD_BLOCK_ERASE_32KB          0x52
#define FLASHCMD_READ_SFDP                 0x5a  // These are supported by almost any SPI flash
#define FLASHCMD_CHIP_ERASE_A              0x60
#define FLASHCMD_ENABLE_RESET              0x66
#define FLASHCMD_FAST_READ_QUAD_OUTPUT     0x6B  // Quad SPI
#define FLASHCMD_ERASE_PROGRAM_SUSPEND     0x75
#define FLASHCMD_SET_BURST_WITH_WRAP       0x77
#define FLASHCMD_ERASE_PROGRAM_RESUME      0x7A
#define FLASHCMD_GLOBAL_BLOCK_LOCK         0x7E
#define FLASHCMD_MANUFACTURER_DEVICE_ID    0x90
#define FLASHCMD_MFTR_DEVICE_ID_DUAL_IO    0x92  // Dual SPI
#define FLASHCMD_MFTR_DEVICE_ID_QUAD_IO    0x94  // Quad SPI
#define FLASHCMD_GLOBAL_BLOCK_UNLOCK       0x98
#define FLASHCMD_RESET_DEVICE              0x99
#define FLASHCMD_READ_JEDEC_ID             0x9f  // These are supported by almost any SPI flash
#define FLASHCMD_RELEASE_POWER_DOWN_ID     0xAB
#define FLASHCMD_POWER_DOWN                0xB9
#define FLASHCMD_FAST_READ_DUAL_IO         0xBB  // Dual SPI
#define FLASHCMD_CHIP_ERASE                0xC7
#define FLASHCMD_BLOCK_ERASE_64KB          0xD8
#define FLASHCMD_FAST_READ_QUAD_IO         0xEB  // Quad SPI


#endif /* NOMAGIC_PROBE_SRC_HAL_QSPI_FLASH_H_ */
