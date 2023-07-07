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
#ifndef HAL_STARTUP_H
#define HAL_STARTUP_H

#include <stdio.h>
#include <stdbool.h>

// The Interrupt with the lowest Priority Number is the most important
#define TIMER_IRQ_0_PRIORITY         3
#define TIMER_IRQ_1_PRIORITY         3
#define TIMER_IRQ_2_PRIORITY         3
#define TIMER_IRQ_3_PRIORITY         3
#define PWM_IRQ_WRAP_PRIORITY        3
#define USBCTRL_IRQ_PRIORITY         3
#define XIP_IRQ_PRIORITY             3
#define PIO0_IRQ_0_PRIORITY          3
#define PIO0_IRQ_1_PRIORITY          3
#define PIO1_IRQ_0_PRIORITY          3
#define PIO1_IRQ_1_PRIORITY          3
#define DMA_IRQ_0_PRIORITY           3
#define DMA_IRQ_1_PRIORITY           3
#define IO_IRQ_BANK0_PRIORITY        3
#define IO_IRQ_QSPI_PRIORITY         3
#define SIO_IRQ_PROC0_PRIORITY       3
#define SIO_IRQ_PROC1_PRIORITY       3
#define CLOCKS_IRQ_PRIORITY          3
#define SPI0_IRQ_PRIORITY            3
#define SPI1_IRQ_PRIORITY            3
#define UART0_IRQ_PRIORITY           0
#define UART1_IRQ_PRIORITY           3
#define ADC_IRQ_FIFO_PRIORITY        3
#define I2C0_IRQ_PRIORITY            3
#define I2C1_IRQ_PRIORITY            3
#define RTC_IRQ_PRIORITY             3

// IRQ Numbers
#define TIMER_IRQ_0_NUMBER          0
#define TIMER_IRQ_1_NUMBER          1
#define TIMER_IRQ_2_NUMBER          2
#define TIMER_IRQ_3_NUMBER          3
#define PWM_IRQ_WRAP_NUMBER         4
#define USBCTRL_IRQ_NUMBER          5
#define XIP_IRQ_NUMBER              6
#define PIO0_IRQ_0_NUMBER           7
#define PIO0_IRQ_1_NUMBER           8
#define PIO1_IRQ_0_NUMBER           9
#define PIO1_IRQ_1_NUMBER          10
#define DMA_IRQ_0_NUMBER           11
#define DMA_IRQ_1_NUMBER           12
#define IO_IRQ_BANK0_NUMBER        13
#define IO_IRQ_QSPI_NUMBER         14
#define SIO_IRQ_PROC0_NUMBER       15
#define SIO_IRQ_PROC1_NUMBER       16
#define CLOCKS_IRQ_NUMBER          17
#define SPI0_IRQ_NUMBER            18
#define SPI1_IRQ_NUMBER            19
#define UART0_IRQ_NUMBER           20
#define UART1_IRQ_NUMBER           21
#define ADC_IRQ_FIFO_NUMBER        22
#define I2C0_IRQ_NUMBER            23
#define I2C1_IRQ_NUMBER            24
#define RTC_IRQ_NUMBER             25

typedef struct {
    volatile uint32_t ISER;               //  Interrupt Set Enable
    volatile uint32_t RESERVED0[31];
    volatile uint32_t ICER;               // Interrupt Clear Enable
    volatile uint32_t RESERVED1[31U];
    volatile uint32_t ISPR;               // Interrupt Set Pending
    volatile uint32_t RESERVED2[31U];
    volatile uint32_t ICPR;               // Interrupt Clear Pending
    volatile uint32_t RESERVED3[31U];
    volatile uint32_t RESERVED4[64U];
    volatile uint32_t IP[8U];             // Interrupt Priority
} NVIC_Type;

#define NVIC    ((volatile NVIC_Type*) 0xE000E100)

static inline void NVIC_EnableIRQ(uint32_t IRQ_Number, uint32_t priority) {
	// set Priority
    NVIC->IP[(IRQ_Number >> 2)] = ((uint32_t)(
    NVIC->IP[(IRQ_Number >> 2)] & ~(0xFFUL << (IRQ_Number & 0x03UL) * 8UL))
            | (((priority << (8U - 2)) & (uint32_t) 0xFFUL)
                    << (IRQ_Number & 0x03UL) * 8UL));
    // enable Interrupt
    __asm volatile("":::"memory");
    NVIC->ISER = (uint32_t)(1UL << (((uint32_t) IRQ_Number) & 0x1FUL));
    __asm volatile("":::"memory");
}

/**
  \brief   Disable Interrupt
  \details Disables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
static inline void NVIC_DisableIRQ(int32_t IRQn)
{
  if (IRQn >= 0)
  {
    NVIC->ICER = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __asm volatile ("dsb 0xF":::"memory");
    __asm volatile ("isb 0xF":::"memory");
  }
}

#endif // HAL_STARTUP_H
