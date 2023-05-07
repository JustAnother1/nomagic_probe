/*
 automatically created main.c
 created at: 2023-04-26 01:10:10
 created from blinky.xml
 */

#include <hal/hw/IO_BANK0.h>
#include <hal/hw/PADS_BANK0.h>
#include <hal/hw/PSM.h>
#include <hal/hw/RESETS.h>
#include <hal/hw/SIO.h>
#include <hal/hw/XOSC.h>
#include <stdint.h>
#include "hal/console_uart.h"
#include <hal/hw/PPB.h>
#include "cli/cli.h"

void delay_us(int usec);
void main(void);

static volatile uint32_t time;

void delay_us(int usec) {
    while (usec != 0) {
        volatile uint32_t cnt = 11;
        while (cnt > 0) {
            cnt--;
        }
        usec--;
    }
}

void SysTick_Handler(void) {
	time++;
}

void init_time(void)
{
	time = 0;
	PPB->SYST_CSR = 0x7;  // sysTick an
	PPB->SYST_RVR = 125000;  // reload value
}


void main1(void) {
    RESETS->RESET = RESETS->RESET & ~0x00000020; // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | 0x00000400; // make sure that SIO is powered on
    SIO->GPIO_OE_CLR = 1ul << 25;
    SIO->GPIO_OUT_CLR = 1ul << 25;
    PADS_BANK0->GPIO25 = 0x00000030;
    IO_BANK0->GPIO25_CTRL = 5;
    SIO->GPIO_OE_SET = 1ul << 25;
    init_time();

    // console_uart_initialize();
    for (;;) {
        // uint8_t data = 23;
        SIO->GPIO_OUT_SET = 1 << 25;
        // Delay
        delay_us((10 / 1 * 60) * 1000);
        SIO->GPIO_OUT_CLR = 1 << 25;
        // Delay
        delay_us((10 / 1 * (100 - 60)) * 1000);
        // console_uart_send_bytes(&data, 1);
    }
}

void main(void) {
	console_uart_initialize();
	cli_init();
    for (;;) {
    	cli_tick();
    }
}

