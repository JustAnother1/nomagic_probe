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
#include "hal/hw/XOSC.h"
#include "hal/hw/CLOCKS.h"
#include "hal/hw/ROSC.h"
#include "hal/hw/PLL_SYS.h"
#include "hal/hw/PSM.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/SIO.h"
#include "main.h"
#include <stdnoreturn.h>
#include "hal/debug_uart.h"
#include "hal/watchdog.h"

typedef void (*VECTOR_FUNCTION_Type)(void);

void default_Handler(void) __attribute__ ((weak, interrupt ("IRQ")));
void NMI_Handler(void) __attribute__ ((weak, interrupt ("IRQ")));
void Hard_Fault_Handler(void) __attribute__ ((weak, interrupt ("IRQ")));
void SVCall_Handler(void) __attribute__ ((weak, interrupt ("IRQ")));
void PendSV_Handler(void) __attribute__ ((weak, interrupt ("IRQ")));
void SysTick_Handler(void) __attribute__ ((weak, interrupt ("IRQ")));

void TIMER_IRQ_0(void) __attribute__ ((weak, interrupt ("IRQ")));
void TIMER_IRQ_1(void) __attribute__ ((weak, interrupt ("IRQ")));
void TIMER_IRQ_2(void) __attribute__ ((weak, interrupt ("IRQ")));
void TIMER_IRQ_3(void) __attribute__ ((weak, interrupt ("IRQ")));
void PWM_IRQ_WRAP(void) __attribute__ ((weak, interrupt ("IRQ")));
void USBCTRL_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void XIP_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void PIO0_IRQ_0(void) __attribute__ ((weak, interrupt ("IRQ")));
void PIO0_IRQ_1(void) __attribute__ ((weak, interrupt ("IRQ")));
void PIO1_IRQ_0(void) __attribute__ ((weak, interrupt ("IRQ")));
void PIO1_IRQ_1(void) __attribute__ ((weak, interrupt ("IRQ")));
void DMA_IRQ_0(void) __attribute__ ((weak, interrupt ("IRQ")));
void DMA_IRQ_1(void) __attribute__ ((weak, interrupt ("IRQ")));
void IO_IRQ_BANK0(void) __attribute__ ((weak, interrupt ("IRQ")));
void IO_IRQ_QSPI(void) __attribute__ ((weak, interrupt ("IRQ")));
void SIO_IRQ_PROC0(void) __attribute__ ((weak, interrupt ("IRQ")));
void SIO_IRQ_PROC1(void) __attribute__ ((weak, interrupt ("IRQ")));
void CLOCKS_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void SPI0_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void SPI1_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void UART0_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void UART1_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void ADC_IRQ_FIFO(void) __attribute__ ((weak, interrupt ("IRQ")));
void I2C0_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void I2C1_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));
void RTC_IRQ(void) __attribute__ ((weak, interrupt ("IRQ")));

#ifdef ENABLE_CORE_1
static void wake_up_core1(void);
#endif
_Noreturn void error_state(void) __attribute__ ((weak, __noreturn__));
_Noreturn void Reset_Handler()__attribute__((__noreturn__, section(".third_stage_boot")));


