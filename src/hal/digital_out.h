/*
  automatically created hal/digital_out.h
*/

#include <hal/hw/SIO.h>


#ifndef HAL_DIGITAL_OUT_H_
#define HAL_DIGITAL_OUT_H_
static inline void loop_monitor_pin_on(void)
{
    SIO->GPIO_OUT_SET = 1<<22;
}

static inline void loop_monitor_pin_off(void)
{
    SIO->GPIO_OUT_CLR = 1<<22;
}

static inline void loop_monitor_pin_toggle(void)
{
    SIO->GPIO_OUT_XOR = 1<<22;
}
static inline void led_pin_on(void)
{
    SIO->GPIO_OUT_SET = 1<<25;
}

static inline void led_pin_off(void)
{
    SIO->GPIO_OUT_CLR = 1<<25;
}

static inline void led_pin_toggle(void)
{
    SIO->GPIO_OUT_XOR = 1<<25;
}
#endif /* HAL_DIGITAL_OUT_H_ */

