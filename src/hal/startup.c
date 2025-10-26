/*
  automatically created hal/startup.c
*/

#include <hal/debug_uart.h>
#include <hal/hw/CLOCKS.h>
#include <hal/hw/IO_BANK0.h>
#include <hal/hw/PADS_BANK0.h>
#include <hal/hw/PLL.h>
#include <hal/hw/PPB.h>
#include <hal/hw/PSM.h>
#include <hal/hw/RESETS.h>
#include <hal/hw/SIO.h>
#include <hal/hw/VREG_AND_CHIP_RESET.h>
#include <hal/hw/XIP_SSI.h>
#include <hal/hw/XOSC.h>
#include <hal/irq.h>
#include <hal/target_uart.h>

volatile uint32_t ms_since_boot;





uint32_t time_get_ms(void)
{
    return ms_since_boot;
}


void SysTick_Handler(void)
{
    ms_since_boot++;
}

/* start up code */

#define DHCSR_C_DEBUGEN_MASK  1
#define DHCSR ((uint32_t *) 0xe000edf0)

__attribute__((__noreturn__)) void Reset_Handler(void) __attribute__ ((__noreturn__, section(".third_stage_boot")));

extern int main(void);

extern uint32_t linker_bss_start;
extern uint32_t linker_bss_end;

extern uint32_t linker_data_start;
extern uint32_t linker_data_end;
extern uint32_t linker_data_in_flash;

extern uint32_t linker_code_start;
extern uint32_t linker_code_end;
extern uint32_t linker_code_in_flash;

extern uint32_t linker_ro_data_start;
extern uint32_t linker_ro_data_end;
extern uint32_t linker_ro_data_in_flash;

extern const VECTOR_FUNCTION_Type __VECTOR_TABLE_RAM[64] __attribute__((aligned(0x100u)));


__attribute__((weak))  void debug_flush(void)
{
}

__attribute__((__noreturn__)) void error_state(void)
{
    // make sure that all debug messages have been send
    debug_flush();
    if(0 != (*DHCSR & DHCSR_C_DEBUGEN_MASK))
    {
        // only break if debugger is attached
        __asm__ __volatile__ ("bkpt #0");
    }

    for (;;)
    {

    }
}


