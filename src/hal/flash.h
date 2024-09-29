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

#ifndef HAL_FLASH_H_
#define HAL_FLASH_H_

#include <stdbool.h>
#include <stdint.h>

// using the boot ROM read/write need to be 256 Bytes in size
// reading outside of the Flash address space  gives no error, the Flash just wraps around
// So reading at 0x10000000 and at 0x10200000 gives the same result on a 2MB flash.
// The maximum flash size is 16 MB

/*
 * XIP Address alias:
 0x10... XIP access, cacheable, allocating - Normal cache operation
 0x11... XIP access, cacheable, non-allocating - Check for hit, don’t update cache on miss
 0x12... XIP access, non-cacheable, allocating - Don’t check for hit, always update cache
 0x13... XIP access, non-cacheable, non-allocating - Bypass cache completely
 0x15... Use XIP cache as SRAM bank, mirrored across entire segment
*/

void flash_init(void);
void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length);
void flash_erase_page(uint32_t number);
void flash_read(uint32_t start_address, uint8_t* data, uint32_t length);
bool flash_report(uint32_t loop);

#endif /* HAL_FLASH_H_ */
