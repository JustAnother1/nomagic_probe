/*
 * Copyright (c) 2004,2012 Kustaa Nyholm / SpareTimeLabs
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list
 * of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution.
 *
 * Neither the name of the Kustaa Nyholm or SpareTimeLabs nor the names of its
 * contributors may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

#include <stdint.h>
#include <stdio.h>
#include "printf.h"


#ifdef PRINTF_FLOAT_SUPPORT
static void f2a(double num, char * bf);
#endif
static void ui2a(uint32_t num, uint32_t base, int uc, char * bf);
static void i2a(int32_t num, char * bf);
static int a2d(char ch);
static char a2i(char ch, char** src, int base, int* nump);
static void putchw(void* putp, putcf putf, int n, char z, char* bf);
static void putcp(void* __restrict p, char c);
static void putcp_n(void* __restrict p, char c);

static putcf stdout_putf;
static void* stdout_putp;
static size_t leng_limit;


#ifdef PRINTF_FLOAT_SUPPORT
#define NUM_FAC_POST_DECIMAL_POSITIONS 10000
static void f2a(double num, char * bf)
{
    if(num < 0)
    {
        num = -num;
        *bf++ = '-';
    }
    if(num > 4294967295)
    {
        // to big for Uint32 -> TODO 1,234*10^56
        // for now: Overflow -> OVF
        *bf++ = 'O';
        *bf++ = 'V';
        *bf++ = 'F';
    }
    else
    {
        uint32_t value = (uint32_t)num;
        uint_fast16_t fraction = (uint_fast16_t)((num - (double)value) * NUM_FAC_POST_DECIMAL_POSITIONS);
        uint32_t d = 1;
        int n = 0;

        // find amount of characters needed to present the number
        while (value/d >= 10)
        {
            d *= 10;
        }
        // add digits before decimal point
        while (d!=0)
        {
            // dgt = digit ( 0..9)
            int dgt = value / d;
            value %= d;
            d /= 10;
            // N is zero in first iteration to avoid accidental leading 0
            if(n || (dgt > 0) || (d == 0))
            {
                *bf++ = dgt + '0';
                ++n;
            }
        }
        // decimal point and fraction
        if(0 < fraction)
        {
            *bf++ = '.';
            d = NUM_FAC_POST_DECIMAL_POSITIONS/10;
            while(fraction > 0)
            {
                int dgt = fraction / d;
                fraction %= d;
                d /= 10;
                *bf++ = dgt + '0';
            }
        }
        // end of string marking
        *bf = 0;
    }
}
#endif


extern void div_and_mod(uint32_t divident, uint32_t divisor, uint32_t* quotient, uint32_t* remainder);


static void ui2a(uint32_t num, // number to convert
                 uint32_t base,  // base of number (decimal=10; hexadecimal=16,..)
                 int uc, // upper case -> true(1) -> A..F in hex; false(0) -> a..f in hex
                 char * bf)  // output for string
{
    int n = 0;
    uint32_t d = 1;  // ten to the number of digits needed to present the number '5' -> 1; '123' -> 100
    // find number of characters needed to present the number
    while (num/d >= base)
    {
        d = d * base;
    }
    while (d!=0)
    {
        // unsigned int digit = num / d;  // current digit
        // num = num % d; // prepare for next digit
        uint32_t digit;
        div_and_mod(num, d, &digit, &num);
        d = d / base;  // prepare for next digit
        if(n || (digit > 0) || (d == 0))
        {
            // *bf++ = (char)(digit + (unsigned int)( digit < 10 ? '0' : (uc ? 'A' : 'a') - 10));
            if(digit < 10)
            {
                *bf = (char)(digit + '0');
            }
            else
            {
                if(0 == uc)
                {
                    *bf = (char)(digit + 'a' -10);
                }
                else
                {
                    *bf = (char)(digit + 'A' -10);
                }
            }
            bf++;
            n++;
        }
    }
    // end of string marking
    *bf = 0;
}

static void i2a(int32_t num, char * bf)
{
    if (num<0)
    {
        num = -num;
        *bf++ = '-';
    }
    ui2a((uint32_t)num, 10, 0, bf);
}

static int a2d(char ch)
{
    if((ch >= '0') && (ch <= '9'))
    {
        return ch - '0';
    }
    else if((ch >='a') && (ch <='f'))
    {
        return ch - 'a' + 10;
    }
    else if((ch >='A') && (ch <= 'F'))
    {
        return ch - 'A' + 10;
    }
    else return -1;
}

static char a2i(char ch, char** src, int base, int* nump)
{
    char* p = *src;
    int num = 0;
    int digit;
    while((digit = a2d(ch)) >= 0)
    {
        if (digit>base)
        {
            break;
        }
        num = num * base + digit;
        ch = *p++;
    }
    *src = p;
    *nump = num;
    return ch;
}

static void putchw(void* putp,
                   putcf putf,
                   int n,  // number of characters to expand string to
                   char z, // leading zero 1-> leading Zeros, 0 -> no leading zeros
                   char* bf) // buffer containing the number as string
{
    char fc = z ? '0' : ' ';
    char ch;
    char* p = bf;
    // move to end of number
    while((*p++) && (n > 0))
    {
        n--;
    }
    // expand string to requested length
    while(n-- > 0)
    {
        putf(putp, fc);
    }
    // print everything in the buffer
    while((ch = *bf++))  // :-(
    {
        putf(putp, ch);
    }
}

int format(void* __restrict putp, putcf putf, const char* cfmt, va_list va)
{
    char bf[12];
    char ch;
    char* fmt;
    int length = 0;
    fmt = (char *)cfmt;

    // if the debug output function is not available...
    if(NULL == putf)
    {
        // ...then there is nothing we can do.
        return -1;
    }

    while((length < MAX_STRING_LENGTH) && (ch = *(fmt++)) )
    {
        length++;
        if(ch!='%')
        {
            putf(putp,ch);
        }
        else
        {

            // lz = leading Zeros -> 0 = no leading zeros; 1= leading Zeros
            char lz = 0;
            // w = width -> number of characters used to print the number

            // %03d with number 23 -> lz=1, w=3 ->   "023"
            // %3d  with number 23 -> lz=0, w=3 ->   " 23"
            // %5d  with number 23 -> lz=0, w=5 -> "   23"
            // %05d with number 23 -> lz=1, w=5 -> "00023"
            int w = 0;
            ch = *(fmt++);
            if(ch == '0')
            {
                ch = *(fmt++);
                lz = 1;
            }
            if((ch >= '0') && (ch <= '9'))
            {
                ch = a2i(ch, &fmt, 10, &w);
            }
            if(ch == 'l')
            {
                ch = *(fmt++);
            }
            switch (ch)
            {
            case 0:
                return length;

            case 'c' :
                putf(putp, (char)(va_arg(va, int)));
                break;

            case 'd' :
            {
                i2a(va_arg(va, int32_t),bf);
                putchw(putp, putf, w, lz, bf);
                break;
            }

#ifdef PRINTF_FLOAT_SUPPORT
            case 'f':
                f2a(va_arg(va, double),bf);
                putchw(putp, putf, w, lz, bf);
                break;
#endif

            case 's' :
                putchw(putp, putf, w, 0, va_arg(va, char*));
                break;

            case 'u' :
            {
                ui2a(va_arg(va, uint32_t),10,0,bf);
                putchw(putp, putf, w, lz, bf);
                break;
            }

            case 'x':
            case 'X' :
                ui2a(va_arg(va, uint32_t), 16, (ch == 'X'), bf);
                putchw(putp, putf, w, lz, bf);
                break;

            case '%' :
                putf(putp, ch);
                break;

            default:
                break;
            }
        }
    }
    return length;
}

void init_printf(void* putp, void (*putf) (void*, char))
{
    stdout_putf = putf;
    stdout_putp = putp;
}

int PRINTF_NAME(const char *fmt, ...)
{
    int len;
    va_list va;
    va_start(va, fmt);
    len = format(stdout_putp, stdout_putf, fmt, va);
    va_end(va);
    return len;
}

static void putcp(void* __restrict p, char c)
{
    *(*((char**)p))++ = c;
}

static void putcp_n(void* __restrict p, char c)
{
    leng_limit--;
    if(0 < leng_limit)
    {
        *(*((char**)p))++ = c;
    }
}

int sprintf(char * __restrict s, const char * __restrict fmt, ...)
{
    int len;
    va_list va;
    va_start(va,fmt);
    len = format((void* __restrict)&s, putcp, fmt, va);
    putcp((void* __restrict)&s, 0);
    va_end(va);
    return len;
}

int snprintf (char * __restrict s, size_t size, const char * __restrict fmt, ...)
{
    int len;
    leng_limit = size;
    va_list va;
    va_start(va,fmt);
    len = format((void* __restrict)&s, putcp_n, fmt, va);
    putcp_n((void* __restrict)&s, 0);
    va_end(va);
    return len;
}
