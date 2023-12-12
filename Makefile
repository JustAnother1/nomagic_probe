PROJECT = nomagic_probe

# tools
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

BIN_FOLDER = bin/
SRC_FOLDER = src/

SOURCE_DIR = $(dir $(lastword $(MAKEFILE_LIST)))

ifeq ($(TARGET),EXTERN)
	# can be configured for each supported target
	DDEFS += -DFEAT_USB_MSC
else
	# nomagic probe will debug only the RP2040
	DDEFS += -DTARGET_RP2040
endif


LKR_SCRIPT = $(SRC_FOLDER)hal/RP2040.ld

# COMPILER SWITCHES
# =================
# These switches enable or disable functionality
# tinyUSB logging has different levels 0 = no logging,1 = some logging, 2 = more logging, 3= all logging
DDEFS += -DCFG_TUSB_DEBUG=1
# with this the watchdog is only active if the debugger is not connected
DDEFS += -DDISABLE_WATCHDOG_FOR_DEBUG=1
# use both cores
#DDEFS += -DENABLE_CORE_1=1
# use BOOT ROM (for flash functions,...)
DDEFS += -DBOOT_ROM_ENABLED=1

CFLAGS  = -c -ggdb3

CFLAGS += -O3
# sometimes helps with debugging:
# CFLAGS += -O0
#CFLAGS += -save-temps=obj

CFLAGS += -std=c17
CFLAGS += -mcpu=cortex-m0plus -mthumb
CFLAGS += -ffreestanding -funsigned-char -fno-short-enums
CFLAGS += -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wconversion 
# -Wpadded : tinyUSB creates warnings with this enabled. :-( 
CFLAGS += -ffunction-sections -fdata-sections

LFLAGS  = -ffreestanding -nostdlib -nolibc -nodefaultlibs -nostartfiles -specs=nosys.specs
LFLAGS += -Wl,--gc-sections,-Map=$(BIN_FOLDER)$(PROJECT).map -g
LFLAGS += -fno-common -T$(LKR_SCRIPT)

#swd
SRC += $(SRC_FOLDER)swd/swd_protocol.c
SRC += $(SRC_FOLDER)swd/swd_packets.c
SRC += $(SRC_FOLDER)swd/swd_gpio.c
#gdb server
SRC += $(SRC_FOLDER)gdbserver/cmd_qsupported.c
SRC += $(SRC_FOLDER)gdbserver/commands.c
SRC += $(SRC_FOLDER)gdbserver/gdbserver.c
SRC += $(SRC_FOLDER)gdbserver/util.c
# Hardware abstraction layer
SRC += $(SRC_FOLDER)hal/debug_uart.c
SRC += $(SRC_FOLDER)hal/startup.c
SRC += $(SRC_FOLDER)hal/hw_divider.c
SRC += $(SRC_FOLDER)hal/watchdog.c
SRC += $(SRC_FOLDER)hal/boot_rom.c
SRC += $(SRC_FOLDER)hal/flash.c
SRC += $(SRC_FOLDER)hal/qspi.c
SRC += $(SRC_FOLDER)hal/time_base.c
# command line interface (debug - UART0)
SRC += $(SRC_FOLDER)cli/cli.c
SRC += $(SRC_FOLDER)cli/cli_memory.c
SRC += $(SRC_FOLDER)cli/cli_swd.c
SRC += $(SRC_FOLDER)cli/cli_sys.c
SRC += $(SRC_FOLDER)cli/cli_usb.c
# functions usually available from standard libraries
SRC += $(SRC_FOLDER)lib/ctype.c
SRC += $(SRC_FOLDER)lib/atoi.c
SRC += $(SRC_FOLDER)lib/memcpy.c
SRC += $(SRC_FOLDER)lib/memmove.c
SRC += $(SRC_FOLDER)lib/memset.c
SRC += $(SRC_FOLDER)lib/printf.c
SRC += $(SRC_FOLDER)lib/strlen.c
SRC += $(SRC_FOLDER)lib/strncmp.c
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
# user feedback
SRC += $(SRC_FOLDER)led.c
# main
SRC += $(SRC_FOLDER)main.c



