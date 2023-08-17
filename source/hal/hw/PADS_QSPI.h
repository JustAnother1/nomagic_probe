#ifndef HW_PADS_QSPI_H
#define HW_PADS_QSPI_H
/** Memory Block starting at 0x40020000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>

typedef struct
{

/** VOLTAGE_SELECT (offset: 0x0)
  Voltage select. Per bank control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: VOLTAGE_SELECT
  offset: 0, size: 1, access: read-write
  Enum: 
  Value: 0 - 3v3 : Set voltage to 3.3V (DVDD &gt;= 2V5)
  Value: 1 - 1v8 : Set voltage to 1.8V (DVDD &lt;= 1V8)
*/
volatile uint32_t VOLTAGE_SELECT;

/** GPIO_QSPI_SCLK (offset: 0x4)
  Pad control register
  access : read-write
  reset value : 0x56
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum: 
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SCLK;

/** GPIO_QSPI_SD0 (offset: 0x8)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum: 
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD0;

/** GPIO_QSPI_SD1 (offset: 0xc)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum: 
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD1;

/** GPIO_QSPI_SD2 (offset: 0x10)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum: 
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD2;

/** GPIO_QSPI_SD3 (offset: 0x14)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum: 
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD3;

/** GPIO_QSPI_SS (offset: 0x18)
  Pad control register
  access : read-write
  reset value : 0x5A
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum: 
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SS;
} PADS_QSPI_type;

#define PADS_QSPI ((PADS_QSPI_type *) 0x40020000)

#endif // HW_PADS_QSPI_H
