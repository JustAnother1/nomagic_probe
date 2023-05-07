# automatically created Makefile
# created at: 2023-04-26 01:10:10
# created from blinky.xml

CC = arm-none-eabi-gcc
ASFLAGS = -g -Wall -gdwarf-2 -mthumb -mcpu=cortex-m0plus
SIZE = size
project = nomagic_probe
AS = arm-none-eabi-as
LKR_SCRIPT = hal/RP2040.ld
LFLAGS = -nostartfiles -Wl,-Map=app.map -g -T$(LKR_SCRIPT)
CFLAGS = -c -fno-common -ffreestanding -O3 -g -mcpu=cortex-m0plus -mthumb -I.
SOURCE_DIR = $(dir $(lastword $(MAKEFILE_LIST)))
OBJS =  hal/console_uart.o hal/startup.o main.o cli/cli.o
LD = arm-none-eabi-gcc
CPFLAGS = -Obinary
VPATH = $(SOURCE_DIR)
FILES_TO_CLEAN = app.map
.DEFAULT_GOAL = all

$(project).elf: $(OBJS)
	$(LD) $(LFLAGS) -o $(project).elf $(OBJS)

flash: $(project).elf
	openocd -f board/pico-debug.cfg -c "$(project).elf verify reset exit"

$(project).uf2: $(project).elf
	elf2uf2 -f 0xe48bff56 -p 256 -i $(project).elf

all: $(project).uf2
	@echo ""
	@echo "size"
	@echo "===="
	$(SIZE) $(project).elf

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(project).elf $(project).uf2 *.o hal/*.o cli/*.o app.map

.PHONY: clean flash all

