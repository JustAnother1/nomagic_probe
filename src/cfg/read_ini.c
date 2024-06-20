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

#include <stddef.h>
#include "read_ini.h"
#include "probe_api/debug_log.h"

static char setting[MAX_SETTING_LENGTH];
static char value[MAX_VALUE_LENGTH];
static configuration_setter setter_cb;
static bool found_setting;
static bool found_section;
static uint32_t word_pos;
static char * cp;

static void skip_until_end_of_line(get_next_char stream);

void read_ini_read(get_next_char stream, get_section_setter section_cb)
{
    setter_cb = NULL;
    found_setting = false;
    found_section = false;
    word_pos = 0;

    if((NULL == stream) || (NULL == section_cb))
    {
        return;
    }

    for(;;)
    {
        cp = stream();
        switch(*cp)
        {
            case 0:
                if((true == found_setting) && (0 != word_pos))
                {
                    // file ends with last letter of value
                    if(NULL == setter_cb)
                    {
                        // first setting outside of all sections ?
                        setter_cb = section_cb(NULL);
                    }
                    if(NULL != setter_cb)
                    {
                        value[word_pos] = 0;
                        // debug_line("INI: found setting %s = %s !", setting, value);
                        setter_cb(setting, value);
                    }
                    // else user not interested in this setting
                }
                // else file has ended
                return;

            case '\r':
            case '\n':
                // end of line
                if((0 != word_pos) && (true == found_setting) && (NULL != setter_cb))
                {
                    value[word_pos] = 0;
                    // debug_line("INI: found setting %s = %s !", setting, value);
                    setter_cb(setting, value);
                }
                found_setting = false;
                found_section = false;
                word_pos = 0;
                break;

            case ' ':
            case '\t':
                // white space -> skip
                if((0 != word_pos) && (true == found_setting))
                {
                    if(NULL != setter_cb)
                    {
                        value[word_pos] = 0;
                        // debug_line("INI: found setting %s = %s !", setting, value);
                        setter_cb(setting, value);
                    }
                    // else user not interested in this setting
                    skip_until_end_of_line(stream);
                }
                // else not the white space after a settings value
                if((false == found_setting) && (0 != word_pos))
                {
                    setting[word_pos] = 0;
                }
                word_pos = 0;
                break;

            case '[':
                // start of section
                found_section = true;
                break;

            case ']':
                // end of section
                if((true == found_section) && (0 < word_pos))
                {
                    setting[word_pos] = 0;
                    // debug_line("INI: found section %s !", setting);
                    setter_cb = section_cb(setting);
                }
                // else invalid section
                skip_until_end_of_line(stream);
                break;

            case '#':
            case ';':
                // comment -> skip until end of line
                skip_until_end_of_line(stream);
                break;

            case ':':
            case '=':
                if(true == found_section)
                {
                    // a section can not start with [
                    skip_until_end_of_line(stream);
                }
                else
                {
                    // this line is a setting + value pair
                    found_setting = true;
                    if(0 != word_pos)
                    {
                        setting[word_pos] = 0;
                    }
                    word_pos = 0;
                }
                break;

            default:
                // A..Z, a..z, 1..9,0
                if(true == found_setting)
                {
                    value[word_pos] = *cp;
                    word_pos++;
                    if(MAX_VALUE_LENGTH == word_pos)
                    {
                        // setting/section too long -> skip until end of line
                        skip_until_end_of_line(stream);
                    }
                }
                else
                {
                    setting[word_pos] = *cp;
                    word_pos++;
                    if(MAX_SETTING_LENGTH == word_pos)
                    {
                        // setting/section too long -> skip until end of line
                        skip_until_end_of_line(stream);
                    }
                }
                break;
        }
    }
}

bool read_ini_bool(char * val)
{
    if(NULL == val)
    {
        return false;
    }
    switch(*val)
    {
    case 'y':
    case 'Y':
    case '1':
        return true;
    }
    return false;
}

// Static functions

static void skip_until_end_of_line(get_next_char stream)
{
    for(;;)
    {
        cp =  stream();
        if(('\r' == *cp) ||('\n' == *cp))
        {
            break;
        }
    }
    found_setting = false;
    found_section = false;
    word_pos = 0;
}
