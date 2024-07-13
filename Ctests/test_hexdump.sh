#!/bin/sh
make fclean && make && make clean
./ft_hexdump -C /etc/* > ft_hex.out 
hexdump -C /etc/* > hex.out
echo 'diff hex.out ft_hex.out'
diff hex.out ft_hex.out