const VECTOR_FUNCTION_Type __VECTOR_TABLE[64] __attribute__((used, section(".vectors")))
= {
/*  0: Initial Stack Pointer    */(VECTOR_FUNCTION_Type) (0x20041fff),  // Core 0
/*  1: Reset Handler            */Reset_Handler,
/*  2: NMI Handler        (-14) */NMI_Handler,
/*  3: Hard Fault Handler (-13) */Hard_Fault_Handler,
/*  4: reserved           (-12) */default_Handler,
/*  5: reserved           (-11) */default_Handler,
/*  6: reserved           (-10) */default_Handler,
/*  7: reserved           ( -9) */default_Handler,
/*  8: reserved           ( -8) */default_Handler,
/*  9: reserved           ( -7) */default_Handler,
/* 10: reserved           ( -6) */default_Handler,
/* 11: SVCall Handler     ( -5) */SVCall_Handler,
/* 12: reserved           ( -4) */default_Handler,
/* 13: reserved           ( -3) */default_Handler,
/* 14: PendSV Handler     ( -2) */PendSV_Handler,
/* 15: SysTick Handler    ( -1) */SysTick_Handler,
/* 16: TIMER_IRQ_0        (  0) */TIMER_IRQ_0,
/* 17: TIMER_IRQ_1        (  1) */TIMER_IRQ_1,
/* 18: TIMER_IRQ_2        (  2) */TIMER_IRQ_2,
/* 19: TIMER_IRQ_3        (  3) */TIMER_IRQ_3,
/* 20: PWM_IRQ_WRAP       (  4) */PWM_IRQ_WRAP,
/* 21: USBCTRL_IRQ        (  5) */USBCTRL_IRQ,
/* 22: XIP_IRQ            (  6) */XIP_IRQ,
/* 23: PIO0_IRQ_0         (  7) */PIO0_IRQ_0,
/* 24: PIO0_IRQ_1         (  8) */PIO0_IRQ_1,
/* 25: PIO1_IRQ_0         (  9) */PIO1_IRQ_0,
/* 26: PIO1_IRQ_1         ( 10) */PIO1_IRQ_1,
/* 27: DMA_IRQ_0          ( 11) */DMA_IRQ_0,
/* 28: DMA_IRQ_1          ( 12) */DMA_IRQ_1,
/* 29: IO_IRQ_BANK0       ( 13) */IO_IRQ_BANK0,
/* 30: IO_IRQ_QSPI        ( 14) */IO_IRQ_QSPI,
/* 31: SIO_IRQ_PROC0      ( 15) */SIO_IRQ_PROC0,
/* 32: SIO_IRQ_PROC1      ( 16) */SIO_IRQ_PROC1,
/* 33: CLOCKS_IRQ         ( 17) */CLOCKS_IRQ,
/* 34: SPI0_IRQ           ( 18) */SPI0_IRQ,
/* 35: SPI1_IRQ           ( 19) */SPI1_IRQ,
/* 36: UART0_IRQ          ( 20) */UART0_IRQ,
/* 37: UART1_IRQ          ( 21) */UART1_IRQ,
/* 38: ADC_IRQ_FIFO       ( 22) */ADC_IRQ_FIFO,
/* 39: I2C0_IRQ           ( 23) */I2C0_IRQ,
/* 40: I2C1_IRQ           ( 24) */I2C1_IRQ,
/* 41: RTC_IRQ            ( 25) */RTC_IRQ,
/* 42: reserved           ( 26) */default_Handler,
/* 43: reserved           ( 27) */default_Handler,
/* 44: reserved           ( 28) */default_Handler,
/* 45: reserved           ( 29) */default_Handler,
/* 46: reserved           ( 30) */default_Handler,
/* 47: reserved           ( 31) */default_Handler,
/* 48: reserved           ( 32) */default_Handler,
/* 49: reserved           ( 33) */default_Handler,
/* 50: reserved           ( 34) */default_Handler,
/* 51: reserved           ( 35) */default_Handler,
/* 52: reserved           ( 36) */default_Handler,
/* 53: reserved           ( 37) */default_Handler,
/* 54: reserved           ( 38) */default_Handler,
/* 55: reserved           ( 39) */default_Handler,
/* 56: reserved           ( 40) */default_Handler,
/* 57: reserved           ( 41) */default_Handler,
/* 58: reserved           ( 42) */default_Handler,
/* 59: reserved           ( 43) */default_Handler,
/* 60: reserved           ( 44) */default_Handler,
/* 61: reserved           ( 45) */default_Handler,
/* 62: reserved           ( 46) */default_Handler,
/* 63: reserved           ( 47) */default_Handler, };

extern uint32_t __bss_start;
extern uint32_t __bss_end;

extern uint32_t __data_start;
extern uint32_t __data_end;
extern uint32_t __data_in_flash;

extern uint32_t __code_start;
extern uint32_t __code_end;
extern uint32_t __code_in_flash;

extern uint32_t __third_boot_start;
extern uint32_t __third_boot_end;

extern uint32_t __ro_data_start;
extern uint32_t __ro_data_end;

void NMI_Handler(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_NMI);
    error_state();
}

void Hard_Fault_Handler(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_HARD_FAULT);
    error_state();
}

void SVCall_Handler(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_SVCALL);
    error_state();
}

void PendSV_Handler(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_PENDSV);
    error_state();
}

void SysTick_Handler(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_SYSTICK);
    error_state();
}

void TIMER_IRQ_0(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_0);
    error_state();
}

void TIMER_IRQ_1(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_1);
    error_state();
}

void TIMER_IRQ_2(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_2);
    error_state();
}

void TIMER_IRQ_3(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_3);
    error_state();
}

void PWM_IRQ_WRAP(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_PWM);
    error_state();
}

void USBCTRL_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_USB_CTRL);
    error_state();
}

void XIP_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_XIP);
    error_state();
}

void PIO0_IRQ_0(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_0_0);
    error_state();
}

void PIO0_IRQ_1(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_0_1);
    error_state();
}

void PIO1_IRQ_0(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_1_0);
    error_state();
}

void PIO1_IRQ_1(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_1_1);
    error_state();
}