__attribute__((__noreturn__)) void Reset_Handler(void)
{
    /// !!! DO NOT CALL ANY FUNCTIONS BETWEEN THIS LINE
    uint32_t *code_start_p =  &linker_code_start;
    uint32_t *code_end_p = &linker_code_end;
    uint32_t *code_src_p = &linker_code_in_flash;

    uint32_t *rodata_start_p =  &linker_ro_data_start;
    uint32_t *rodata_end_p = &linker_ro_data_end;
    uint32_t *rodata_src_p = &linker_ro_data_in_flash;

    uint32_t *bss_start_p =  &linker_bss_start;
    uint32_t *bss_end_p = &linker_bss_end;

    uint32_t *data_start_p =  &linker_data_start;
    uint32_t *data_end_p = &linker_data_end;
    uint32_t *data_src_p = &linker_data_in_flash;

    __asm volatile ("LDR     R0,=0x20041ffc \n"
                    "MOV     SP, R0"); // set stack pointer

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
        // initialize clock cpu
    
    // for clock being stable at 200 MHz
    VREG_AND_CHIP_RESET->VREG = 0xc1; // enabled + 1.15V
    // configure external oscillator clock (12000000 Hz)
    XOSC->STARTUP = (12000000/256000) + 1;
    // power up XOSC
    XOSC->CTRL = 0xfabaa0;  // enable @ 1..15 MHz (only possible setting)
    // wait for XOSC to stabilize
    while (0 == (XOSC_STATUS_STABLE_MASK & XOSC->STATUS))
    {
        ;
    }

    // switch clk_ref and clk_sys to XOSC
    CLOCKS->CLK_REF_CTRL = (CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC << CLOCKS_CLK_REF_CTRL_SRC_OFFSET);
    CLOCKS->WAKE_EN[0] = 0xffffffff; // all clocks enabled
    CLOCKS->WAKE_EN[1] = 0x7fff; // all clocks enabled
    // wait for switch to happen
    while (4 != CLOCKS->CLK_REF_SELECTED)
    {
        ;
    }

    // configure system PLL
    // program the clk_ref divider ( 1)
    PLL_SYS->CS = 1;
    // program feedback divider (100)
    PLL_SYS->FBDIV_INT = 100;
    // turn on main power and VCO
    PLL_SYS->PWR = 0;
    // wait for VCO clock to lock
    while (0 == (PLL_CS_LOCK_MASK & PLL_SYS->CS))
    {
        ;
    }

    // set up post dividers and turn them on (6, 1)
    PLL_SYS->PRIM = (6 << PLL_PRIM_POSTDIV1_OFFSET) |(1 << PLL_PRIM_POSTDIV2_OFFSET);
    // switch sys aux to PLL
    CLOCKS->CLK_SYS_CTRL = 0;
    // switch sys mux to aux
    CLOCKS->CLK_SYS_CTRL = 1;
    // wait for locked
    while (CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC != CLOCKS->CLK_SYS_SELECTED)
    {
        ;
    }

    // peripheral clock
    // disable clock divider
    CLOCKS->CLK_PERI_CTRL = 0;
    // wait for the generated clock to stop (2 clock cycles of clock source)
    // change the auxiliary mux select control
    CLOCKS->CLK_PERI_CTRL = (CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_SYS << CLOCKS_CLK_PERI_CTRL_AUXSRC_OFFSET); // clock source is PLL_SYS - can glitch
    // enable the clock divider
    CLOCKS->CLK_PERI_CTRL = (1 << CLOCKS_CLK_PERI_CTRL_ENABLE_OFFSET) | (CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_SYS << CLOCKS_CLK_PERI_CTRL_AUXSRC_OFFSET);
    // wait for the clock generator to restart (2 clock cycles of clock source)
    __asm volatile ("nop");
    __asm volatile ("nop");


    // copy read only data from flash to RAM
    while(rodata_start_p < rodata_end_p)
    {
        *rodata_start_p = *rodata_src_p;
        rodata_start_p++;
        rodata_src_p++;
    }

    // initialize variables to their initialization value
    while(data_start_p < data_end_p)
    {
        *data_start_p = *data_src_p;
        data_start_p++;
        data_src_p++;
    }

    // initialize global variables to zero
    while(bss_start_p < bss_end_p)
    {
        *bss_start_p = 0;
        bss_start_p++;
    }

    PPB->VTOR = (uint32_t)&__VECTOR_TABLE_RAM;

    // copy code from Flash to RAM
    while(code_start_p < code_end_p)
    {
        *code_start_p = *code_src_p;
        code_start_p++;
        code_src_p++;
    }

    // disable XIP / QSPI Flash Interrupts as the (boot loader) handlers are gone now.
    XIP_SSI->IMR = 0x3f; // all interrupt are masked
    (void)XIP_SSI->ICR;  // clear all active interrupts
    /// !!! AND THIS LINE  !!!

    // initialize timer time_ms
    
    ms_since_boot = 0;
    PPB->SYST_CSR = (1 << PPB_SYST_CSR_ENABLE_OFFSET) | (1 << PPB_SYST_CSR_TICKINT_OFFSET) | (1 << PPB_SYST_CSR_CLKSOURCE_OFFSET);     // SysTick on
    PPB->SYST_RVR = 200000;  // reload value = CPU clock in Hz / 1000


    // initialize digital out loop_monitor_pin
    
    RESETS->RESET = RESETS->RESET & ~ RESETS_RESET_IO_BANK0_MASK; // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | PSM_FRCE_ON_SIO_MASK; // make sure that SIO is powered on
    SIO->GPIO_OE_CLR = 1ul << 22;
    SIO->GPIO_OUT_CLR = 1ul << 22;
    PADS_BANK0->GPIO[22] = PADS_BANK0_GPIO22_DRIVE_12MA << PADS_BANK0_GPIO22_DRIVE_OFFSET;
    IO_BANK0->GPIO22_CTRL = 5; // 5 == SIO
    SIO->GPIO_OE_SET = 1ul << 22;


    // initialize digital out led_pin
    
    RESETS->RESET = RESETS->RESET & ~ RESETS_RESET_IO_BANK0_MASK; // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | PSM_FRCE_ON_SIO_MASK; // make sure that SIO is powered on
    SIO->GPIO_OE_CLR = 1ul << 25;
    SIO->GPIO_OUT_CLR = 1ul << 25;
    PADS_BANK0->GPIO[25] = PADS_BANK0_GPIO25_DRIVE_12MA << PADS_BANK0_GPIO25_DRIVE_OFFSET;
    IO_BANK0->GPIO25_CTRL = 5; // 5 == SIO
    SIO->GPIO_OE_SET = 1ul << 25;

#ifdef FEAT_DEBUG_UART
    // initialize UART debug_uart
    debug_uart_init(115200);
#endif // FEAT_DEBUG_UART
#ifdef FEAT_TARGET_UART
    // initialize UART target_uart
    target_uart_init(115200);
#endif // FEAT_TARGET_UART

    for(;;)
    {
        main();
        // main exited - WTF???
    }
}

