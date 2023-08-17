################################################################################
#                                 DASHBOARD.MK                                 #
################################################################################
# COPYRIGHT (c) 2020 Embeetle                                                  #
# This software component is licensed by Embeetle under the MIT license. Con-  #
# sult the license text at the bottom of this file.                            #
#                                                                              #
#------------------------------------------------------------------------------#
#                                   SUMMARY                                    #
#------------------------------------------------------------------------------#
# This file is intended to be included in the makefile. It contains all        #
# variables that depend on dashboard settings in Embeetle.                     #
#                                                                              #
# We suggest to include this file in your makefile like so:                    #
#                                                                              #
#     MAKEFILE := $(lastword $(MAKEFILE_LIST))                                 #
#     MAKEFILE_DIR := $(dir $(MAKEFILE))                                       #
#     include $(MAKEFILE_DIR)dashboard.mk                                      #
#                                                                              #
#------------------------------------------------------------------------------#
#                                    EDITS                                     #
#------------------------------------------------------------------------------#
# This file was automatically generated, but feel free to edit. When you chan- #
# ge something in the dashboard, Embeetle will ask your permission to modify   #
# this file accordingly. You'll be shown a proposal for a 3-way-merge in a     #
# diffing window. In other words, your manual edits won't be lost.             #
#                                                                              #
#------------------------------------------------------------------------------#
#                               MORE INFORMATION                               #
#------------------------------------------------------------------------------#
# Consult the Embeetle website for more info about this file:                  #
# https://embeetle.com/#embeetle-ide/manual/beetle-anatomy/dashboard           #
#                                                                              #
################################################################################

# 1. VERSION
# ==========
# Define the makefile interface version this 'dashboard.mk' file must be com-
# patible with.
EMBEETLE_MAKEFILE_INTERFACE_VERSION = 7

# 2. TOOLS
# ========
# When invoking the makefile, Embeetle passes absolute paths to the toolchain
# (ARM, RISCV, ...) and the flash tool (OpenOCD, esptool, ...) on the command-
# line.
# Example:
#
#   > "TOOLPREFIX=C:/my_tools/gnu_arm_toolchain_9.2.1/bin/arm-none-eabi-"
#   > "FLASHTOOL=C:/my_tools/openocd_0.10.0_dev01138_32b/bin/openocd.exe"
#
# If you ever invoke the makefile without these commandline-arguments,
# you need a fallback mechanism. Therefore, we provide a default value
# for these variables here. Read more about the reasons in ADDENDUM 2.
TOOLPREFIX = arm-none-eabi-
FLASHTOOL = openocd

# 3. PROJECT LAYOUT
# =================
# The PROJECT LAYOUT section in the dashboard points to all important config
# file locations (eg. linkerscript, openocd config files, ...). If you change
# any of those locations in the dashboard, Embeetle changes the variables be-
# low accordingly.
#
# NOTES:
#     - These paths are all relative to the build directory.
#     - Locations of 'dashboard.mk' and 'filetree.mk' are not
#       defined here. That's because they're always located in
#       the same folder with the makefile.
SOURCE_DIR = ../
BIN_FILE = application.bin
ELF_FILE = application.elf
LINKERSCRIPT = ../config/linkerscript.ld
OPENOCD_CHIPFILE = ../config/openocd_chip.cfg
OPENOCD_PROBEFILE = ../config/openocd_probe.cfg

# 4. BINARIES
# ===========
# Define the binaries that must be built.
BINARIES = \
  $(ELF_FILE) \
  $(ELF_FILE:.elf=.bin) \
  $(ELF_FILE:.elf=.hex)

# Define the rules to build these binaries from the .elf file.
%.bin: %.elf
	$(info )
	$(info )
	$(info Preparing: $@)
	$(OBJCOPY) -O binary $< $@

%.hex: %.elf
	$(info )
	$(info )
	$(info Preparing: $@)
	$(OBJCOPY) -O ihex $< $@

