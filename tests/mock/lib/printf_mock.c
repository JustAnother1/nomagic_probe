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
#include <stddef.h>
#include <string.h>

#include "printf.h"

#define STRING_BUFFER_LENGTH  10000

static char str_buffer[STRING_BUFFER_LENGTH];
static volatile uint32_t buf_idx;
static bool putc_issue;

static void test_putc(void* p, char c)
{
    (void) p; // not used
    str_buffer[buf_idx] = c;
    buf_idx++;
    if(STRING_BUFFER_LENGTH == buf_idx)
    {
        buf_idx = 0;
        putc_issue = true;
    }
}

void init_printf_mock(void)
{
    memset(str_buffer, 0, STRING_BUFFER_LENGTH);
    putc_issue = false;
    buf_idx = 0;
    init_printf(NULL, test_putc);
}

uint32_t printf_mock_get_write_idx(void)
{
    return buf_idx;
}

char* printf_mock_get_as_String(void)
{
    str_buffer[buf_idx] = 0;
    buf_idx = 0;
    return str_buffer;
}

bool printf_mock_had_putc_issue(void)
{
    return putc_issue;
}

