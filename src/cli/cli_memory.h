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
#ifndef CLI_CLI_MEMORY_H_
#define CLI_CLI_MEMORY_H_

#include <stdbool.h>
#include <stdint.h>

bool cmd_memory_display(const uint32_t loop);
bool cmd_memory_dump(const uint32_t loop);
bool cmd_flash_memory_erase(const uint32_t loop);
bool cmd_flash_memory_write(const uint32_t loop);
#ifdef BOOT_ROM_ENABLED
bool cmd_flash_disable_XIP(const uint32_t loop);
bool cmd_flash_enable_XIP(const uint32_t loop);
#else
bool cmd_flash_init(const uint32_t loop);
bool cmd_flash_detect(const uint32_t loop);
#endif
#ifdef FEAT_USB_MSC
bool cmd_file_dump(const uint32_t loop);
bool cmd_file_ls(const uint32_t loop);
bool cmd_file_format(const uint32_t loop);
#endif

#endif /* CLI_CLI_MEMORY_H_ */
