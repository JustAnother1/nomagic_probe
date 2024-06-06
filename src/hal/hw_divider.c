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

#include "hw_divider.h"
#include "hal/hw/SIO.h"

static inline void __set_PRIMASK(uint32_t priMask);
static inline void waitForDivisor(void);

/**
  \brief   Set Priority Mask
  \details Assigns the given value to the Priority Mask Register.
  \param [in]    priMask  Priority Mask
 */
static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm__ __volatile__ ("MSR primask, %0" : : "r" (priMask) : "memory");
}

static inline void waitForDivisor(void)
{
    // wait 8 cycles
    __asm__ __volatile__ ("nop");
    __asm__ __volatile__ ("nop");
    __asm__ __volatile__ ("nop");
    __asm__ __volatile__ ("nop");

    __asm__ __volatile__ ("nop");
    __asm__ __volatile__ ("nop");
    __asm__ __volatile__ ("nop");
    __asm__ __volatile__ ("nop");
}
/* TODO
int32_t __aeabi_idiv(int32_t numerator, int32_t denominator)
{
    int32_t div;
    int32_t rem;

    // disable all interrupts
    __set_PRIMASK(1); // PRIMASK = 1;
    // write values
    SIO->DIV_SDIVIDEND = (uint32_t)numerator;
    SIO->DIV_SDIVISOR = (uint32_t)denominator;

    waitForDivisor();

    // read result
    rem = (int32_t)SIO->DIV_REMAINDER;
    div = (int32_t)SIO->DIV_QUOTIENT;

    // restore enabled interrupts
    __set_PRIMASK(0); // PRIMASK = 0;
    (void)rem;
    return div;
}
*/
uint32_t __aeabi_uidiv(uint32_t numerator, uint32_t denominator)
{
    uint32_t div;
    uint32_t rem;

    // disable all interrupts
    __set_PRIMASK(1); // PRIMASK = 1;
    // write values
    SIO->DIV_UDIVIDEND = numerator;
    SIO->DIV_UDIVISOR = denominator;

    waitForDivisor();

    // read result
    rem = SIO->DIV_REMAINDER;
    div = SIO->DIV_QUOTIENT;

    // restore enabled interrupts
    __set_PRIMASK(0); // PRIMASK = 0;
    (void)rem;
    return div;
}

#pragma GCC diagnostic ignored "-Wreturn-type"
uint32_t __aeabi_uidivmod(uint32_t numerator, uint32_t denominator)
{
    // disable all interrupts
    __set_PRIMASK(1); // PRIMASK = 1;
    // write values
    SIO->DIV_UDIVIDEND = numerator;
    SIO->DIV_UDIVISOR = denominator;

    waitForDivisor();

    // read results and returns them both
    __asm__ __volatile__ (
            "ldr r2, = 0xD0000000\n\t"
            "ldr r1, [r2, #0x74]\n\t"
            "ldr r0, [r2, #0x70]"
              );
    // restore enabled interrupts
    __set_PRIMASK(0); // PRIMASK = 0;
}
#pragma GCC diagnostic pop

void div_and_mod(uint32_t divident, uint32_t divisor, uint32_t* quotient, uint32_t* remainder)
{
    // disable all interrupts
    __set_PRIMASK(1); // PRIMASK = 1;

    // write values
    SIO->DIV_UDIVIDEND = divident;
    SIO->DIV_UDIVISOR = divisor;

    waitForDivisor();

    // read result
    *remainder = SIO->DIV_REMAINDER;
    *quotient = SIO->DIV_QUOTIENT;

    // restore enabled interrupts
    __set_PRIMASK(0); // PRIMASK = 0;
}
