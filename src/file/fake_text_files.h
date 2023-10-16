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

#ifndef FILE_FAKE_TEXT_FILES_H_
#define FILE_FAKE_TEXT_FILES_H_

#include <stdint.h>

#define README_CONTENTS \
"This is the configuration drive of the nomagic probe.\r\n\
For more information visit https://github.com/JustAnother1/nomagic_probe\r\n"

#define autorun_inf_CONTENTS \
"[autorun]\r\n\
icon=favicon.ico\r\n"


int32_t fake_readme_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
int32_t fake_autorun_inf_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);

#endif /* FILE_FAKE_TEXT_FILES_H_ */
