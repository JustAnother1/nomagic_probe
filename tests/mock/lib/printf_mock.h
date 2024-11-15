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

#ifndef MOCK_LIB_PRINTF_MOCK_H_
#define MOCK_LIB_PRINTF_MOCK_H_

void init_printf_mock(void);
uint32_t printf_mock_get_write_idx(void);
char* printf_mock_get_as_String(void);
bool printf_mock_had_putc_issue(void);

#endif /* MOCK_LIB_PRINTF_MOCK_H_ */
