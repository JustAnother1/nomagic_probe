#!/bin/bash

# update the hardware abstraction layer (HAL) from the
# microcontroller board support package (MBSP) service.
# https://mbsp.nomagic.de/

# 'http://localhost:2323/mbsp'

wget --post-file cfg.json \
 --header='Content-Type:application/json' \
 --output-document=mbsp.zip \
 'https://mbsp.nomagic.de:2323/mbsp'
unzip -o mbsp.zip
rm mbsp.zip
echo "Result:"
cat mbsp_report.txt
echo "Done!"
