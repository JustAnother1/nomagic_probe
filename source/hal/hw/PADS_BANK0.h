#ifndef HW_PADS_BANK0_H
#define HW_PADS_BANK0_H
/** Memory Block starting at 0x4001C000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

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

/** GPIO0 (offset: 0x4)
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
volatile uint32_t GPIO0;

/** GPIO1 (offset: 0x8)
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
volatile uint32_t GPIO1;

/** GPIO2 (offset: 0xc)
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
volatile uint32_t GPIO2;

/** GPIO3 (offset: 0x10)
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
volatile uint32_t GPIO3;

/** GPIO4 (offset: 0x14)
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
volatile uint32_t GPIO4;

/** GPIO5 (offset: 0x18)
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
volatile uint32_t GPIO5;

/** GPIO6 (offset: 0x1c)
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
volatile uint32_t GPIO6;

/** GPIO7 (offset: 0x20)
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
volatile uint32_t GPIO7;

/** GPIO8 (offset: 0x24)
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
volatile uint32_t GPIO8;

/** GPIO9 (offset: 0x28)
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
volatile uint32_t GPIO9;

/** GPIO10 (offset: 0x2c)
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
volatile uint32_t GPIO10;

/** GPIO11 (offset: 0x30)
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
volatile uint32_t GPIO11;

/** GPIO12 (offset: 0x34)
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
volatile uint32_t GPIO12;

/** GPIO13 (offset: 0x38)
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
volatile uint32_t GPIO13;

/** GPIO14 (offset: 0x3c)
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
volatile uint32_t GPIO14;

/** GPIO15 (offset: 0x40)
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
volatile uint32_t GPIO15;

/** GPIO16 (offset: 0x44)
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
volatile uint32_t GPIO16;

/** GPIO17 (offset: 0x48)
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
volatile uint32_t GPIO17;

/** GPIO18 (offset: 0x4c)
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
volatile uint32_t GPIO18;

/** GPIO19 (offset: 0x50)
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
volatile uint32_t GPIO19;

/** GPIO20 (offset: 0x54)
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
volatile uint32_t GPIO20;

/** GPIO21 (offset: 0x58)
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
volatile uint32_t GPIO21;

/** GPIO22 (offset: 0x5c)
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
volatile uint32_t GPIO22;

/** GPIO23 (offset: 0x60)
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
volatile uint32_t GPIO23;

/** GPIO24 (offset: 0x64)
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
volatile uint32_t GPIO24;

/** GPIO25 (offset: 0x68)
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
volatile uint32_t GPIO25;

/** GPIO26 (offset: 0x6c)
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
volatile uint32_t GPIO26;

/** GPIO27 (offset: 0x70)
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
volatile uint32_t GPIO27;

/** GPIO28 (offset: 0x74)
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
volatile uint32_t GPIO28;

/** GPIO29 (offset: 0x78)
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
volatile uint32_t GPIO29;

/** SWCLK (offset: 0x7c)
  Pad control register
  access : read-write
  reset value : 0xDA
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
volatile uint32_t SWCLK;

/** SWD (offset: 0x80)
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
volatile uint32_t SWD;
} PADS_BANK0_type;

#define PADS_BANK0 ((PADS_BANK0_type *) 0x4001C000)

#endif // HW_PADS_BANK0_H
