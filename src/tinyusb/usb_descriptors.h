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

#ifndef SRC_TINYUSB_USB_DESCRIPTORS_H_
#define SRC_TINYUSB_USB_DESCRIPTORS_H_

#include <stdint.h>

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid);
uint8_t const * tud_descriptor_configuration_cb(uint8_t index);
uint8_t const * tud_descriptor_device_cb(void);

#endif /* SRC_TINYUSB_USB_DESCRIPTORS_H_ */
