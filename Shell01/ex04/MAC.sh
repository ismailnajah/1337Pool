#!/bin/sh
ifconfig -a | grep -oE '([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}'
