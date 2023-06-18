/* https://blog.thea.codes/the-most-thoroughly-commented-linker-script/ */
ENTRY(Reset_Handler)
/* 2nd stage bootloader */
TARGET(binary)
INPUT("src/hal/2ndstage.bin")
OUTPUT_FORMAT(default)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x10000000, LENGTH = 2048K
    RAM (xwr)  : ORIGIN = 0x20000000, LENGTH =  264K
}

SECTIONS
{
/* second stage boot loader: (needed for ROM boot loader to work) */
  .text 0x10000000 : {
    "src/hal/2ndstage.bin"
    KEEP (*(.vectors))
  } > FLASH

/* executeable code for functions*/
  .text : {
    *(.text)
    *(.text.*)
  } > FLASH

/* read only data (const,..) */
  .rodata : {
    *(.rodata)
    *(.rodata.*)
  } > FLASH

/* initialized data */
  .data : {
    . = ALIGN(4);
    __data_start = .;
    
    *(.data)
    *(.data.*)
    
    . = ALIGN(4);
    __data_end = .;
  } >RAM AT> FLASH

  /* used by the startup to initialize data */
  __data_in_flash = LOADADDR(.data);

/* zero initialized variables */
  .bss (NOLOAD) : {
    . = ALIGN(4);
    __bss_start = .;
    
    *(.bss)
    *(.bss.*)
    *(COMMON)
    
    . = ALIGN(4);
    __bss_end = .;
  }> RAM

}
