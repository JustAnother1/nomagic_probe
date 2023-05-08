#include "time.h"
#include <hal/hw/PPB.h>

volatile uint32_t ms_since_boot;

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
    ms_since_boot++;
}

void init_time(void)
{
    ms_since_boot = 0;
    PPB->SYST_CSR = 0x7;  // sysTick an
    PPB->SYST_RVR = 125000;  // reload value
}

uint32_t time_get_ms(void)
{
    return ms_since_boot;
}


