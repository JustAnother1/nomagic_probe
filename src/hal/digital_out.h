/*
  automatically created hal/digital_out.h
*/

#include <hal/hw/SIO.h>

static inline void led_pin_on(void)
{
    SIO->GPIO_OUT_SET = 1<<25;
}
static inline void led_pin_off(void)
{
    SIO->GPIO_OUT_CLR = 1<<25;
}

