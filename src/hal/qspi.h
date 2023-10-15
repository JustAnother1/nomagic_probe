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

// size is 16 bit -> 0..65535 fastest allowed value is 2, 1 is not valid, 0 mean no clock
// #define QSPI_BAUDRATE_DIVIDOR     2
#define QSPI_BAUDRATE_DIVIDOR     128

void qspi_init(void);
void qspi_transfere(const uint8_t *tx, uint8_t *rx, size_t count);
void qspi_transfere_no_cmd(const uint8_t *tx, uint8_t *rx, size_t count);
void qspi_reset_flash(void);


#endif /* HAL_QSPI_H_ */