# 5. COMPILATION FLAGS
# ====================
# CPU specific flags for C++, C and assembly compilation and linking.
TARGET_COMMONFLAGS = -mcpu=cortex-m0plus \
                     -mfloat-abi=soft \
                     -mthumb \
                     -DNDEBUG \
                     -DLIB_PICO_BIT_OPS=1 \
                     -DLIB_PICO_BIT_OPS_PICO=1 \
                     -DLIB_PICO_DIVIDER=1 \
                     -DLIB_PICO_DIVIDER_HARDWARE=1 \
                     -DLIB_PICO_DOUBLE=1 \
                     -DLIB_PICO_DOUBLE_PICO=1 \
                     -DLIB_PICO_FLOAT=1 \
                     -DLIB_PICO_FLOAT_PICO=1 \
                     -DLIB_PICO_INT64_OPS=1 \
                     -DLIB_PICO_INT64_OPS_PICO=1 \
                     -DLIB_PICO_MALLOC=1 \
                     -DLIB_PICO_MEM_OPS=1 \
                     -DLIB_PICO_MEM_OPS_PICO=1 \
                     -DLIB_PICO_PLATFORM=1 \
                     -DLIB_PICO_PRINTF=1 \
                     -DLIB_PICO_PRINTF_PICO=1 \
                     -DLIB_PICO_RUNTIME=1 \
                     -DLIB_PICO_STANDARD_LINK=1 \
                     -DLIB_PICO_STDIO=1 \
                     -DLIB_PICO_STDIO_UART=1 \
                     -DLIB_PICO_STDLIB=1 \
                     -DLIB_PICO_SYNC=1 \
                     -DLIB_PICO_SYNC_CORE=1 \
                     -DLIB_PICO_SYNC_CRITICAL_SECTION=1 \
                     -DLIB_PICO_SYNC_MUTEX=1 \
                     -DLIB_PICO_SYNC_SEM=1 \
                     -DLIB_PICO_TIME=1 \
                     -DLIB_PICO_UTIL=1 \
                     -DPICO_BOARD=\"pico\" \
                     -DPICO_BUILD=1 \
                     -DPICO_CMAKE_BUILD_TYPE=\"Release\" \
                     -DPICO_COPY_TO_RAM=0 \
                     -DPICO_CXX_ENABLE_EXCEPTIONS=0 \
                     -DPICO_NO_FLASH=0 \
                     -DPICO_NO_HARDWARE=0 \
                     -DPICO_ON_DEVICE=1 \
                     -DPICO_PROGRAM_URL=\"https://github.com/raspberrypi/pico-examples/tree/HEAD/blink\" \
                     -DPICO_TARGET_NAME=\"blink\" \
                     -DPICO_USE_BLOCKED_RAM=0 \

# CPU specific C compilation flags
TARGET_CFLAGS = -std=gnu11 \

# CPU specific C++ compilation flags
TARGET_CXXFLAGS = -fno-exceptions \
                  -fno-unwind-tables \
                  -fno-rtti \
                  -fno-use-cxa-atexit \
                  -std=gnu++17 \

# CPU specific assembler flags
TARGET_SFLAGS = 

