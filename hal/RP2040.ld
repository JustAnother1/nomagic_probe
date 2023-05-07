ENTRY(Reset_Handler)
/* 2nd stage bootloader */
TARGET(binary)
INPUT("hal/2ndstage.bin")
OUTPUT_FORMAT(default)

MEMORY
{
    FLASH (rx) :ORIGIN = 0x10000000, LENGTH = 2048K
    RAM (xwr) :ORIGIN = 0x20000000, LENGTH = 264K
}
SECTIONS
{
.text 0x10000000 : {
    "hal/2ndstage.bin"
    KEEP (*(.vectors))
  } > FLASH
.text : {
    *(.text)
  } > FLASH
.data : {
    *(.data)
  } > FLASH
.bss (NOLOAD) : ALIGN(4) {
    __bss_start = .;
   *(.bss)
   *(COMMON)
   . = ALIGN(4);
    __bss_end = .;
  }> RAM
}
