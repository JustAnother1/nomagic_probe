# Makefile for the nomagic probe firmware
# =======================================
#
# You can do a "make help" to see all the supported targets.
# The target chip specific stuff is handeled in the included target.mk file.

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
#
# - HAS_NCM = yes
#       USB Network interface. Allows other interfaces to be available as TCP Ports.

BIN_FOLDER = bin/
SRC_FOLDER = src/
NOMAGIC_FOLDER = nomagic_probe/


HAS_MSC = yes
HAS_DEBUG_UART = yes
HAS_DEBUG_CDC = no
HAS_CLI = yes
HAS_GDB_SERVER = yes
HAS_NCM = yes

include nomagic_probe.mk

# files specific to the chip that will be debugged:
SRC += no_target/no.c

INCDIRS +=no_target/



# unit test configuration
# =======================

TST_LFLAGS = -lgcov --coverage
TST_CFLAGS =  -c -Wall -Wextra -g3 -fprofile-arcs -ftest-coverage -Wno-int-to-pointer-cast -Wno-implicit-function-declaration -Wno-format
TST_DDEFS = -DUNIT_TEST=1
TST_DDEFS += -DFEAT_DEBUG_UART
TST_INCDIRS = tests/
TST_INCDIRS += tests/cfg/
TST_INCDIRS += src/tinyusb/src/
TST_INCDIRS += /usr/include/
TST_INCDIRS += src/
TST_INCDIRS +=tests/bin/
TST_INCDIRS +=no_target/
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
TST_OBJS += tests/bin/tests/mock/serial_debug.o
TST_OBJS += tests/bin/tests/mock/serial_gdb.o

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

tests/bin/src/cli/cli.o: src/cli/cli.c
	@echo ""
	@echo "=== compiling (tests) $@"
	@$(MKDIR_P) $(@D)
	@echo "#define VERSION \"x.x.x\"" > tests/bin/version.h
	$(TST_CC) $(TST_CFLAGS) $(TST_DDEFS) $(TST_INCDIR) $< -o $@

tests/bin/%o: %c
	@echo ""
	@echo "=== compiling (tests) $@"
	@$(MKDIR_P) $(@D)
	$(TST_CC) $(TST_CFLAGS) $(TST_DDEFS) $(TST_INCDIR) $< -o $@

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
	lcov  --directory tests/ -c -o tests/bin/lcov.info --exclude "*tests/*" --exclude "*/usr/include/*" 
	genhtml -o test_coverage -t "coverage" --num-spaces 4 tests/bin/lcov.info -o tests/bin/test_coverage/


clean:
	@rm -rf $(BIN_FOLDER)/* tests/$(PROJECT)_tests tests/bin/ $(CLEAN_RM)

.PHONY: help clean flash all list test doc $(BIN_FOLDER)version.h

-include $(OBJS:.o=.d)
