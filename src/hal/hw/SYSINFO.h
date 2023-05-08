#ifndef HW_SYSINFO_H
#define HW_SYSINFO_H
/* Memory Block starting at 0x40000000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>

typedef struct
{

/* CHIP_ID (offset: 0x0)
  JEDEC JEP-106 compliant chip identifier.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: REVISION
  offset: 28, size: 4, access: read-only
  Field: PART
  offset: 12, size: 16, access: read-only
  Field: MANUFACTURER
  offset: 0, size: 12, access: read-only
*/
volatile uint32_t CHIP_ID;

/* PLATFORM (offset: 0x4)
  Platform register. Allows software to know what environment it is running in.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ASIC
  offset: 1, size: 1, access: read-only
  Field: FPGA
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PLATFORM;
volatile uint32_t reserved0[14];

/* GITREF_RP2040 (offset: 0x40)
  Git hash of the chip source. Used to identify chip version.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t GITREF_RP2040;
} SYSINFO_type;

#define SYSINFO ((SYSINFO_type *) 0x40000000)

#endif // HW_SYSINFO_H
