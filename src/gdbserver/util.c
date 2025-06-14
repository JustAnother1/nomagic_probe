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

#include "cfg/serial_cfg.h"
#include "probe_api/debug_log.h"
#include "probe_api/hex.h"
#include "probe_api/util.h"

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
    if(0 == num_digits)
    {
        num_digits = strlen(hex);
    }
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
            debug_error("gdbs: to int: invalid hex char %d / 0x%02x / %c (%s) !", *hex, *hex, *hex, *hex);
            return 0;
        }
        res = res + digit_val;
        hex++;
    }
    return res;
}

void byte_to_hex(char* hex, uint32_t value)
{
    uint32_t i;
    hex++;
    for(i = 0; i < 2; i++)
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
        hex--;
    }
}

void int_to_hex(char* hex, uint32_t value, uint32_t num_digits)
{
    // -> little-endian
    if(0 == num_digits)
    {
        num_digits = 2;
        if(0xff < value)
        {
            num_digits = 4;
        }
        if(0xffff < value)
        {
            num_digits = 6;
        }
        if(0xffffff < value)
        {
            num_digits = 8;
        }
    }
    // the value is uint32_t so num_digits can not be more than 8
    if(num_digits > 6)
    {
        // 7 or 8 digits -> 8 digits
        byte_to_hex(hex, (value)     & 0xff);
        hex = hex + 2;
        byte_to_hex(hex, (value>>8)  & 0xff);
        hex = hex + 2;
        byte_to_hex(hex, (value>>16) & 0xff);
        hex = hex + 2;
        byte_to_hex(hex, (value>>24) & 0xff);
    }
    else if(num_digits > 4)
    {
        // 5 or 6 digits -> 6 digits
        byte_to_hex(hex, (value>>16) & 0xff);
        hex = hex + 2;
        byte_to_hex(hex, (value>>8)  & 0xff);
        hex = hex + 2;
        byte_to_hex(hex, (value)     & 0xff);
    }
    else if(num_digits > 2)
    {
        // 3 or 4 digits -> 4 digits
        byte_to_hex(hex, (value)    & 0xff);
        hex = hex + 2;
        byte_to_hex(hex, (value>>8) & 0xff);
    }
    else
    {
        // 1 or 2 digits -> 2 digits
        byte_to_hex(hex, (value)     & 0xff);
    }
}

// convert hex string as defined by gdb-server protocol to normal string.
void decode_hex_string_to_text(char * hex, uint32_t buf_length, char * buf)
{
    char c = 0;
    bool first = true;
    uint32_t pos = 0;

    if(NULL == buf)
    {
        return;
    }
    if(NULL == hex)
    {
        *buf = 0;
        return;
    }

    while(pos < buf_length-1) // -1 necessary to end string with \0
    {
        switch(*hex)
        {
        case '0': if(true == first) {                    first = false;} else {             buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '1': if(true == first) { c = c + ( 1 * 16); first = false;} else { c = c +  1; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '2': if(true == first) { c = c + ( 2 * 16); first = false;} else { c = c +  2; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '3': if(true == first) { c = c + ( 3 * 16); first = false;} else { c = c +  3; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '4': if(true == first) { c = c + ( 4 * 16); first = false;} else { c = c +  4; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '5': if(true == first) { c = c + ( 5 * 16); first = false;} else { c = c +  5; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '6': if(true == first) { c = c + ( 6 * 16); first = false;} else { c = c +  6; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '7': if(true == first) { c = c + ( 7 * 16); first = false;} else { c = c +  7; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '8': if(true == first) { c = c + ( 8 * 16); first = false;} else { c = c +  8; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case '9': if(true == first) { c = c + ( 9 * 16); first = false;} else { c = c +  9; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case 'a':
        case 'A': if(true == first) { c = c + (10 * 16); first = false;} else { c = c + 10; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case 'b':
        case 'B': if(true == first) { c = c + (11 * 16); first = false;} else { c = c + 11; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case 'c':
        case 'C': if(true == first) { c = c + (12 * 16); first = false;} else { c = c + 12; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case 'd':
        case 'D': if(true == first) { c = c + (13 * 16); first = false;} else { c = c + 13; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case 'e':
        case 'E': if(true == first) { c = c + (14 * 16); first = false;} else { c = c + 14; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case 'f':
        case 'F': if(true == first) { c = c + (15 * 16); first = false;} else { c = c + 15; buf[pos] = c; pos++;  c = 0; first = true;} break;
        case 0:
            buf[pos] = c;
            pos++;
            buf[pos] = 0;
            return;

        default:
            debug_error("gdbs: to text invalid hex char %d / 0x%02x / %c !", *hex, *hex, *hex);
            buf[pos] = 0;
            return;
        }
        hex++;
    }
    buf[pos] = 0;
}

// convert text string into hex string as defined by gdb-server protocol.
void encode_text_to_hex_string(char * text, uint32_t buf_length, char * buf)
{
    uint32_t pos = 0;

    if(NULL == buf)
    {
        return;
    }
    if(NULL == text)
    {
        *buf = 0;
        return;
    }

    while(pos < (buf_length - 2))
    {
        uint8_t val = (uint8_t)(*text);
        if(0 == val)
        {
            // end of text reached
            buf[pos] = 0;
            return;
        }
        else
        {
            byte_to_hex(&(buf[pos]), val);
            pos = pos + 2;
        }
        text++;
    }
    buf[pos] = 0;
}

// convert binary data into ASCII characters and '.' like in hex dumps.
void binary_to_ascii_dump(char * data, uint32_t length)
{
    uint32_t i;
    for(i = 0; i < length; i++)
    {
        if(   (data[i] > 126)
           || (data[i] < 32)
           || (data[i] == '\n')
           || (data[i] == '\r')
           || (data[i] == '\t') )
        {
            data[i] = '.';
        }
    }
}
