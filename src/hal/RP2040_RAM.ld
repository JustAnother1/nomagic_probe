ENTRY(Reset_Handler)
/* 2nd stage bootloader */
TARGET(binary)
INPUT("src/hal/2ndstage.bin")
OUTPUT_FORMAT(default)

MEMORY
{
    RAM (xwr) :ORIGIN = 0x20000000, LENGTH = 264K
}
SECTIONS
{
.text : {
    KEEP (*(.vectors))
    *(.text)
} > RAM

.data : {
    *(.data)
} > RAM

.bss (NOLOAD) : ALIGN(4) {
    __bss_start = .;
    *(.bss)
    *(COMMON)
    . = ALIGN(4);
    __bss_end = .;
    _end = __bss_end;
    end = _end;
}> RAM
}
