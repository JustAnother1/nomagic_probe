/* https://blog.thea.codes/the-most-thoroughly-commented-linker-script/ */
ENTRY(Reset_Handler)
/* 2nd stage bootloader */
TARGET(binary)
INPUT("nomagic_probe/src/hal/2ndstage.bin")
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
        "nomagic_probe/src/hal/2ndstage.bin"
        KEEP (*(.vectors))
    } > FLASH

/* executeable code for boot functions*/
    .third_stage_boot : {
        . = ALIGN(4);
        __third_boot_start = .;
        
        *(.third_stage_boot .third_stage_boot.*)
        
        . = ALIGN(4);
        __third_boot_end = .;
    } > FLASH

/* executeable code for functions*/
    .code : {
        . = ALIGN(4);
        __code_start = .;
        
        *(.text)
        *(.text.*)
        
        . = ALIGN(4);
        __code_end = .;
    }  >RAM AT> FLASH

    /* used by the startup to copy code */
    __code_in_flash = LOADADDR(.code);

/* read only data (const,..) */
    .rodata : {
        . = ALIGN(4);
        __ro_data_start = .;
        
        *(.rodata)
        *(.rodata.*)
        
        . = ALIGN(4);
        __ro_data_end = .;
    } >RAM AT> FLASH

    /* used by the startup to copy rodata */
    __ro_data_in_flash = LOADADDR(.rodata);

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