# CPU specific linker flags
TARGET_LDFLAGS = --specs=nosys.specs \
                 -Wl,--build-id=none \
                 -Wl,--wrap=sprintf \
                 -Wl,--wrap=snprintf \
                 -Wl,--wrap=vsnprintf \
                 -Wl,--wrap=__clzsi2 \
                 -Wl,--wrap=__clzdi2 \
                 -Wl,--wrap=__ctzsi2 \
                 -Wl,--wrap=__ctzdi2 \
                 -Wl,--wrap=__popcountsi2 \
                 -Wl,--wrap=__popcountdi2 \
                 -Wl,--wrap=__clz \
                 -Wl,--wrap=__clzl \
                 -Wl,--wrap=__clzll \
                 -Wl,--wrap=__aeabi_idiv \
                 -Wl,--wrap=__aeabi_idivmod \
                 -Wl,--wrap=__aeabi_ldivmod \
                 -Wl,--wrap=__aeabi_uidiv \
                 -Wl,--wrap=__aeabi_uidivmod \
                 -Wl,--wrap=__aeabi_uldivmod \
                 -Wl,--wrap=__aeabi_dadd \
                 -Wl,--wrap=__aeabi_ddiv \
                 -Wl,--wrap=__aeabi_dmul \
                 -Wl,--wrap=__aeabi_drsub \
                 -Wl,--wrap=__aeabi_dsub \
                 -Wl,--wrap=__aeabi_cdcmpeq \
                 -Wl,--wrap=__aeabi_cdrcmple \
                 -Wl,--wrap=__aeabi_cdcmple \
                 -Wl,--wrap=__aeabi_dcmpeq \
                 -Wl,--wrap=__aeabi_dcmplt \
                 -Wl,--wrap=__aeabi_dcmple \
                 -Wl,--wrap=__aeabi_dcmpge \
                 -Wl,--wrap=__aeabi_dcmpgt \
                 -Wl,--wrap=__aeabi_dcmpun \
                 -Wl,--wrap=__aeabi_i2d \
                 -Wl,--wrap=__aeabi_l2d \
                 -Wl,--wrap=__aeabi_ui2d \
                 -Wl,--wrap=__aeabi_ul2d \
                 -Wl,--wrap=__aeabi_d2iz \
                 -Wl,--wrap=__aeabi_d2lz \
                 -Wl,--wrap=__aeabi_d2uiz \
                 -Wl,--wrap=__aeabi_d2ulz \
                 -Wl,--wrap=__aeabi_d2f \
                 -Wl,--wrap=sqrt \
                 -Wl,--wrap=cos \
                 -Wl,--wrap=sin \
                 -Wl,--wrap=tan \
                 -Wl,--wrap=atan2 \
                 -Wl,--wrap=exp \
                 -Wl,--wrap=log \
                 -Wl,--wrap=ldexp \
                 -Wl,--wrap=copysign \
                 -Wl,--wrap=trunc \
                 -Wl,--wrap=floor \
                 -Wl,--wrap=ceil \
                 -Wl,--wrap=round \
                 -Wl,--wrap=sincos \
                 -Wl,--wrap=asin \
                 -Wl,--wrap=acos \
                 -Wl,--wrap=atan \
                 -Wl,--wrap=sinh \
                 -Wl,--wrap=cosh \
                 -Wl,--wrap=tanh \
                 -Wl,--wrap=asinh \
                 -Wl,--wrap=acosh \
                 -Wl,--wrap=atanh \
                 -Wl,--wrap=exp2 \
                 -Wl,--wrap=log2 \
                 -Wl,--wrap=exp10 \
                 -Wl,--wrap=log10 \
                 -Wl,--wrap=pow \
                 -Wl,--wrap=powint \
                 -Wl,--wrap=hypot \
                 -Wl,--wrap=cbrt \
                 -Wl,--wrap=fmod \
                 -Wl,--wrap=drem \
                 -Wl,--wrap=remainder \
                 -Wl,--wrap=remquo \
                 -Wl,--wrap=expm1 \
                 -Wl,--wrap=log1p \
                 -Wl,--wrap=fma \
                 -Wl,--wrap=__aeabi_lmul \
                 -Wl,--wrap=__aeabi_fadd \
                 -Wl,--wrap=__aeabi_fdiv \
                 -Wl,--wrap=__aeabi_fmul \
                 -Wl,--wrap=__aeabi_frsub \
                 -Wl,--wrap=__aeabi_fsub \
                 -Wl,--wrap=__aeabi_cfcmpeq \
                 -Wl,--wrap=__aeabi_cfrcmple \
                 -Wl,--wrap=__aeabi_cfcmple \
                 -Wl,--wrap=__aeabi_fcmpeq \
                 -Wl,--wrap=__aeabi_fcmplt \
                 -Wl,--wrap=__aeabi_fcmple \
                 -Wl,--wrap=__aeabi_fcmpge \
                 -Wl,--wrap=__aeabi_fcmpgt \
                 -Wl,--wrap=__aeabi_fcmpun \
                 -Wl,--wrap=__aeabi_i2f \
                 -Wl,--wrap=__aeabi_l2f \
                 -Wl,--wrap=__aeabi_ui2f \
                 -Wl,--wrap=__aeabi_ul2f \
                 -Wl,--wrap=__aeabi_f2iz \
                 -Wl,--wrap=__aeabi_f2lz \
                 -Wl,--wrap=__aeabi_f2uiz \
                 -Wl,--wrap=__aeabi_f2ulz \
                 -Wl,--wrap=__aeabi_f2d \
                 -Wl,--wrap=sqrtf \
                 -Wl,--wrap=cosf \
                 -Wl,--wrap=sinf \
                 -Wl,--wrap=tanf \
                 -Wl,--wrap=atan2f \
                 -Wl,--wrap=expf \
                 -Wl,--wrap=logf \
                 -Wl,--wrap=ldexpf \
                 -Wl,--wrap=copysignf \
                 -Wl,--wrap=truncf \
                 -Wl,--wrap=floorf \
                 -Wl,--wrap=ceilf \
                 -Wl,--wrap=roundf \
                 -Wl,--wrap=sincosf \
                 -Wl,--wrap=asinf \
                 -Wl,--wrap=acosf \
                 -Wl,--wrap=atanf \
                 -Wl,--wrap=sinhf \
                 -Wl,--wrap=coshf \
                 -Wl,--wrap=tanhf \
                 -Wl,--wrap=asinhf \
                 -Wl,--wrap=acoshf \
                 -Wl,--wrap=atanhf \
                 -Wl,--wrap=exp2f \
                 -Wl,--wrap=log2f \
                 -Wl,--wrap=exp10f \
                 -Wl,--wrap=log10f \
                 -Wl,--wrap=powf \
                 -Wl,--wrap=powintf \
                 -Wl,--wrap=hypotf \
                 -Wl,--wrap=cbrtf \
                 -Wl,--wrap=fmodf \
                 -Wl,--wrap=dremf \
                 -Wl,--wrap=remainderf \
                 -Wl,--wrap=remquof \
                 -Wl,--wrap=expm1f \
                 -Wl,--wrap=log1pf \
                 -Wl,--wrap=fmaf \
                 -Wl,--wrap=malloc \
                 -Wl,--wrap=calloc \
                 -Wl,--wrap=free \
                 -Wl,--wrap=memcpy \
                 -Wl,--wrap=memset \
                 -Wl,--wrap=__aeabi_memcpy \
                 -Wl,--wrap=__aeabi_memset \
                 -Wl,--wrap=__aeabi_memcpy4 \
                 -Wl,--wrap=__aeabi_memset4 \
                 -Wl,--wrap=__aeabi_memcpy8 \
                 -Wl,--wrap=__aeabi_memset8 \
                 -Wl,-z,max-page-size=4096 \
                 -Wl,--wrap=printf \
                 -Wl,--wrap=vprintf \
                 -Wl,--wrap=puts \
                 -Wl,--wrap=putchar \
                 -Wl,--wrap=getchar \
                 -T $(LINKERSCRIPT) \
                 -L $(dir $(LINKERSCRIPT)) \

