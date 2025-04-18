#!/bin/bash

# update the hardware abstraction layer (HAL) from the
# microcontroller board support package (MBSP) service.
# https://mbsp.nomagic.de/

# 'http://localhost:2323/mbsp'
rm hal/hw/ -r 2>/dev/null
rm hal/2ndstage.bin 2>/dev/null
rm  hal/RP2040.ld 2>/dev/null
rm  hal/debug_uart.h 2>/dev/null
rm  hal/debug_uart.c 2>/dev/null
rm  hal/target_uart.h 2>/dev/null
rm  hal/target_uart.c 2>/dev/null
rm  hal/digital_out.h 2>/dev/null
rm hal/irq.c 2>/dev/null
rm hal/startup.c 2>/dev/null
rm mbsp_report.txt 2>/dev/null

wget --post-file cfg.json \
 --header='Content-Type:application/json' \
 --output-document=mbsp.zip \
 'http://localhost:2323/mbsp'

returnCode=$?
echo "res: $returnCode"
if [ $returnCode -eq 0 ]
then
  echo "OK"
else
  echo "Failed !"
  exit 1
fi

unzip -o mbsp.zip

returnCode=$?
echo "res: $returnCode"
if [ $returnCode -eq 0 ]
then
  echo "OK"
else
  echo "Failed !"
  exit 1
fi

rm mbsp.zip
echo "Result:"
cat mbsp_report.txt
if grep -q "successful = false" "mbsp_report.txt"; then
    echo "!!!!!!!!!!!!!!!!!!!!!"
    echo "!!!! MBSP failed !!!!"
    echo "!!!!!!!!!!!!!!!!!!!!!"
else
    echo "Done!"
fi
