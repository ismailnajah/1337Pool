#!/bin/sh
FT_USER=daemon
id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'
