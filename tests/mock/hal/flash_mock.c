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

#include <stdint.h>
#include <stdbool.h>

void flash_init(void)
{

}

void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length)
{
    (void)start_address;
    (void)data;
    (void)length;
}

void flash_erase_page(uint32_t number)
{
    (void)number;
}

void flash_read(uint32_t start_address, uint8_t* data, uint32_t length)
{
    (void)start_address;
    (void)data;
    (void)length;
}

bool flash_report(uint32_t loop)
{
    (void)loop;
    return false;
}
