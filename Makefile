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

BIN_FOLDER = bin/
SRC_FOLDER = src/

SOURCE_DIR = $(dir $(lastword $(MAKEFILE_LIST)))

LKR_SCRIPT = $(SRC_FOLDER)hal/RP2040.ld
#LKR_SCRIPT = $(SRC_FOLDER)hal/RP2040_RAM.ld

# tinyUSB logging has different levels 0 = no logging,1= some logging, 2 = more logging, 3= all logging
DDEFS += -DCFG_TUSB_DEBUG=1
# with this the watchdog is only active if the debugger is not connected
#DDEFS += -DDISABLE_WATCHDOG_FOR_DEBUG=1


CFLAGS  = -c -g3
CFLAGS += -O3
#CFLAGS += -O0
CFLAGS += -std=c17
CFLAGS += -mcpu=cortex-m0plus -mthumb
CFLAGS += -ffreestanding -funsigned-char -fno-short-enums
CFLAGS += -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wconversion 
# -Wpadded : tinyUSB creates warnings with this enabled. :-( 
CFLAGS += -ffunction-sections -fdata-sections

LFLAGS  = -ffreestanding -nostdlib -nolibc -nodefaultlibs -nostartfiles -specs=nosys.specs
LFLAGS += -Wl,--gc-sections,-Map=$(BIN_FOLDER)$(PROJECT).map -g
LFLAGS += -fno-common -T$(LKR_SCRIPT)


# Hardware abstraction layer
SRC += $(SRC_FOLDER)hal/debug_uart.c
SRC += $(SRC_FOLDER)hal/startup.c
SRC += $(SRC_FOLDER)hal/hw_divider.c
SRC += $(SRC_FOLDER)hal/watchdog.c
# command line interface (debug - UART0)
SRC += $(SRC_FOLDER)cli/cli.c
SRC += $(SRC_FOLDER)cli/cli_memory.c
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
# file handling
SRC += $(SRC_FOLDER)file/faked_disk.c
SRC += $(SRC_FOLDER)file/file_storage.c
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
SRC += $(SRC_FOLDER)tinyusb/usb_msc.c
SRC += $(SRC_FOLDER)tinyusb/src/class/msc/msc_device.c
# time base
SRC += $(SRC_FOLDER)time_base.c
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

# make config
VPATH = $(SOURCE_DIR)
.DEFAULT_GOAL = all


# targets

$(BIN_FOLDER)$(PROJECT).elf: $(OBJS)
	@echo ""
	@echo "linking"
	@echo "======="
	$(LD) $(LFLAGS) -o $(BIN_FOLDER)$(PROJECT).elf $(OBJS)

%hex: %elf
	$(HEX) $< $@

%bin: %elf
	$(BIN) $< $@

%txt: %elf
	$(DIS) $< $@ > $@

flash: $(BIN_FOLDER)$(PROJECT).elf
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
	$(SIZE) $(BIN_FOLDER)$(PROJECT).elf

	
$(BIN_FOLDER)%o: %c
	@echo "=== compiling $@"
	@$(MKDIR_P) $(@D)
	$(CC) -c $(CFLAGS) $(DDEFS) $(INCDIR) $< -o $@

list:
	@echo " READ -> $(BIN_FOLDER)$(PROJECT).rd"
	@arm-none-eabi-readelf -Wall $(BIN_FOLDER)$(PROJECT).elf > $(BIN_FOLDER)$(PROJECT).rd
	@echo " LIST -> $(BIN_FOLDER)$(PROJECT).lst"
	@$(OBJDUMP) -axdDSstr $(BIN_FOLDER)$(PROJECT).elf > $(BIN_FOLDER)$(PROJECT).lst
	#$(OBJDUMP) -h -S -z $< > $@

doc:
	doxygen

clean:
	@rm -rf $(BIN_FOLDER) app.map doc/doxygen/

.PHONY: clean flash all list

