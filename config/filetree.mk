################################################################################
#                              MAKEFILE INCLUDES                               #
################################################################################
# COPYRIGHT (c) 2023 Embeetle                                                  #
# This software component is licensed by Embeetle under the MIT license. Con-  #
# sult the license text at the bottom of this file.                            #
#                                                                              #
#------------------------------------------------------------------------------#
#                                   SUMMARY                                    #
#------------------------------------------------------------------------------#
# This file should be included in the makefile. It lists all source files (c,  #
# c++, asm..) that take part in the compilation.                               #
#                                                                              #
# Take a look at the Embeetle filetree. All files with a green checkmark are   #
# the ones ending up here in this file. Embeetle attempts to list automatical- #
# ly the right set of files, starting from 'main.c'. However, you can manually #
# overrule the beetle's decisions by clicking the file's checkmark (turning it #
# red). Save the project (Ctrl+S) and observe the result in this file.         #
#                                                                              #
# We suggest to include this file in your makefile like so:                    #
#                                                                              #
#     MAKEFILE := $(lastword $(MAKEFILE_LIST))                                 #
#     MAKEFILE_DIR := $(dir $(MAKEFILE))                                       #
#     include $(MAKEFILE_DIR)filetree.mk                                       #
#                                                                              #
#------------------------------------------------------------------------------#
#                                    EDITS                                     #
#------------------------------------------------------------------------------#
# This file was automatically generated. Do not edit! It is overwritten regu-  #
# larly by Embeetle. Although Embeetle IDE practices the "treat config as      #
# code" principle, this file is an exception.                                  #
#                                                                              #
# If you want to force a certain source file to be in- or excluded from the    #
# build, just click the corresponding checkbox in the Embeetle Filetree and    #
# save the project. This file should adapt itself accordingly.                 #
#                                                                              #
#------------------------------------------------------------------------------#
#                               MORE INFORMATION                               #
#------------------------------------------------------------------------------#
# Consult the following pages on our website for more info about this file:    #
# https://embeetle.com/#embeetle-ide/manual/beetle-anatomy/file-tree           #
# https://embeetle.com/#embeetle-ide/manual/build/source-file-selection        #
#                                                                              #
# Read this comic if you want to have a good laugh:                            #
# https://embeetle.com/#comics/src_files_selection                             #
#                                                                              #
################################################################################

# VERSION:
EMBEETLE_MAKEFILE_INTERFACE_VERSION = 7

# INCLUDED CFILES:
C_OFILES = \
project/source/cli/cli.c.o \
project/source/cli/cli_memory.c.o \
project/source/cli/cli_sys.c.o \
project/source/cli/cli_usb.c.o \
project/source/file/faked_disk.c.o \
project/source/file/file_storage.c.o \
project/source/file/file_system.c.o \
project/source/gdbserver/commands.c.o \
project/source/gdbserver/gdbserver.c.o \
project/source/gdbserver/util.c.o \
project/source/hal/boot_rom.c.o \
project/source/hal/debug_uart.c.o \
project/source/hal/flash.c.o \
project/source/hal/hw_divider.c.o \
project/source/hal/startup.c.o \
project/source/hal/watchdog.c.o \
project/source/led.c.o \
project/source/lib/atoi.c.o \
project/source/lib/ctype.c.o \
project/source/lib/memcpy.c.o \
project/source/lib/memmove.c.o \
project/source/lib/memset.c.o \
project/source/lib/printf.c.o \
project/source/lib/strlen.c.o \
project/source/lib/strncmp.c.o \
project/source/main.c.o \
project/source/time_base.c.o \
project/source/tinyusb/src/class/cdc/cdc_device.c.o \
project/source/tinyusb/src/class/msc/msc_device.c.o \
project/source/tinyusb/src/common/tusb_fifo.c.o \
project/source/tinyusb/src/device/usbd.c.o \
project/source/tinyusb/src/device/usbd_control.c.o \
project/source/tinyusb/src/tusb.c.o \
project/source/tinyusb/usb.c.o \
project/source/tinyusb/usb_cdc.c.o \
project/source/tinyusb/usb_descriptors.c.o \
project/source/tinyusb/usb_msc.c.o

# INCLUDED CXXFILES:
CXX_OFILES =

# INCLUDED SFILES:
S_OFILES =

# LIST ALL OFILES:
OFILES = $(C_OFILES) $(CXX_OFILES) $(S_OFILES)

# INCLUDED HDIRS:
HDIR_FLAGS = \
-I$(SOURCE_DIR)source \
-I$(SOURCE_DIR)source/cfg \
-I$(SOURCE_DIR)source/lib \
-I$(SOURCE_DIR)source/tinyusb/src

# INCLUDED ARCHIVES
PROJECT_LDLIBS =

# MIT LICENSE
# ===========
# COPYRIGHT (c) 2020 Embeetle
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