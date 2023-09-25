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
#ifndef HAL_BOOT_ROM_H_
#define HAL_BOOT_ROM_H_
#ifdef BOOT_ROM_ENABLED
#include <stdint.h>
#include <stddef.h>

/*
+---------+-----------------------------------------------------------------------------------------------------------+
|  CODE   | Description                                                                                               |
+---------+-----------------------------------------------------------------------------------------------------------+
| 'I','F' | void _connect_internal_flash(void)                                                                        |
|         | Restore all QSPI pad controls to their default state, and connect the SSI to the QSPI pads                |
+---------+-----------------------------------------------------------------------------------------------------------+
| 'E','X' | void _flash_exit_xip(void)                                                                                |
|         | First set up the SSI for serial-mode operations, then issue the fixed XIP exit sequence described in      |
|         | Section 2.8.1.2. Note that the bootrom code uses the IO forcing logic to drive the CS pin, which must be  |
|         | cleared before returning the SSI to XIP mode (e.g. by a call to _flash_flush_cache). This function        |
|         | configures the SSI with a fixed SCK clock divisor of /6.                                                  |
+---------+-----------------------------------------------------------------------------------------------------------+
| 'R','E' | void _flash_range_erase(uint32_t addr, size_t count, uint32_t block_size, uint8_t block_cmd)              |
|         | Erase a count bytes, starting at addr (offset from start of flash). Optionally, pass a block erase command|
|         | e.g. D8h block erase, and the size of the block erased by this command — this function will use the larger|
|         | block erase where possible, for much higher erase speed. addr must be aligned to a 4096-byte sector, and  |
|         | count must be a multiple of 4096 bytes.                                                                   |
+---------+-----------------------------------------------------------------------------------------------------------+
| 'R','P' | void flash_range_program(uint32_t addr, const uint8_t *data, size_t count)                                |
|         | Program data to a range of flash addresses starting at addr (offset from the start of flash) and count    |
|         | bytes in size. addr must be aligned to a 256-byte boundary, and count must be a multiple of 256.          |
+---------+-----------------------------------------------------------------------------------------------------------+
| 'F','C' | void _flash_flush_cache(void)                                                                             |
|         | Flush and enable the XIP cache. Also clears the IO forcing on QSPI CSn, so that the SSI can drive the     |
|         | flash chip select as normal.                                                                              |
+---------+-----------------------------------------------------------------------------------------------------------+
| 'C','X' | void _flash_enter_cmd_xip(void)                                                                           |
|         | Configure the SSI to generate a standard 03h serial read command, with 24 address bits, upon each XIP     |
|         | access. This is a very slow XIP configuration, but is very widely supported. The debugger calls this      |
|         | function after performing a flash erase/programming operation, so that the freshly-programmed code and    |
|         | data is visible to the debug host, without having to know exactly what kind of flash device is connected. |
+---------+-----------------------------------------------------------------------------------------------------------+
*/

#define ROM_FUNC_CONNECT_INTERNAL_FLASH ROM_TABLE_CODE('I', 'F')
#define ROM_FUNC_FLASH_EXIT_XIP         ROM_TABLE_CODE('E', 'X')
#define ROM_FUNC_FLASH_RANGE_ERASE      ROM_TABLE_CODE('R', 'E')
#define ROM_FUNC_FLASH_RANGE_PROGRAM    ROM_TABLE_CODE('R', 'P')
#define ROM_FUNC_FLASH_FLUSH_CACHE      ROM_TABLE_CODE('F', 'C')
#define ROM_FUNC_FLASH_ENTER_CMD_XIP    ROM_TABLE_CODE('C', 'X')

typedef void *(*_connect_internal_flash_fnptr)(void);
typedef void *(*_flash_exit_xip_fnptr)(void);
typedef void *(*_flash_range_erase_fnptr)(uint32_t addr, size_t count, uint32_t block_size, uint8_t block_cmd);
typedef void *(*flash_range_program_fnptr)(uint32_t addr, const uint8_t *data, size_t count);
typedef void *(*_flash_flush_cache_fnptr)(void);
typedef void *(*_flash_enter_cmd_xip_fnptr)(void);

typedef struct {
    _connect_internal_flash_fnptr _connect_internal_flash;
    _flash_exit_xip_fnptr _flash_exit_xip;
    _flash_range_erase_fnptr _flash_range_erase;
    flash_range_program_fnptr flash_range_program;
    _flash_flush_cache_fnptr _flash_flush_cache;
    _flash_enter_cmd_xip_fnptr _flash_enter_cmd_xip;
} boot_rom_flash_functions;

void boot_rom_check_if_valid(void);
void boot_rom_report(void);
boot_rom_flash_functions* boot_rom_get_flash_functions(void);
#endif /* BOOT_ROM_ENABLED */
#endif /* HAL_BOOT_ROM_H_ */
