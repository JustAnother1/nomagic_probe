# Makefile for the nomagic probe firmware
# =======================================
#
# You can do a "make help" to see all the supported targets.
# The target chip specif stuff is handeled in the included target.mk file.

PROJECT = nomagic_probe

# tools
# =====
CP = arm-none-eabi-objcopy
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
SIZE = size
MKDIR_P = mkdir -p
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
DIS = $(CP) -S
OBJDUMP = arm-none-eabi-objdump
TST_CC = gcc
TST_LD = cc
GITREF = $(shell git describe --abbrev=40 --dirty --always --tags)

# configuration
# =============
# 
# Some firmware features can be anabled and disabled as needed for the different scenarios.
# they are listed here:
# - HAS_MSC = yes
#       USB Mass Storage Device Class enabled. This enables the thumb drive feature.
#
# - HAS_CLI = yes
#       Command line interface(CLI provides commands to directly controll the fimrware and to inspect he firmwares internal state.
#       Must be used in combination with either "HAS_DEBUG_UART = yes" or "HAS_DEBUG_CDC = yes" !
#
# - HAS_DEBUG_UART = yes
#       Command Line Interface (CLI) on UART pins.
#
# - HAS_DEBUG_CDC = yes
#       Command Line Interface(CLI) on the USB Communication Class Device (USB-Serial).
#
# - HAS_GDB_SERVER = yes
#       gdb-server interface.

BIN_FOLDER = bin/
SRC_FOLDER = src/

# default target is the RaspberryPi RP2040
ifndef TARGET
	TARGET = RP2040
endif


# remove ?  SOURCE_DIR = $(dir $(lastword $(MAKEFILE_LIST)))

ifeq ($(TARGET), DETECT)
	HAS_MSC = yes
	HAS_DEBUG_UART = no
	HAS_DEBUG_CDC = yes
	HAS_CLI = yes
	HAS_GDB_SERVER = no
	HAS_DETECT = yes
else
	HAS_MSC = yes
	HAS_DEBUG_UART = yes
	HAS_DEBUG_CDC = no
	HAS_CLI = yes
	HAS_GDB_SERVER = yes
	HAS_DETECT = no
endif


# ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
# ! ! ! ! ALL CONFIGURATION SETTINGS ARE ABOVE THIS LINE  ! ! ! !
# ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !


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

DDEFS += -DTARGET=$(TARGET)

# enable USB Mass Storage (Thumb Drive)
ifeq ($(HAS_MSC), yes)
	DDEFS += -DFEAT_USB_MSC
endif
# enable the command line interfae for testing
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

# enable the gdb-server
ifeq ($(HAS_DETECT), yes)
	DDEFS += -DFEAT_DETECT
endif


CFLAGS  = -c -ggdb3
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

LKR_SCRIPT = $(SRC_FOLDER)hal/RP2040.ld

LFLAGS  = -ffreestanding -nostdlib -nolibc -nodefaultlibs -nostartfiles -specs=nosys.specs -fno-builtin -fno-builtin-function
LFLAGS += -Wl,--gc-sections,-Map=$(BIN_FOLDER)$(PROJECT).map -g
LFLAGS += -fno-common -T$(LKR_SCRIPT)


# Files to compile
# ================

# file handling
ifeq ($(HAS_MSC), yes)
SRC += $(SRC_FOLDER)file/fake_mbr.c
SRC += $(SRC_FOLDER)file/fake_boot_sector.c
SRC += $(SRC_FOLDER)file/fake_fat.c
SRC += $(SRC_FOLDER)file/fake_root_folder.c
SRC += $(SRC_FOLDER)file/fake_text_files.c
SRC += $(SRC_FOLDER)file/fake_favicon.c
SRC += $(SRC_FOLDER)file/fake_fs.c
SRC += $(SRC_FOLDER)file/file_storage.c
SRC += $(SRC_FOLDER)file/file_system.c
endif

# gdb server
ifeq ($(HAS_GDB_SERVER), yes)
SRC += $(SRC_FOLDER)gdbserver/cmd_qsupported.c
SRC += $(SRC_FOLDER)gdbserver/cmd_qxfer.c
SRC += $(SRC_FOLDER)gdbserver/commands.c
SRC += $(SRC_FOLDER)gdbserver/gdbserver.c
SRC += $(SRC_FOLDER)gdbserver/util.c
endif

# Hardware abstraction layer
ifeq ($(HAS_DEBUG_UART), yes)
SRC += $(SRC_FOLDER)hal/debug_uart.c
endif
SRC += $(SRC_FOLDER)hal/startup.c
SRC += $(SRC_FOLDER)hal/hw_divider.c
SRC += $(SRC_FOLDER)hal/watchdog.c
SRC += $(SRC_FOLDER)hal/boot_rom.c
SRC += $(SRC_FOLDER)hal/flash.c
SRC += $(SRC_FOLDER)hal/qspi.c
SRC += $(SRC_FOLDER)hal/time_base.c

