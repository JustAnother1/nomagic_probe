# Makefile for the nomagic probe firmware
# =======================================
#
# You can do a "make help" to see all the supported targets.
# The target chip specific stuff is handeled in the included target.mk file.

PROJECT = nomagic_probe
PROBE_NAME = "no target "

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
CAT = cat

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
#       Must be used in combination with either "HAS_DEBUG_TCP_IP = yes", "HAS_DEBUG_UART = yes" or "HAS_DEBUG_CDC = yes" !
#
# - HAS_DEBUG_UART = yes
#       Command Line Interface (CLI) on UART pins.
#
# - HAS_DEBUG_CDC = yes
#       Command Line Interface(CLI) on the USB Communication Class Device (USB-Serial).
#
# - HAS_GDB_SERVER = yes
#       gdb-server interface.
#
# - HAS_NCM = yes
#       USB Network interface. Allows other interfaces to be available as TCP Ports.
#
# - HAS_DEBUG_TCP_IP = yes
#       Command Line Interface (CLI) on TCP Port. Can only be used with "HAS_NCM = yes".
#
# - USE_BOOT_ROM = yes
#       use the functions stored in the boot rom in the RP2040 to access the QSPI flash.

BIN_FOLDER = bin/
SRC_FOLDER = src/
NOMAGIC_FOLDER = nomagic_probe/


HAS_MSC = yes
HAS_DEBUG_UART = yes
HAS_DEBUG_CDC = no
HAS_CLI = yes
HAS_GDB_SERVER = yes
HAS_NCM = yes
USE_BOOT_ROM = no
HAS_DEBUG_TCP_IP = yes

# tinyUSB logging has different levels 0 = no logging,1 = some logging, 2 = more logging, 3= all logging
DDEFS += -DCFG_TUSB_DEBUG=1
# with this (=1)the watchdog is only active if the debugger is not connected
DDEFS += -DDISABLE_WATCHDOG_FOR_DEBUG=0
# use both cores
#DDEFS += -DENABLE_CORE_1=1
DDEFS += -DLWIP_DEBUG=1

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

LFLAGS  = -ffreestanding -nostartfiles
# disabled the following due to this issue:
#  undefined reference to `__gnu_thumb1_case_si'
LFLAGS += -nostdlib -nolibc -nodefaultlibs 
LFLAGS += -specs=nosys.specs
LFLAGS += -fno-builtin -fno-builtin-function
# https://wiki.osdev.org/Libgcc : All code compiled with GCC must be linked with libgcc. 
#LFLAGS += -lgcc
LFLAGS += -Wl,--gc-sections,-Map=$(BIN_FOLDER)$(PROJECT).map,--print-memory-usage -g
LFLAGS += -fno-common -T$(LKR_SCRIPT)

include nomagic_probe.mk
include tests/tests.mk

# files specific to the chip that will be debugged:
SRC += no_target/no.c

INCDIRS +=no_target/

# make config
.DEFAULT_GOAL = all


# targets
# =======

help:
	@echo "nomagic probe firmware"
	@echo "available targets"
	@echo "================="
	@echo "make clean              delete all generated files"
	@echo "make all                compile firmware creates elf and uf2 file."
	@echo "                        (only support for any target)"
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

$(BIN_FOLDER)%o: %c
	@echo ""
	@echo "=== compiling $@"
	@$(MKDIR_P) $(@D)
	$(CC) $(CFLAGS) $(DDEFS) $(INCDIR) $< -o $@

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
	firefox bin/doxygen/html/index.html

clean:
	@rm -rf $(BIN_FOLDER)/* tests/$(PROJECT)_tests tests/bin/ $(CLEAN_RM)

.PHONY: help clean flash all list test doc $(BIN_FOLDER)version.h

-include $(OBJS:.o=.d)
