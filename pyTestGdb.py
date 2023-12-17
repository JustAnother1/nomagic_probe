#!/usr/bin/python3
# -*- coding: utf-8 -*-

import subprocess
import os
import time

def readPrintout():
    c = proc.stdout.read1()
    while c != b'':
        for line in c.decode("utf-8").splitlines():
            print(line)
        time.sleep(.5)
        c = proc.stdout.read1()
    c = proc.stderr.read1()
    while c != b'':
        for line in c.decode("utf-8").splitlines():
            print(line)
        c = proc.stderr.read1()

#arm-none-eabi-gdb --nh --nx 
# --eval-command="set verbose on"
# --eval-command="target extended-remote /dev/serial/by-id/usb-Raspberry_Pi_nomagic_probe_000000000001-if00" 
# bin/nomagic_probe.elf
cmd = 'arm-none-eabi-gdb --nh --nx bin/nomagic_probe.elf'

proc = subprocess.Popen(cmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
print('started gdb')
time.sleep(1)
os.set_blocking(proc.stdout.fileno(), False)
os.set_blocking(proc.stderr.fileno(), False)
readPrintout()

time.sleep(1)
print('sending verbose on')
proc.stdin.write('set verbose on\r\n'.encode())
proc.stdin.flush()
time.sleep(.5)
readPrintout()
proc.stdin.write('show verbose\r\n'.encode())
proc.stdin.flush()
time.sleep(.5)
readPrintout()

time.sleep(1)
print('sending remote')
proc.stdin.write('target extended-remote /dev/serial/by-id/usb-Raspberry_Pi_nomagic_probe_000000000001-if00\r\n'.encode())
proc.stdin.flush()
time.sleep(.5)
readPrintout()
    
time.sleep(20)

readPrintout()

remainder = proc.communicate()[0]
print(remainder.decode("utf-8"))
print('Done!')

if proc.returncode == 0:
	print('Command succeeded:')
else:
	print('Command failed:')
