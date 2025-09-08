ENTRY(Reset_Handler)
TARGET(binary)
INPUT("nomagic_probe/src/hal/2ndstage.bin")
OUTPUT_FORMAT(default)

MEMORY
{
    FLASH (xr) :ORIGIN = 0x10000000, LENGTH = 2048K
    RAM (xwr) :ORIGIN = 0x20000000, LENGTH = 264K
}

SECTIONS
{
.text 0x10000000 : {
        "nomagic_probe/src/hal/2ndstage.bin"
        KEEP (*(.vectors))
    } > FLASH
    
.third_stage_boot : {
        . = ALIGN(4);
        linker_third_boot_start = .;

        *(.third_stage_boot .third_stage_boot.*)

        . = ALIGN(4);
        linker_third_boot_end = .;
    } > FLASH
    
.code : {
        . = ALIGN(4);
        linker_code_start = .;

        *(.text)
        *(.text.*)
        *(.time_critical.*)

        . = ALIGN(4);
        linker_code_end = .;
    }  >RAM AT> FLASH

    /* used by the startup to copy code */
    linker_code_in_flash = LOADADDR(.code);
    
.rodata : {
        . = ALIGN(4);
        linker_ro_data_start = .;

        *(.rodata)
        *(.rodata.*)

        . = ALIGN(4);
        linker_ro_data_end = .;
    } >RAM AT> FLASH

    /* used by the startup to copy rodata */
    linker_ro_data_in_flash = LOADADDR(.rodata);
    
.data : {
    . = ALIGN(4);
    linker_data_start = .;

    *(.data)
    *(.data.*)

    . = ALIGN(4);
    linker_data_end = .;
} >RAM AT> FLASH
/* used by the startup to initialize data */
linker_data_in_flash = LOADADDR(.data);

.bss (NOLOAD) : {
    linker_bss_start = .;
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN(4);
    linker_bss_end = .;
    _end = linker_bss_end;
    end = _end;
}> RAM

}