void DMA_IRQ_0(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_DMA_0);
    error_state();
}

void DMA_IRQ_1(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_DMA_1);
    error_state();
}

void IO_IRQ_BANK0(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_GPIO_BANK_0);
    error_state();
}

void IO_IRQ_QSPI(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_GPIO_QSPI);
    error_state();
}

void SIO_IRQ_PROC0(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_SIO_PROC_0);
    error_state();
}

void SIO_IRQ_PROC1(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_SIO_PROC_1);
    error_state();
}

void CLOCKS_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_CLOCKS);
    error_state();
}

void SPI0_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_SPI_0);
    error_state();
}

void SPI1_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_SPI_1);
    error_state();
}

void UART0_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_UART_0);
    error_state();
}

void UART1_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_UART_1);
    error_state();
}

void ADC_IRQ_FIFO(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_ADC_FIFO);
    error_state();
}

void I2C0_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_I2C_0);
    error_state();
}

void I2C1_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_I2C_1);
    error_state();
}

void RTC_IRQ(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_RTC);
    error_state();
}

void default_Handler(void) {
    watchdog_report_issue(ISSUE_UNEXPECTED_HANDLER_CALLED_DEFAULT);
    error_state();
}

_Noreturn void error_state(void)
{
    __asm__ __volatile__ ("bkpt #0");

    for (;;)
    {
        /*
        // uint8_t data = 23;
        SIO->GPIO_OUT_SET = 1 << 25;
        // Delay
        delay_us(10 * 1000);
        SIO->GPIO_OUT_CLR = 1 << 25;
        // Delay
        delay_us(190 * 1000);
        */
    }
}

void startup_report(void)
{
    debug_line("3rd stage boot start: 0x%08lx", (uint32_t)&__third_boot_start);
    debug_line("3rd stage boot end:   0x%08lx", (uint32_t)&__third_boot_end);
    debug_line(".code start:          0x%08lx", (uint32_t)&__code_start);
    debug_line(".code end:            0x%08lx", (uint32_t)&__code_end);
    debug_line(".code start in flash: 0x%08lx", (uint32_t)&__code_in_flash);
    debug_line(".code end in flash:   0x%08lx", (uint32_t)(&__code_in_flash + (&__code_end - &__code_start)));
    debug_line(".bss start:           0x%08lx", (uint32_t)&__bss_start);
    debug_line(".bss end:             0x%08lx", (uint32_t)&__bss_end);
    debug_line(".data start:          0x%08lx", (uint32_t)&__data_start);
    debug_line(".data end:            0x%08lx", (uint32_t)&__data_end);
    debug_line(".data start in flash: 0x%08lx", (uint32_t)&__data_in_flash);
    debug_line(".data end in flash:   0x%08lx", (uint32_t)(&__data_in_flash + (&__data_end - &__data_start)));
    debug_line(".rodata start:        0x%08lx", (uint32_t)&__ro_data_start);
    debug_line(".rodata end:          0x%08lx", (uint32_t)&__ro_data_end);
}

#ifdef ENABLE_CORE_1
static void wake_up_core1(void)
{
    // if you are using the SDK then you can simply use the multicore_launch_core1 function to launch code on processor core 1.

    // values to be sent in order over the FIFO from core 0 to core 1
    //
    // vector_table is value for VTOR register
    // sp is initial stack pointer (SP)
    // entry is the initial program counter (PC) (don't forget to set the thumb bit!)
    const uint32_t cmd_sequence[6] = {0, 0, 1, (uintptr_t) &__VECTOR_TABLE, (uintptr_t) 0x20040fff, (uintptr_t) ((uint32_t)(&main1) | 1)};
    uint32_t seq = 0;
    uint32_t response = 0;
    uint32_t tries = 0;
    do {
        uint32_t cmd = cmd_sequence[seq];
        // always drain the READ FIFO (from core 1) before sending a 0
        if (!cmd)
        {
            // discard data from read FIFO until empty
            while (0 != (SIO->FIFO_ST & 1))
            {
                response = SIO->FIFO_RD;
            }
            // execute a SEV as core 1 may be waiting for FIFO space
            __asm volatile ("sev");
        }
        // write 32 bit value to write FIFO
        // We wait for the fifo to have some space
        while (0 == (SIO->FIFO_ST & 2))
            ;

        SIO->FIFO_WR = cmd;

        // Fire off an event to the other core
        __asm volatile ("sev");

        // read 32 bit value from read FIFO once available
        // If nothing there yet, we wait for an event first,
        // to try and avoid too much busy waiting
        while (1 == (SIO->FIFO_ST & 1))
        {
            response = SIO->FIFO_RD;
        }

        response = SIO->FIFO_RD;

        // move to next state on correct response (echo-d value) otherwise start over
        if(cmd == response)
        {
            seq = seq +1;
        }
        else
        {
            seq = 0;
            tries++;
        }
    } while ((seq < 6) && (tries < 6));
}
#endif

