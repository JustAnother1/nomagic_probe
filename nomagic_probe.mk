NOMAGIC_SRC_FOLDER = $(NOMAGIC_FOLDER)src/
GITREF = $(shell cd $(NOMAGIC_FOLDER) && git describe --abbrev=40 --dirty --always --tags)

# COMPILER SWITCHES
# =================
# These switches enable or disable functionality
# tinyUSB logging has different levels 0 = no logging,1 = some logging, 2 = more logging, 3= all logging
DDEFS += -DCFG_TUSB_DEBUG=1
# with this (=1)the watchdog is only active if the debugger is not connected
DDEFS += -DDISABLE_WATCHDOG_FOR_DEBUG=0
# use both cores
#DDEFS += -DENABLE_CORE_1=1
# use BOOT ROM (for flash functions,...)
DDEFS += -DBOOT_ROM_ENABLED=1

# enable USB Mass Storage (Thumb Drive)
ifeq ($(HAS_MSC), yes)
	DDEFS += -DFEAT_USB_MSC
endif
# enable the command line interface for testing
ifeq ($(HAS_DEBUG_UART), yes)
	DDEFS += -DFEAT_DEBUG_UART
endif

ifeq ($(HAS_DEBUG_CDC), yes)
	DDEFS += -DFEAT_DEBUG_CDC
endif
# enable the gdb-server
ifeq ($(HAS_GDB_SERVER), yes)
	DDEFS += -DFEAT_GDB_SERVER
endif

CFLAGS  = -c -ggdb3 -MMD -MP
CFLAGS += -O3
# sometimes helps with debugging:
# CFLAGS += -O0
# CFLAGS += -save-temps=obj

CFLAGS += -std=c17
CFLAGS += -mcpu=cortex-m0plus -mthumb
CFLAGS += -ffreestanding -funsigned-char
# -fno-short-enums
CFLAGS += -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wconversion 
# -Wpadded : tinyUSB creates warnings with this enabled. :-( 
CFLAGS += -ffunction-sections -fdata-sections

LKR_SCRIPT = $(NOMAGIC_SRC_FOLDER)hal/RP2040.ld

LFLAGS  = -ffreestanding -nostartfiles
# disabled the following due to this issue:
#  undefined reference to `__gnu_thumb1_case_si'
# LFLAGS += -nostdlib -nolibc -nodefaultlibs 
# LFLAGS += -specs=nosys.specs
# LFLAGS += -fno-builtin -fno-builtin-function
# https://wiki.osdev.org/Libgcc : All code compiled with GCC must be linked with libgcc. 
LFLAGS += -lgcc
LFLAGS += -Wl,--gc-sections,-Map=$(BIN_FOLDER)$(PROJECT).map -g
LFLAGS += -fno-common -T$(LKR_SCRIPT)


# Files to compile
# ================

# file handling
ifeq ($(HAS_MSC), yes)
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_mbr.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_boot_sector.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_fat.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_root_folder.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_text_files.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_favicon.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_fs.c
SRC += $(NOMAGIC_SRC_FOLDER)file/file_storage.c
SRC += $(NOMAGIC_SRC_FOLDER)file/file_system.c
endif

# gdb server
ifeq ($(HAS_GDB_SERVER), yes)
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/cmd_qsupported.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/cmd_qxfer.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/commands.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/gdbserver.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/replies.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/util.c
endif

# Hardware abstraction layer
ifeq ($(HAS_DEBUG_UART), yes)
SRC += $(NOMAGIC_SRC_FOLDER)hal/debug_uart.c
endif
SRC += $(NOMAGIC_SRC_FOLDER)hal/startup.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/hw_divider.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/watchdog.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/boot_rom.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/flash.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/qspi.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/time_base.c

# command line interface (debug - UART0 / USB-CDC)
ifeq ($(HAS_CLI), yes)
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_memory.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_swd.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_sys.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_usb.c
endif

# functions usually available from standard libraries
SRC += $(NOMAGIC_SRC_FOLDER)lib/ctype.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/atoi.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/memcpy.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/memmove.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/memset.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/printf.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/strchr.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/strlen.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/strncmp.c

# SWD
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_engine.c
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_protocol.c
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_packets.c
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_packet_bits.c
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_gpio.c

# USB driver
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb_descriptors.c

# USB stack (tinyusb
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/tusb.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/device/usbd.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/device/usbd_control.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/common/tusb_fifo.c

# USB serial interface (CDC)
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb_cdc.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/class/cdc/cdc_device.c

# USB thumb drive (MSC)
ifeq ($(HAS_MSC), yes)
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb_msc.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/class/msc/msc_device.c
endif

# target
SRC += $(NOMAGIC_SRC_FOLDER)target/common.c
SRC += $(NOMAGIC_SRC_FOLDER)target/common_actions.c
SRC += $(NOMAGIC_SRC_FOLDER)target/steps.c
SRC += $(NOMAGIC_SRC_FOLDER)target/cortex-m.c

# user feedback
SRC += $(NOMAGIC_SRC_FOLDER)led.c

# main
SRC += $(NOMAGIC_SRC_FOLDER)main.c

OBJS = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

INCDIRS +=$(NOMAGIC_SRC_FOLDER)
INCDIRS +=$(BIN_FOLDER)
INCDIRS +=$(NOMAGIC_SRC_FOLDER)cfg/
INCDIRS +=$(NOMAGIC_SRC_FOLDER)lib/
INCDIRS +=$(NOMAGIC_SRC_FOLDER)tinyusb/src/
INCDIR = $(patsubst %,-I%, $(INCDIRS))


$(BIN_FOLDER)version.h:
	@echo ""
	@echo "create version.h"
	@echo "================"
	@echo -n "#define VERSION \"" > $(BIN_FOLDER)version.h
	@cat $(NOMAGIC_FOLDER)version.txt >> $(BIN_FOLDER)version.h
	@echo " $(GITREF)\"" >> $(BIN_FOLDER)version.h

$(BIN_FOLDER)$(NOMAGIC_SRC_FOLDER)cli/cli.o: $(NOMAGIC_SRC_FOLDER)cli/cli.c $(BIN_FOLDER)version.h
	@echo ""
	@echo "=== compiling $@"
	@$(MKDIR_P) $(@D)
	$(CC) $(CFLAGS) $(DDEFS) $(INCDIR) $< -o $@
