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

#ifndef HAL_QSPI_H_
#define HAL_QSPI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// clock of QSPI is peripheralClock divided by QSPI_BAUDRATE_DIVIDOR
// size is 16 bit -> 0..65535 fastest allowed value is 2, 1 is not valid, 0 means no clock
// #define QSPI_BAUDRATE_DIVIDOR     2
#define QSPI_BAUDRATE_DIVIDOR     128

void qspi_init(void);
void qspi_page_program_256(uint32_t start_address, uint8_t* data);
void qspi_read(uint32_t start_address, uint8_t* data, uint32_t length);
void qspi_erase_sector(uint32_t number);
bool qspi_detect(uint32_t loop);

#endif /* HAL_QSPI_H_ */
