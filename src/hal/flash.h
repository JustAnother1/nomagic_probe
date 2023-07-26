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

#include <stdint.h>

void flash_init(void);
void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length);
void flash_erase_page(uint32_t number);
void flash_read(uint32_t start_address, uint8_t* data, uint32_t length);
void flash_report(void);


#endif /* HAL_FLASH_H_ */
