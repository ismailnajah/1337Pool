#!/bin/sh
FT_LINE1=4
FT_LINE2=7
cat /etc/passwd | awk '!/^#.*$/' | sed -n 'n;p' | sed 's/:.*//g' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/\./' | tr -d '\n'
