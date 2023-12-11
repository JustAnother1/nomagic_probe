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
#include "util.h"
#include "cfg/gdbserver_cfg.h"

uint32_t calculateChecksum(char* data, uint32_t length)
{
    uint32_t sum = 0;
    uint32_t i;
    for(i = 0; i < length; i++)
    {
        sum = sum + (uint8_t)(data[i]);  // unsigned !
    }
    sum = (sum&0xff);  // only the lowest 8 bit
    return sum;
}

uint32_t hex_to_int(char* hex, uint32_t num_digits)
{
    uint32_t res = 0;
    uint32_t i;
    uint32_t digit_val = 0;
    for(i = 0; i < num_digits; i++)
    {
        res = res*16;
        switch(*hex)
        {
        case '0': digit_val = 0; break;
        case '1': digit_val = 1; break;
        case '2': digit_val = 2; break;
        case '3': digit_val = 3; break;
        case '4': digit_val = 4; break;
        case '5': digit_val = 5; break;
        case '6': digit_val = 6; break;
        case '7': digit_val = 7; break;
        case '8': digit_val = 8; break;
        case '9': digit_val = 9; break;
        case 'a':
        case 'A': digit_val = 10; break;
        case 'b':
        case 'B': digit_val = 11; break;
        case 'c':
        case 'C': digit_val = 12; break;
        case 'd':
        case 'D': digit_val = 13; break;
        case 'e':
        case 'E': digit_val = 14; break;
        case 'f':
        case 'F': digit_val = 15; break;
        default:
            digit_val = 0;
            debug_line("gdbs: invalid hex char %d / 0x%02x !", *hex, *hex);
            break;
        }
         res = res + digit_val;
         hex++;
    }
    return res;
}

void int_to_hex(char* hex, uint32_t value, uint32_t num_digits)
{
    uint32_t i;
    for(i = 0; i < num_digits; i++)
    {
        switch(value&0xf)
        {
        case  0: *hex = '0'; break;
        case  1: *hex = '1'; break;
        case  2: *hex = '2'; break;
        case  3: *hex = '3'; break;
        case  4: *hex = '4'; break;
        case  5: *hex = '5'; break;
        case  6: *hex = '6'; break;
        case  7: *hex = '7'; break;
        case  8: *hex = '8'; break;
        case  9: *hex = '9'; break;
        case 10: *hex = 'a'; break;
        case 11: *hex = 'b'; break;
        case 12: *hex = 'c'; break;
        case 13: *hex = 'd'; break;
        case 14: *hex = 'e'; break;
        case 15: *hex = 'f'; break;
        }
        value = (value>>4);
        hex++;
    }
}


