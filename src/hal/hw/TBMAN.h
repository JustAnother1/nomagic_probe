/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_TBMAN_H
#define HW_TBMAN_H
/** Testbench manager. Allows the programmer to know what platform their software is running on. */
/** Memory Block starting at 0x4006C000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define TBMAN_PLATFORM_FPGA_OFFSET                         1u
#define TBMAN_PLATFORM_FPGA_MASK                           2u

#define TBMAN_PLATFORM_ASIC_OFFSET                         0u
#define TBMAN_PLATFORM_ASIC_MASK                           1u


typedef struct
{

/** PLATFORM (offset: 0x0)
  Indicates the type of platform in use
  access : read-write
  reset value : 0x5
  reset mask : 0x0
  Field: FPGA
  offset: 1, size: 1, access: read-only
  Indicates the platform is an FPGA
  Field: ASIC
  offset: 0, size: 1, access: read-only
  Indicates the platform is an ASIC
*/
volatile uint32_t PLATFORM;
} TBMAN_type;

#define TBMAN ((TBMAN_type *) 0x4006C000)

#endif // HW_TBMAN_H
