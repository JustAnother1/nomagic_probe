/* start up code */

#include "hal/hw/XOSC.h"
#include "hal/hw/CLOCKS.h"
#include "hal/hw/ROSC.h"
#include "hal/hw/PLL_SYS.h"
#include "hal/hw/PSM.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/SIO.h"
#include "main.h"

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
// void main(void) __attribute__ ((weak, __noreturn__));
// void main1(void) __attribute__ ((weak, __noreturn__));
void error_state(void) __attribute__ ((weak, __noreturn__));
void Reset_Handler()__attribute__((__noreturn__));

const VECTOR_FUNCTION_Type __VECTOR_TABLE[64] __attribute__((used, section(".vectors")))
= {
/*  0: Initial Stack Pointer    */(VECTOR_FUNCTION_Type) (0x20040000),
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

void NMI_Handler(void) {
    error_state();
}

void Hard_Fault_Handler(void) {
    error_state();
}

void SVCall_Handler(void) {
    error_state();
}

void PendSV_Handler(void) {
    error_state();
}

void SysTick_Handler(void) {
    error_state();
}

void TIMER_IRQ_0(void) {
    error_state();
}

void TIMER_IRQ_1(void) {
    error_state();
}

void TIMER_IRQ_2(void) {
    error_state();
}

void TIMER_IRQ_3(void) {
    error_state();
}

void PWM_IRQ_WRAP(void) {
    error_state();
}

void USBCTRL_IRQ(void) {
    error_state();
}

void XIP_IRQ(void) {
    error_state();
}

void PIO0_IRQ_0(void) {
    error_state();
}

void PIO0_IRQ_1(void) {
    error_state();
}

void PIO1_IRQ_0(void) {
    error_state();
}

void PIO1_IRQ_1(void) {
    error_state();
}

void DMA_IRQ_0(void) {
    error_state();
}

void DMA_IRQ_1(void) {
    error_state();
}

void IO_IRQ_BANK0(void) {
    error_state();
}

void IO_IRQ_QSPI(void) {
    error_state();
}

void SIO_IRQ_PROC0(void) {
    error_state();
}

void SIO_IRQ_PROC1(void) {
    error_state();
}

void CLOCKS_IRQ(void) {
    error_state();
}

void SPI0_IRQ(void) {
    error_state();
}

void SPI1_IRQ(void) {
    error_state();
}

void UART0_IRQ(void) {
    error_state();
}

void UART1_IRQ(void) {
    error_state();
}

void ADC_IRQ_FIFO(void) {
    error_state();
}

void I2C0_IRQ(void) {
    error_state();
}

void I2C1_IRQ(void) {
    error_state();
}

void RTC_IRQ(void) {
    error_state();
}

void default_Handler(void) {
    error_state();
}

/*
void main(void) {
    // send core to sleep
    // TODO
	for(;;) {
		;
	}
}

void main1(void) {
    // send core to sleep
    // TODO
	for(;;) {
		;
	}
}
*/

void error_state(void)
{
    // asm("bkpt #0");
    while (1)
        ;
}

/**
  \brief   Set Priority Mask
  \details Assigns the given value to the Priority Mask Register.
  \param [in]    priMask  Priority Mask
 */
static inline void __set_PRIMASK(uint32_t priMask)
{
  asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}

uint32_t __aeabi_uidiv(uint32_t numerator, uint32_t denominator)
{
    uint32_t div;
    uint32_t rem;

    // disable all interrupts
    __set_PRIMASK(1); // PRIMASK = 1;
    // write values
    SIO-> DIV_UDIVIDEND = numerator;
    SIO->DIV_UDIVISOR = denominator;
    // wait 8 cycles
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");

    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    // read result
    rem = SIO->DIV_REMAINDER;
    div = SIO->DIV_QUOTIENT;

    // restore enabled interrupts
    __set_PRIMASK(0); // PRIMASK = 0;
    (void)rem;
    return div;
}

uint32_t __aeabi_uidivmod(uint32_t numerator, uint32_t denominator)
{
    uint32_t div;
    uint32_t rem;

    // disable all interrupts
    __set_PRIMASK(1); // PRIMASK = 1;
    // write values
    SIO-> DIV_UDIVIDEND = numerator;
    SIO->DIV_UDIVISOR = denominator;
    // wait 8 cycles
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");

    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    // read result
    rem = SIO->DIV_REMAINDER;
    div = SIO->DIV_QUOTIENT;

    // restore enabled interrupts
    __set_PRIMASK(0); // PRIMASK = 0;
    (void)div;
    return rem;
}


void Reset_Handler() {
    uint32_t *bss_start_p =  &__bss_start;
    uint32_t *bss_end_p = &__bss_end;

    PSM->FRCE_ON = 0x1ffff; // power on all needed blocks
    // wait for powered on blocks to become available
    while (0xffff != (0xffff & PSM->DONE)) {
        ;
    }

    if(0 != SIO->CPUID) {
        // soft reset with core1 active
        // send core1 to sleep
        // TODO
    }

    RESETS->RESET = 0x1fbec1d;  // Put everything into reset (just to be sure in case of software reset)
    // everything excludes: SYSCFG, PLL_SYS, PADS_QSPI, PADS_BANK0, JTAG, IOQSPI, IOBANK0, and BUSCTRL
    while (0x1082 != (0x1082 & RESETS->RESET_DONE)) {
        ;
    }
    // configure clock: pico has XOSC = 12 MHz
    XOSC->STARTUP = 0x2f; // = 47 * 256 = 1ms @ 12MHz
    // power up XOSC
    XOSC->CTRL = 0xfabaa0;
    // wait for XOSC to stabilize
    while (0 == (0x80000000 & XOSC->STATUS)) {
        ;
    }
    // switch clk_ref and clk_sys to XOSC
    CLOCKS->CLK_REF_CTRL = 0x2;
    // wait for switch to happen
    while (0x4 != CLOCKS->CLK_REF_SELECTED) {
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
    while (0 == (0x80000000 & PLL_SYS->CS)) {
        ;
    }
    // set up post dividers and turn them on (6, 2)
    PLL_SYS->PRIM = 0x62000;
    // switch sys aux to PLL
    CLOCKS->CLK_SYS_CTRL = 0;
    // switch sys mux to aux
    CLOCKS->CLK_SYS_CTRL = 1;
    // wait for locked
    while (2 != CLOCKS->CLK_SYS_SELECTED) {
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

    // initialize global variables to zero
    while (bss_start_p < bss_end_p) {
        *bss_start_p = 0;
        bss_start_p++;
    }

    main();

    // wake core1 up
    // TODO
/*
    if(0 == SIO->CPUID)
    {
    	main();
    }
    else
    {
    	main1();
    }
*/
    // main exited - WTF???
    error_state();
}