# Libraries from the toolchain
TOOLCHAIN_LDLIBS = 

# 6. FLASH RULES
# ==============
# The 'flash' target flashes the binary to the target microcontroller. To
# achieve this, it invokes the OpenOCD tool:
.PHONY: flash
flash: $(BINARIES) print_flash
	"$(FLASHTOOL)" -f $(OPENOCD_PROBEFILE) \
               -f $(OPENOCD_CHIPFILE) \
               -c "program {$(ELF_FILE)} verify reset; shutdown;"

# Let's figure out what the flags mean:
#
#   -f: Specify a config file for OpenOCD to use. We pass this flag
#       twice: once for the config file that defines the probe and
#       once to define the chip (microcontroller).
#
#   -c: Run the specified commands. The ones we pass are:
#         1) program {file} verify reset;
#            Upload the firmware to the flash memory and verify
#            if it was successful.
#         2) shutdown;
#            Quit OpenOCD.


# ADDENDUM 1. MIT LICENSE
# =======================
# Copyright (c) 2020 Embeetle
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is furn-
# ished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# ADDENDUM 2. WHY THE FALLBACK MECHANISM FOR TOOLS?
# =================================================
# You might wonder: why bother with a default value? Embeetle could simply
# insert the actual paths (as selected in the dashboard) here, like:
#
# TOOLPREFIX = C:/my_tools/gnu_arm_toolchain_9.2.1/bin/arm-none-eabi-
# FLASHTOOL  = C:/my_tools/openocd_0.10.0_dev01138_32b/bin/openocd.exe
#
# However, that would make this dashboard.mk file location dependent: the
# location of the tool would be hardcoded. That's a problem if you access
# this project from two computers where the same tool is stored in different
# locations.