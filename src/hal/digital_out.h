/*
  automatically created hal/digital_out.h
  created at: 2025-01-17 00:42:41
  created from mbsp.json
*/

#include <hal/hw/IO_BANK0.h>
#include <hal/hw/PADS_BANK0.h>
#include <hal/hw/PSM.h>
#include <hal/hw/RESETS.h>
#include <hal/hw/SIO.h>

static inline void led_pin_on(void)
{
    SIO->GPIO_OUT_SET = 1<<25;
}
static inline void led_pin_off(void)
{
    SIO->GPIO_OUT_CLR = 1<<25;
}