_Noreturn void Reset_Handler()
{
    /// !!! DO NOT CALL ANY FUNCTIONS BETWEEN THIS LINE
    uint32_t *code_start_p =  &__code_start;
    uint32_t *code_end_p = &__code_end;
    uint32_t *code_src_p = &__code_in_flash;

    uint32_t *bss_start_p =  &__bss_start;
    uint32_t *bss_end_p = &__bss_end;

    uint32_t *data_start_p =  &__data_start;
    uint32_t *data_end_p = &__data_end;
    uint32_t *data_src_p = &__data_in_flash;

    PSM->FRCE_ON = 0x1ffff; // power on all needed blocks
    // wait for powered on blocks to become available
    while (0xffff != (0xffff & PSM->DONE))
    {
        ;
    }

    RESETS->RESET = 0x1fbec1d;  // Put everything into reset (just to be sure in case of software reset)
    // everything excludes: SYSCFG, PLL_SYS, PADS_QSPI, PADS_BANK0, JTAG, IOQSPI, IOBANK0, and BUSCTRL
    while (0x1082 != (0x1082 & RESETS->RESET_DONE))
    {
        ;
    }
    // configure clock: pico has XOSC = 12 MHz
    XOSC->STARTUP = 0x2f; // = 47 * 256 = 1ms @ 12MHz
    // power up XOSC
    XOSC->CTRL = 0xfabaa0;
    // wait for XOSC to stabilize
    while (0 == (0x80000000 & XOSC->STATUS))
    {
        ;
    }
    // switch clk_ref and clk_sys to XOSC
    CLOCKS->CLK_REF_CTRL = 0x2;
    CLOCKS->WAKE_EN0 = 0xffffffff;
    CLOCKS->WAKE_EN1 = 0x7fff;
    // wait for switch to happen
    while (0x4 != CLOCKS->CLK_REF_SELECTED)
    {
        ;
    }
    // configure system PLL
    // program the clk_ref divider ( 1)
    PLL_SYS->CS = 0x1;
    // program feedback divider ( 125)
    PLL_SYS->FBDIV_INT = 0x7d;
    // turn on main power and VCO
    PLL_SYS->PWR = 0x0;
    // wait for VCO clock to lock
    while (0 == (0x80000000 & PLL_SYS->CS))
    {
        ;
    }
    // set up post dividers and turn them on (6, 2)
    PLL_SYS->PRIM = 0x62000;
    // switch sys aux to PLL
    CLOCKS->CLK_SYS_CTRL = 0;
    // switch sys mux to aux
    CLOCKS->CLK_SYS_CTRL = 1;
    // wait for locked
    while (2 != CLOCKS->CLK_SYS_SELECTED)
    {
        ;
    }

    // peripheral clock
    // disable clock divider
    CLOCKS->CLK_PERI_CTRL = 0;
    // wait for the generated clock to stop (2 clock cycles of clock source)
    // change the auxiliary mux select control
    CLOCKS->CLK_PERI_CTRL = 0x20; // clock source is PLL_SYS - can glitch
    // enable the clock divider
    CLOCKS->CLK_PERI_CTRL = 0x820;
    // wait for the clock generator to restart (2 clock cycles of clock source)

    // power down ROSC
    ROSC->CTRL = 0x00d1efa4;
    // ROSC = off; XOSC = 12 MHz; PLL_SYS = 125 MHz
    // clk_ref = 12 MHz; clk_sys = 125 MHz; clk_peri = 125 MHz

    // copy code from Flash to RAM
    while(code_start_p < code_end_p)
    {
        *code_start_p = *code_src_p;
        code_start_p++;
        code_src_p++;
    }

    // initialize global variables to zero
    while(bss_start_p < bss_end_p)
    {
        *bss_start_p = 0;
        bss_start_p++;
    }

    // initialize variables to their initialization value
    while(data_start_p < data_end_p)
    {
        *data_start_p = *data_src_p;
        data_start_p++;
        data_src_p++;
    }

    /// !!! AND THIS LINE  !!!

#ifdef ENABLE_CORE_1
    if(0 != SIO->CPUID)
    {
        // soft reset with core1 active ?
        main1();
    }
    else
    {
        wake_up_core1();
    }
    main();
#endif

    main();
    // main exited - WTF???
    watchdog_report_issue(ISSUE_UNEXPECTED_CODE_REACHED_MAIN_EXITED);
    error_state();
}

