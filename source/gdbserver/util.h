#ifndef UTIL_H_
#define UTIL_H_

#include <stdint.h>
#include <stdbool.h>


uint32_t calculateChecksum(char *data, uint32_t length);
uint32_t hex_to_int(char* hex, uint32_t num_digits);
void int_to_hex(char* hex, uint32_t value, uint32_t num_digits);


#endif /* UTIL_H_ */
