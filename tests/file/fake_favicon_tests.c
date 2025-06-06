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

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "../src/file/fake_favicon.h"
#include "unity.h"

static const unsigned char expected_favicon_32_ico[] = {
  0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x20, 0x20, 0x00, 0x00, 0x01, 0x00,
  0x20, 0x00, 0xa8, 0x10, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x28, 0x00,
  0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xef, 0x00, 0x13, 0x13, 0xff, 0x01, 0x01, 0x01, 0xff, 0x0d, 0x00, 0x00,
  0xff, 0x4a, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00, 0xff, 0xc1, 0x00, 0x00,
  0xff, 0xda, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00,
  0xff, 0xda, 0x00, 0x00, 0xff, 0xc1, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00,
  0xff, 0x4a, 0x01, 0x01, 0xff, 0x0d, 0x13, 0x13, 0xff, 0x01, 0xff, 0xff,
  0xef, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00, 0x00,
  0xff, 0x97, 0x00, 0x00, 0xff, 0xeb, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00,
  0xff, 0xeb, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00, 0xff, 0x1f, 0x00, 0x00,
  0xf8, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x01, 0x01, 0xff, 0x0c, 0x00, 0x00,
  0xff, 0x83, 0x00, 0x00, 0xff, 0xef, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00,
  0xff, 0xf4, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xef, 0x00, 0x00, 0xff, 0x83, 0x01, 0x01,
  0xff, 0x0c, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00,
  0xff, 0x1e, 0x00, 0x00, 0xff, 0xc4, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00,
  0xff, 0xd8, 0x00, 0x00, 0xfd, 0x91, 0x00, 0x00, 0xe5, 0x5c, 0x00, 0x00,
  0xcd, 0x4a, 0x00, 0x00, 0xb7, 0x3d, 0x00, 0x00, 0xba, 0x3b, 0x00, 0x00,
  0xd6, 0x43, 0x00, 0x00, 0xf7, 0x4e, 0x00, 0x00, 0xff, 0x8e, 0x00, 0x00,
  0xff, 0xd8, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xc4, 0x00, 0x00,
  0xff, 0x1e, 0x00, 0x00, 0xf8, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0xf8, 0x00, 0x00, 0x00, 0xff, 0x33, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xcc, 0x00, 0x00, 0xd9, 0x6c, 0x00, 0x00, 0x3c, 0x84, 0x00, 0x00,
  0x00, 0xd1, 0x00, 0x00, 0x00, 0xee, 0x00, 0x00, 0x00, 0xf7, 0x00, 0x00,
  0x00, 0xea, 0x00, 0x00, 0x00, 0xe4, 0x00, 0x00, 0x00, 0xc6, 0x00, 0x00,
  0x00, 0x9e, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x74, 0x22, 0x00, 0x00,
  0xff, 0x4b, 0x00, 0x00, 0xff, 0xcc, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00,
  0xff, 0x33, 0x00, 0x00, 0xf8, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0x1e, 0x00, 0x00,
  0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xf8, 0x00, 0x00, 0xff, 0x74, 0x00, 0x00, 0x7d, 0x24, 0x00, 0x00,
  0x00, 0xa0, 0x00, 0x00, 0x00, 0xd5, 0x00, 0x00, 0x00, 0xf5, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xed, 0x00, 0x00,
  0x00, 0xe8, 0x00, 0x00, 0x00, 0xcf, 0x00, 0x00, 0x00, 0xb4, 0x00, 0x00,
  0x00, 0x99, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00, 0x00, 0x18, 0x02, 0x02,
  0xff, 0x07, 0x00, 0x00, 0xff, 0x74, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00,
  0xff, 0x1e, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x01, 0x01,
  0xff, 0x0c, 0x00, 0x00, 0xff, 0xc4, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xee, 0x00, 0x00, 0xff, 0x4d, 0x15, 0x15,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00,
  0x00, 0xd3, 0x00, 0x00, 0x00, 0xf5, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xed, 0x00, 0x00, 0x00, 0xe9, 0x00, 0x00,
  0x00, 0xd0, 0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, 0x00, 0x9a, 0x00, 0x00,
  0x00, 0x7f, 0x00, 0x00, 0x00, 0x2d, 0xff, 0xff, 0xff, 0x00, 0x15, 0x15,
  0xff, 0x01, 0x00, 0x00, 0xff, 0x4d, 0x00, 0x00, 0xff, 0xee, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xc4, 0x01, 0x01,
  0xff, 0x0c, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0xff, 0x83, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00,
  0xff, 0x4d, 0x3a, 0x3a, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x34, 0x00, 0x00, 0x00, 0xa2, 0x00, 0x00, 0x00, 0xd1, 0x00, 0x00,
  0x00, 0xf5, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xed, 0x00, 0x00, 0x00, 0xea, 0x00, 0x00, 0x00, 0xd0, 0x00, 0x00,
  0x00, 0xb5, 0x00, 0x00, 0x00, 0x9b, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
  0x00, 0x2c, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x25, 0x25,
  0xff, 0x00, 0x00, 0x00, 0xff, 0x62, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x83, 0x00, 0x00,
  0xf8, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xef, 0x00, 0x00, 0x00,
  0xff, 0x1f, 0x00, 0x00, 0xff, 0xef, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0x74, 0x15, 0x15, 0xff, 0x01, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00,
  0x00, 0xa0, 0x00, 0x00, 0x00, 0xd0, 0x00, 0x00, 0x00, 0xf6, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xed, 0x00, 0x00,
  0x00, 0xea, 0x00, 0x00, 0x00, 0xd1, 0x00, 0x00, 0x00, 0xb6, 0x00, 0x00,
  0x00, 0x9b, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00,
  0xd2, 0x00, 0x01, 0x01, 0xff, 0x08, 0x00, 0x00, 0xff, 0x6d, 0x00, 0x00,
  0xff, 0xeb, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xef, 0x00, 0x00, 0xff, 0x1f, 0xff, 0xff,
  0xef, 0x00, 0x13, 0x13, 0xff, 0x01, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xcc, 0x02, 0x02,
  0xff, 0x07, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x9e, 0x00, 0x00,
  0x00, 0xcf, 0x00, 0x00, 0x00, 0xf6, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xed, 0x00, 0x00, 0x00, 0xeb, 0x00, 0x00,
  0x00, 0xd2, 0x00, 0x00, 0x00, 0xb7, 0x00, 0x00, 0x00, 0x9c, 0x00, 0x00,
  0x00, 0x81, 0x00, 0x00, 0x33, 0x2c, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x00,
  0xff, 0xcb, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0x97, 0x13, 0x13, 0xff, 0x01, 0x01, 0x01,
  0xff, 0x0d, 0x00, 0x00, 0xff, 0xeb, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xfd, 0x00, 0x00, 0xff, 0x4b, 0x00, 0x00, 0xf4, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x00, 0x00, 0x00, 0x9c, 0x00, 0x00, 0x00, 0xce, 0x00, 0x00,
  0x00, 0xf7, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xed, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0xd2, 0x00, 0x00,
  0x00, 0xb7, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x6c, 0x91, 0x00, 0x00,
  0xec, 0xb7, 0x00, 0x00, 0xff, 0xfb, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xe7, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xeb, 0x01, 0x01, 0xff, 0x0d, 0x00, 0x00, 0xff, 0x4a, 0x00, 0x00,
  0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xd8, 0x02, 0x02,
  0xff, 0x06, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00,
  0x00, 0x9d, 0x00, 0x00, 0x00, 0xd3, 0x00, 0x00, 0x00, 0xf9, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xf3, 0x00, 0x00,
  0x00, 0xf2, 0x00, 0x00, 0x00, 0xdc, 0x00, 0x00, 0x29, 0xc3, 0x00, 0x00,
  0xb9, 0xc9, 0x00, 0x00, 0xf7, 0xf6, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xf2, 0x00, 0x00, 0xff, 0x84, 0x00, 0x00, 0xff, 0x15, 0x00, 0x00,
  0xff, 0xd8, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00,
  0xff, 0x4a, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0x8f, 0x00, 0x00, 0xfe, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00,
  0x00, 0x6c, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x00, 0x00, 0xf2, 0x00, 0x00,
  0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x7a, 0xff, 0x00, 0x00, 0xe0, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xfd, 0x00, 0x00, 0xff, 0xb3, 0x00, 0x00, 0xff, 0x2a, 0x00, 0x00,
  0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x8f, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00,
  0xff, 0xc1, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0x48, 0xff, 0xff, 0xff, 0x00, 0x0a, 0x0a, 0x0a, 0x01, 0x00, 0x00,
  0x00, 0x72, 0x00, 0x00, 0x00, 0xee, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x4f, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xfb, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xe8, 0xff, 0x00, 0x00, 0x99, 0xdb, 0x00, 0x00,
  0x5a, 0x1f, 0xff, 0xff, 0xb3, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0xff, 0x48, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xc1, 0x00, 0x00, 0xff, 0xda, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0x2d, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
  0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x59, 0x59,
  0x59, 0xff, 0x76, 0x76, 0x76, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x1f, 0xff, 0x00, 0x00, 0xa6, 0xff, 0x00, 0x00, 0xf3, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xf7, 0xff, 0x00, 0x00, 0xb1, 0xff, 0x00, 0x00,
  0x34, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xa9, 0x18, 0x18,
  0x18, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0xff, 0x2d, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xda, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xf4, 0x00, 0x00, 0xff, 0x1d, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0x00, 0x28, 0x00, 0x00, 0x00, 0xf1, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xff, 0x1c, 0x1c, 0x1c, 0xff, 0xc8, 0xc8, 0xc8, 0xff, 0xf0, 0xf0,
  0xf1, 0xff, 0x59, 0x59, 0xa0, 0xff, 0x06, 0x06, 0xe5, 0xff, 0x00, 0x00,
  0xfe, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x0d, 0x0d, 0xfe, 0xff, 0x1b, 0x1b, 0xd3, 0xff, 0x00, 0x00,
  0x5d, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0xfe, 0x00, 0x00, 0x00, 0x89, 0x28, 0x28, 0x28, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0x1d, 0x00, 0x00,
  0xff, 0xf4, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00,
  0xff, 0xf4, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00,
  0xff, 0x1d, 0xff, 0xff, 0xff, 0x00, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00,
  0x00, 0x38, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x00,
  0x00, 0xff, 0x43, 0x43, 0x6c, 0xff, 0x82, 0x82, 0xf1, 0xff, 0x0e, 0x0e,
  0xfd, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x01, 0x01, 0xff, 0xff, 0x5a, 0x5a, 0xff, 0xff, 0xcf, 0xcf,
  0xff, 0xff, 0xe1, 0xe1, 0xe2, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x00, 0x00,
  0x00, 0xfe, 0x00, 0x00, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x78, 0x02, 0x02,
  0x02, 0x07, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0xff, 0x1d, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00, 0xff, 0xda, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0x2d, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x08, 0x08,
  0x00, 0x01, 0x00, 0x00, 0x73, 0x36, 0x00, 0x00, 0xc0, 0xc8, 0x02, 0x02,
  0xf4, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x0b, 0x0e, 0xf9, 0xff, 0xa7, 0xa7,
  0xf9, 0xff, 0xf5, 0xf5, 0xfe, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xf4, 0xf4,
  0xf4, 0xff, 0xcb, 0xcb, 0xcb, 0xfa, 0x10, 0x10, 0x10, 0x60, 0x00, 0x00,
  0x00, 0x17, 0x01, 0x01, 0x01, 0x0a, 0x01, 0x01, 0x01, 0x0a, 0x01, 0x01,
  0x01, 0x09, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0xff, 0x2d, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xda, 0x00, 0x00, 0xff, 0xc1, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0x48, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x08, 0x08, 0xff, 0x02, 0x00, 0x00, 0xff, 0x43, 0x00, 0x00,
  0xff, 0xcf, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x0c, 0x0e, 0xff, 0xff, 0x47, 0x4d,
  0xe6, 0xff, 0x3e, 0x53, 0x9a, 0xff, 0xd0, 0xd2, 0xd7, 0xff, 0xf6, 0xf6,
  0xf6, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xee, 0xee,
  0xee, 0xff, 0x82, 0x82, 0x82, 0x50, 0x01, 0x01, 0x01, 0x09, 0x1e, 0x1e,
  0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0x48, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xc1, 0x00, 0x00,
  0xff, 0x97, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0x8f, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00, 0x00,
  0xff, 0xa4, 0x00, 0x00, 0xff, 0xfb, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x4b, 0x30,
  0xf1, 0xff, 0x9d, 0x66, 0xae, 0xff, 0xe2, 0xd2, 0xd2, 0xff, 0xeb, 0xec,
  0xed, 0xff, 0xe3, 0xc8, 0xc4, 0xff, 0xd2, 0x9d, 0x94, 0xff, 0xee, 0xe4,
  0xe2, 0xff, 0xec, 0xec, 0xec, 0xfe, 0xce, 0xce, 0xce, 0xcc, 0x69, 0x69,
  0x69, 0x2c, 0x08, 0x08, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0xfe, 0x00, 0x00, 0x00, 0xff, 0x8f, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00, 0xff, 0x4a, 0x00, 0x00,
  0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xdb, 0x00, 0x00,
  0xff, 0x76, 0x00, 0x00, 0xff, 0xed, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xf1, 0x45, 0x45, 0xe6, 0xa9, 0xd6, 0xba, 0xc2, 0xfe, 0xc8, 0x80,
  0x71, 0xff, 0xf1, 0xe5, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xe7,
  0xe5, 0xff, 0xc7, 0x83, 0x76, 0xff, 0xcf, 0xaf, 0xa9, 0xee, 0x90, 0x90,
  0x90, 0x57, 0x00, 0x00, 0x00, 0x0a, 0x02, 0x02, 0x02, 0x05, 0x01, 0x01,
  0x01, 0x07, 0x20, 0x20, 0x20, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x02, 0x02, 0xff, 0x06, 0x00, 0x00,
  0xff, 0xd8, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00,
  0xff, 0x4a, 0x01, 0x01, 0xff, 0x0d, 0x00, 0x00, 0xff, 0xeb, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xfd, 0x00, 0x00, 0xff, 0xae, 0x00, 0x00, 0xff, 0x26, 0x00, 0x00,
  0x00, 0x11, 0xdc, 0xdb, 0xdb, 0xe8, 0xfb, 0xf9, 0xf9, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xf8,
  0xf8, 0xff, 0xb3, 0xb0, 0xb0, 0x8e, 0x07, 0x07, 0x07, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0xf4, 0x00, 0x00, 0x00, 0xff, 0x4b, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xeb, 0x01, 0x01, 0xff, 0x0d, 0x13, 0x13,
  0xff, 0x01, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xd7, 0x00, 0x00, 0xff, 0x4c, 0x04, 0x04,
  0xff, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x74,
  0x74, 0x2c, 0xc0, 0xc0, 0xc0, 0xcc, 0xfb, 0xfb, 0xfb, 0xfe, 0xf2, 0xf2,
  0xf2, 0xfe, 0xf3, 0xf3, 0xf3, 0xff, 0xdc, 0xdc, 0xdc, 0xfc, 0x89, 0x89,
  0x89, 0x68, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x02, 0x02, 0xff, 0x07, 0x00, 0x00,
  0xff, 0xcc, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0x97, 0x13, 0x13, 0xff, 0x01, 0xff, 0xff, 0xef, 0x00, 0x00, 0x00,
  0xff, 0x1f, 0x00, 0x00, 0xff, 0xef, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xf6, 0x00, 0x00, 0xff, 0x7d, 0x01, 0x01,
  0xff, 0x0c, 0x00, 0x00, 0xd7, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0x79, 0x79, 0x30, 0xbf, 0xbf,
  0xbf, 0xef, 0xe5, 0xe5, 0xe5, 0xff, 0x98, 0x98, 0x98, 0xae, 0xe1, 0xe1,
  0xe1, 0xfb, 0xbb, 0xbb, 0xbb, 0xff, 0xc3, 0xc3, 0xc3, 0xf2, 0x89, 0x89,
  0x89, 0x4b, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x15, 0x15,
  0xff, 0x01, 0x00, 0x00, 0xff, 0x74, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xef, 0x00, 0x00, 0xff, 0x1f, 0xff, 0xff,
  0xef, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00,
  0xff, 0x83, 0x25, 0x25, 0xdf, 0xff, 0x15, 0x15, 0xf4, 0xff, 0x00, 0x00,
  0xff, 0xf9, 0x00, 0x00, 0xff, 0x4d, 0x3a, 0x3a, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x1d, 0x1d, 0x1d, 0x01, 0x7b, 0x7b,
  0x7b, 0x39, 0xba, 0xba, 0xba, 0xe0, 0xd2, 0xd2, 0xd2, 0xff, 0xd9, 0xd9,
  0xd9, 0xe0, 0x4d, 0x4d, 0x4d, 0x12, 0xc1, 0xc1, 0xc1, 0xab, 0xd4, 0xd4,
  0xd4, 0xff, 0xbb, 0xbb, 0xbb, 0xff, 0xc3, 0xc3, 0xc3, 0xed, 0x86, 0x86,
  0x86, 0x3b, 0x49, 0x49, 0x49, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x3a, 0x3a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x4d, 0x00, 0x00,
  0xff, 0xf8, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0x83, 0x00, 0x00, 0xf8, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0x0c, 0x5f, 0x5f,
  0xcc, 0xc4, 0xb8, 0xb8, 0xc6, 0xff, 0x73, 0x73, 0xd0, 0xff, 0x25, 0x25,
  0xeb, 0xee, 0x00, 0x00, 0xe6, 0x4e, 0x00, 0x00, 0x06, 0x0d, 0x68, 0x68,
  0x68, 0x28, 0xa8, 0xa8, 0xa8, 0x94, 0xc0, 0xc0, 0xc0, 0xf6, 0xc2, 0xc2,
  0xc2, 0xff, 0xeb, 0xeb, 0xeb, 0xfb, 0x96, 0x96, 0x96, 0x57, 0x00, 0x00,
  0x00, 0x00, 0x52, 0x52, 0x52, 0x14, 0xcb, 0xcb, 0xcb, 0xcc, 0xca, 0xca,
  0xca, 0xff, 0xbb, 0xbb, 0xbb, 0xff, 0xc3, 0xc3, 0xc3, 0xeb, 0x88, 0x88,
  0x88, 0x42, 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0xff, 0x01, 0x00, 0x00,
  0xff, 0x4d, 0x00, 0x00, 0xff, 0xee, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xc4, 0x01, 0x01, 0xff, 0x0c, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xec, 0x1e, 0x95, 0x95,
  0xbe, 0xe0, 0xc6, 0xc6, 0xc7, 0xff, 0xbb, 0xbb, 0xbd, 0xff, 0xb8, 0xb8,
  0xbe, 0xfc, 0xbc, 0xbc, 0xbc, 0xe9, 0xc0, 0xc0, 0xc0, 0xf8, 0xbf, 0xbf,
  0xbf, 0xff, 0xbd, 0xbd, 0xbd, 0xff, 0xe3, 0xe3, 0xe3, 0xfd, 0xae, 0xae,
  0xae, 0x7e, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x65, 0x65, 0x65, 0x1e, 0xd2, 0xd2, 0xd2, 0xd5, 0xca, 0xca,
  0xca, 0xff, 0xbb, 0xbb, 0xbb, 0xff, 0xc5, 0xc5, 0xc5, 0xef, 0x86, 0x86,
  0x8d, 0x55, 0x00, 0x00, 0xfe, 0x75, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00,
  0xff, 0x1e, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x13, 0x13, 0xbb, 0x34, 0xb0, 0xb0,
  0xb9, 0xe5, 0xbe, 0xbe, 0xbe, 0xff, 0xba, 0xba, 0xba, 0xff, 0xba, 0xba,
  0xba, 0xff, 0xba, 0xba, 0xba, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xdd, 0xdd,
  0xdd, 0xf5, 0xaa, 0xaa, 0xaa, 0x7d, 0x00, 0x00, 0x00, 0x04, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x65, 0x65, 0x65, 0x1e, 0xc9, 0xc9, 0xc9, 0xce, 0xce, 0xce,
  0xce, 0xff, 0xba, 0xba, 0xba, 0xff, 0xbf, 0xbf, 0xc3, 0xfc, 0x67, 0x67,
  0xd4, 0xff, 0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xe0, 0x00, 0x00, 0xff, 0x33, 0x00, 0x00, 0xf8, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x65, 0x65, 0x7b, 0x28, 0xb1, 0xb1,
  0xb9, 0xd5, 0xc4, 0xc4, 0xc5, 0xff, 0xc8, 0xc8, 0xc9, 0xff, 0xc8, 0xc8,
  0xca, 0xff, 0xab, 0xab, 0xce, 0xff, 0x41, 0x41, 0xe1, 0xef, 0x00, 0x00,
  0xff, 0x8f, 0x00, 0x00, 0xff, 0x48, 0x00, 0x00, 0xff, 0x2d, 0x00, 0x00,
  0xff, 0x1d, 0x00, 0x00, 0xff, 0x1d, 0x00, 0x00, 0xff, 0x2d, 0x00, 0x00,
  0xff, 0x48, 0x19, 0x19, 0xf0, 0x9f, 0xac, 0xac, 0xcd, 0xfd, 0xd6, 0xd6,
  0xd6, 0xff, 0xba, 0xba, 0xba, 0xff, 0xc2, 0xc2, 0xc3, 0xff, 0x9d, 0x9d,
  0xc2, 0xff, 0x6b, 0x6b, 0xd6, 0xec, 0x1b, 0x1b, 0xc8, 0x35, 0x00, 0x00,
  0xf2, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x86, 0x0f, 0x6d, 0x6d,
  0xb7, 0x85, 0x5f, 0x5f, 0xd8, 0xef, 0x21, 0x21, 0xeb, 0xff, 0x00, 0x00,
  0xfc, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00,
  0xff, 0xf4, 0x00, 0x00, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x10, 0x10, 0xf4, 0xff, 0xa6, 0xa6, 0xce, 0xff, 0xd8, 0xd8,
  0xd8, 0xff, 0xc2, 0xc2, 0xc2, 0xff, 0xbb, 0xbb, 0xbb, 0xff, 0xc8, 0xc8,
  0xc8, 0xff, 0xbc, 0xbc, 0xbc, 0xba, 0x20, 0x20, 0x20, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00,
  0xff, 0x1f, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00, 0xff, 0xeb, 0x00, 0x00,
  0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
  0xff, 0xfe, 0x00, 0x00, 0xfb, 0xeb, 0x59, 0x59, 0xc8, 0x9b, 0xbe, 0xbe,
  0xbe, 0x9a, 0xc3, 0xc3, 0xc3, 0xa9, 0xa2, 0xa2, 0xa2, 0x79, 0x77, 0x77,
  0x77, 0x36, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xef, 0x00, 0x13, 0x13,
  0xff, 0x01, 0x01, 0x01, 0xff, 0x0d, 0x00, 0x00, 0xff, 0x4a, 0x00, 0x00,
  0xff, 0x97, 0x00, 0x00, 0xff, 0xc1, 0x00, 0x00, 0xff, 0xda, 0x00, 0x00,
  0xff, 0xf4, 0x00, 0x00, 0xff, 0xf4, 0x00, 0x00, 0xff, 0xda, 0x00, 0x00,
  0xff, 0xc1, 0x00, 0x00, 0xff, 0x97, 0x00, 0x00, 0xff, 0x4a, 0x01, 0x01,
  0xff, 0x0d, 0x13, 0x13, 0xff, 0x01, 0x07, 0x07, 0x0a, 0x00, 0x36, 0x36,
  0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
  0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0x80, 0x01, 0xff, 0xff, 0x00,
  0x00, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x1f, 0xf0, 0x00,
  0x00, 0x0f, 0xe0, 0x00, 0x00, 0x07, 0xc0, 0x80, 0x02, 0x03, 0xc1, 0x80,
  0x03, 0x83, 0x81, 0x80, 0x02, 0x01, 0x03, 0x80, 0x00, 0x00, 0x07, 0x80,
  0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x30, 0x08, 0x00,
  0x00, 0x70, 0x08, 0x00, 0x00, 0x70, 0x08, 0x00, 0x00, 0x70, 0x0c, 0x00,
  0x00, 0x70, 0x0e, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x01, 0xf0, 0x08, 0x00,
  0x01, 0xf0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x30,
  0x1f, 0xc0, 0x80, 0xf0, 0x0f, 0x81, 0xc1, 0xc0, 0x07, 0x83, 0xc0, 0x01,
  0x02, 0x03, 0xe0, 0x01, 0x80, 0x07, 0xf0, 0x03, 0xc0, 0x0f, 0xf8, 0x00,
  0x00, 0x1f, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x80,
  0x01, 0xff
};
// unsigned int favicon_32_ico_len = 4286;

void setUp(void)
{

}

void tearDown(void)
{

}

// int32_t fake_favicon_ico_file(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
void test_fake_favicon_OK(void)
{
    // Objective: correct request reads part of icon
    int32_t res;
    uint8_t buffer[512];
    memset(buffer, 0x23, 512);
    res = fake_favicon_ico_file(0, buffer, 512);
    TEST_ASSERT_EQUAL_INT32(res, 512);
    TEST_ASSERT_EQUAL_MEMORY(expected_favicon_32_ico, buffer, 512);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_fake_favicon_OK);
    return UNITY_END();
}