OBJS = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

INCDIRS +=$(SRC_FOLDER)
INCDIRS +=$(SRC_FOLDER)cfg/
INCDIRS +=$(SRC_FOLDER)lib/
INCDIRS +=$(SRC_FOLDER)tinyusb/src/
INCDIR = $(patsubst %,-I%, $(INCDIRS))

# test configuration

TST_LFLAGS = -lgcov --coverage
TST_CFLAGS =  -Wall -Wextra -g3 -fprofile-arcs -ftest-coverage -Wno-int-to-pointer-cast
TST_DDEFS = -DUNIT_TEST=1
TST_INCDIRS = tests/
TST_INCDIRS += tests/cfg/
TST_INCDIRS += src/
TST_INCDIRS += src/tinyusb/src/
TST_INCDIRS += /usr/include/
TST_INCDIR = $(patsubst %,-I%, $(TST_INCDIRS))
TST_OBJS += tests/bin/src/cli/cli.o
TST_OBJS += tests/bin/src/lib/printf.o
TST_OBJS += tests/bin/src/tinyusb/usb_msc.o
TST_OBJS += tests/bin/tests/cli_tests.o
TST_OBJS += tests/bin/tests/mocks.o
TST_OBJS += tests/bin/tests/printf_tests.o
TST_OBJS += tests/bin/tests/usb_msc_tests.o
TST_OBJS += tests/bin/tests/munit.o
TST_OBJS += tests/bin/tests/allTests.o

# make config
VPATH = $(SOURCE_DIR)
.DEFAULT_GOAL = all

ifeq ($(TARGET), EXTERN)
    # file handling
    SRC += $(SRC_FOLDER)file/fake_mbr.c
    SRC += $(SRC_FOLDER)file/fake_boot_sector.c
    SRC += $(SRC_FOLDER)file/fake_fat.c
    SRC += $(SRC_FOLDER)file/fake_root_folder.c
    SRC += $(SRC_FOLDER)file/fake_text_files.c
    SRC += $(SRC_FOLDER)file/fake_favicon.c
    SRC += $(SRC_FOLDER)file/fake_fs.c
    SRC += $(SRC_FOLDER)file/file_storage.c
    SRC += $(SRC_FOLDER)file/file_system.c
    # USB thumb drive (MSC)
    SRC += $(SRC_FOLDER)tinyusb/usb_msc.c
    SRC += $(SRC_FOLDER)tinyusb/src/class/msc/msc_device.c
    # target loader
    SRC += $(SRC_FOLDER)file/target_loader.c
else
	include $(SRC_FOLDER)target/target.mk
endif



# targets

help:
	@echo ""
	@echo "available targets"
	@echo "================="
	@echo "make clean              delete all generated files"
	@echo "make all TARGET=EXTERN  compile firmware creates elf and uf2 file. (target configuration needed)"
	@echo "make all                compile firmware creates elf and uf2 file. (only support RP2040 target)"
	@echo "make flash              write firmware to flash of RP2040 using openocd and CMSIS-DAP adapter(picoprobe)"
	@echo "make doc                run doxygen"
	@echo "make test               run unit tests"
	@echo "make lcov               create coverage report of unit tests"
	@echo "make list               create list file"
	@echo ""

$(BIN_FOLDER)$(PROJECT).elf: $(OBJS)
	@echo ""
	@echo "linking"
	@echo "======="
	$(LD) $(LFLAGS) -o $(BIN_FOLDER)$(PROJECT).elf $(OBJS)

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
	@echo "=== compiling $@"
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
	#--exclude "*cpputest/*"
	genhtml -o test_coverage -t "coverage" --num-spaces 4 tests/bin/lcov.info -o tests/bin/test_coverage/


clean:
	@rm -rf $(BIN_FOLDER) app.map doc/doxygen/ tests/$(PROJECT)_tests tests/bin/

.PHONY: help clean flash all list test doc

-include $(OBJS:.o=.d)
