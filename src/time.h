#ifndef TIME_H_
#define TIME_H_

#include <stdint.h>

void delay_us(int usec);

void init_time(void);
uint32_t time_get_ms(void);


#endif /* TIME_H_ */