# command line interface (debug - UART0 / USB-CDC)
ifeq ($(HAS_CLI), yes)
SRC += $(SRC_FOLDER)cli/cli.c
SRC += $(SRC_FOLDER)cli/cli_memory.c
SRC += $(SRC_FOLDER)cli/cli_swd.c
SRC += $(SRC_FOLDER)cli/cli_sys.c
SRC += $(SRC_FOLDER)cli/cli_usb.c
endif

# functions usually available from standard libraries
SRC += $(SRC_FOLDER)lib/ctype.c
SRC += $(SRC_FOLDER)lib/atoi.c
SRC += $(SRC_FOLDER)lib/memcpy.c
SRC += $(SRC_FOLDER)lib/memmove.c
SRC += $(SRC_FOLDER)lib/memset.c
SRC += $(SRC_FOLDER)lib/printf.c
SRC += $(SRC_FOLDER)lib/strlen.c
SRC += $(SRC_FOLDER)lib/strncmp.c

# SWD
SRC += $(SRC_FOLDER)swd/result_queue.c
SRC += $(SRC_FOLDER)swd/swd_engine.c
SRC += $(SRC_FOLDER)swd/swd_protocol.c
SRC += $(SRC_FOLDER)swd/swd_packets.c
SRC += $(SRC_FOLDER)swd/swd_packet_bits.c
SRC += $(SRC_FOLDER)swd/swd_gpio.c

# USB driver
SRC += $(SRC_FOLDER)tinyusb/usb.c
SRC += $(SRC_FOLDER)tinyusb/usb_descriptors.c

# USB stack (tinyusb
SRC += $(SRC_FOLDER)tinyusb/src/tusb.c
SRC += $(SRC_FOLDER)tinyusb/src/device/usbd.c
SRC += $(SRC_FOLDER)tinyusb/src/device/usbd_control.c
SRC += $(SRC_FOLDER)tinyusb/src/common/tusb_fifo.c

# USB serial interface (CDC)
SRC += $(SRC_FOLDER)tinyusb/usb_cdc.c
SRC += $(SRC_FOLDER)tinyusb/src/class/cdc/cdc_device.c

# USB thumb drive (MSC)
ifeq ($(HAS_MSC), yes)
SRC += $(SRC_FOLDER)tinyusb/usb_msc.c
SRC += $(SRC_FOLDER)tinyusb/src/class/msc/msc_device.c
endif

# user feedback
SRC += $(SRC_FOLDER)led.c

# main
SRC += $(SRC_FOLDER)main.c

# files specific to the chip that will be debugged:
ifeq ($(TARGET), EXTERN)
    # target loader
    SRC += $(SRC_FOLDER)file/target_loader.c
else
	include target/target.mk
endif



OBJS = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

INCDIRS +=$(SRC_FOLDER)
INCDIRS +=$(SRC_FOLDER)cfg/
INCDIRS +=$(SRC_FOLDER)lib/
INCDIRS +=$(SRC_FOLDER)tinyusb/src/
INCDIR = $(patsubst %,-I%, $(INCDIRS))

# unit test configuration
# =======================

TST_LFLAGS = -lgcov --coverage
TST_CFLAGS =  -Wall -Wextra -g3 -fprofile-arcs -ftest-coverage -Wno-int-to-pointer-cast -Wno-implicit-function-declaration
TST_DDEFS = -DUNIT_TEST=1
TST_DDEFS += -DFEAT_DEBUG_UART
TST_INCDIRS = tests/
TST_INCDIRS += tests/cfg/
TST_INCDIRS += src/tinyusb/src/
TST_INCDIRS += /usr/include/
TST_INCDIRS += src/
TST_INCDIR = $(patsubst %,-I%, $(TST_INCDIRS))

# Files to compile for unit tests
# ===============================

TST_OBJS += tests/bin/src/cli/cli.o
TST_OBJS += tests/bin/src/lib/printf.o
TST_OBJS += tests/bin/src/tinyusb/usb_msc.o
TST_OBJS += tests/bin/src/gdbserver/cmd_qsupported.o
TST_OBJS += tests/bin/src/gdbserver/cmd_qxfer.o
TST_OBJS += tests/bin/src/gdbserver/commands.o
TST_OBJS += tests/bin/src/gdbserver/gdbserver.o
TST_OBJS += tests/bin/src/gdbserver/util.o
TST_OBJS += tests/bin/tests/cli_tests.o
TST_OBJS += tests/bin/tests/mocks.o
TST_OBJS += tests/bin/tests/printf_tests.o
TST_OBJS += tests/bin/tests/usb_msc_tests.o
TST_OBJS += tests/bin/tests/gdbserver_util_tests.o
TST_OBJS += tests/bin/tests/gdbserver_gdbserver_tests.o
TST_OBJS += tests/bin/tests/munit.o
TST_OBJS += tests/bin/tests/allTests.o


