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

#include <string.h>
#include "fake_text_files.h"
#include "file_storage.h"

int32_t fake_readme_file(uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    if(BLOCK_SIZE > offset)
    {
        if(offset < sizeof(README_CONTENTS))
        {
            some = sizeof(README_CONTENTS) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &README_CONTENTS[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}

int32_t fake_autorun_inf_file(uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    uint32_t some = 0;
    if(BLOCK_SIZE > offset)
    {
        if(offset < sizeof(autorun_inf_CONTENTS))
        {
            some = sizeof(autorun_inf_CONTENTS) - offset;
            if(some > bufsize)
            {
                some = bufsize;
            }
            memcpy(buffer, &autorun_inf_CONTENTS[offset], some);
        }
        memset(&buffer[some], 0, bufsize - some);
    }
    else
    {
        // all zeros
        memset(buffer, 0, bufsize);
    }
    return (int32_t)bufsize;
}
