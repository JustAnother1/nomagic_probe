#!/bin/bash

# 'http://localhost:2323/mbsp'

wget --post-file cfg.json \
 --header='Content-Type:application/json' \
 --output-document=mbsp.zip \
 'https://mbsp.nomagic.de:2323/mbsp'
unzip -o mbsp.zip
rm mbsp.zip
echo "Done!"