# make config
# remove ?  VPATH = $(SOURCE_DIR)
.DEFAULT_GOAL = all


# targets
# =======

help:
	@echo ""
	@echo "available targets"
	@echo "================="
	@echo "make clean              delete all generated files"
	@echo "make all TARGET=DETECT  compile firmware creates elf and uf2 file."
	@echo "                        (no target support, no gdb-server, detect serial interface)"
	@echo "make all TARGET=EXTERN  compile firmware creates elf and uf2 file."
	@echo "                        (target configuration needed)"
	@echo "make all                compile firmware creates elf and uf2 file."
	@echo "                        (only support RP2040 target)"
	@echo "make flash              write firmware to flash of RP2040"
	@echo "                        using openocd and CMSIS-DAP adapter(picoprobe)"
	@echo "make doc                run doxygen"
	@echo "make test               run unit tests"
	@echo "make lcov               create coverage report of unit tests"
	@echo "make list               create list file"
	@echo ""

$(BIN_FOLDER)$(PROJECT).elf: $(OBJS) $(LIBS)
	@echo ""
	@echo "linking"
	@echo "======="
	$(LD) $(LFLAGS) -o $(BIN_FOLDER)$(PROJECT).elf $(OBJS) $(LINK_LIBS)

%hex: %elf
	@echo ""
	@echo "elf->hex"
	@echo "========"
	$(HEX) $< $@

%bin: %elf
	@echo ""
	@echo "elf->bin"
	@echo "========"
	$(BIN) $< $@

%txt: %elf
	@echo ""
	@echo "disassemble"
	@echo "==========="
	$(DIS) $< $@ > $@

$(BIN_FOLDER)version.h:
	@echo ""
	@echo "create version.h"
	@echo "================"
	@echo -n "#define VERSION \"" > $(BIN_FOLDER)version.h
	@cat version.txt >> $(BIN_FOLDER)version.h
	@echo " $(GITREF)\"" >> $(BIN_FOLDER)version.h

flash: $(BIN_FOLDER)$(PROJECT).elf
	@echo ""
	@echo "flashing"
	@echo "========"
	openocd  -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "program $(BIN_FOLDER)$(PROJECT).elf verify reset exit"

$(BIN_FOLDER)$(PROJECT).uf2: $(BIN_FOLDER)$(PROJECT).elf
	@echo ""
	@echo "elf -> uf2"
	@echo "=========="
	elf2uf2 -f 0xe48bff56 -p 256 -i $(BIN_FOLDER)$(PROJECT).elf

all: $(BIN_FOLDER)$(PROJECT).uf2
	@echo ""
	@echo "size"
	@echo "===="
	$(SIZE) --format=GNU $(BIN_FOLDER)$(PROJECT).elf

	
$(BIN_FOLDER)%o: %c $(BIN_FOLDER)version.h
	@echo ""
	@echo "=== compiling $@"
	@$(MKDIR_P) $(@D)
	$(CC) -MD -MP -c $(CFLAGS) $(DDEFS) $(INCDIR) $< -o $@

list: $(BIN_FOLDER)$(PROJECT).elf
	@echo ""
	@echo "listing"
	@echo "========"
	@echo " READ -> $(BIN_FOLDER)$(PROJECT).rd"
	@arm-none-eabi-readelf -Wall $(BIN_FOLDER)$(PROJECT).elf > $(BIN_FOLDER)$(PROJECT).rd
	@echo " LIST -> $(BIN_FOLDER)$(PROJECT).lst"
	@$(OBJDUMP) -axdDSstr $(BIN_FOLDER)$(PROJECT).elf > $(BIN_FOLDER)$(PROJECT).lst

doc:
	@echo ""
	@echo "doxygen"
	@echo "========"
	doxygen

tests/bin/%o: %c
	@echo ""
	@echo "=== compiling (tests) $@"
	@$(MKDIR_P) $(@D)
	$(TST_CC) -c $(TST_CFLAGS) $(TST_DDEFS) $(TST_INCDIR) $< -o $@

$(PROJECT)_tests: $(TST_OBJS)
	@echo ""
	@echo "linking tests"
	@echo "============="
	$(TST_LD) $(TST_LFLAGS) -o tests/bin/$(PROJECT)_tests $(TST_OBJS)


test: $(PROJECT)_tests
	@echo ""
	@echo "executing tests"
	@echo "==============="
	tests/bin/$(PROJECT)_tests

lcov: 
	lcov --base-directory tests/ --directory tests/ -c -o tests/bin/lcov.info --exclude "*tests/*"
	genhtml -o test_coverage -t "coverage" --num-spaces 4 tests/bin/lcov.info -o tests/bin/test_coverage/


clean:
	@rm -rf $(BIN_FOLDER)/* tests/$(PROJECT)_tests tests/bin/ $(CLEAN_RM)

.PHONY: help clean flash all list test doc $(BIN_FOLDER)version.h

-include $(OBJS:.o=.d)
