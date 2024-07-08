# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 13:15:43 by inajah            #+#    #+#              #
#    Updated: 2024/07/08 13:46:00 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
C_SOURCE=(ft_putchar ft_swap ft_putstr ft_strlen ft_strcmp)
O_FILES=''
CFLAGS='-Wall -Wextra -Werror'

for name in ${C_SOURCE[@]};
do
	echo "gcc $CFLAGS -c $name.c -o $name.o"
	gcc $CFLAGS -c $name.c -o $name.o
	O_FILES+="$name.o "
done
echo "ar rcs libft.a $O_FILES"
ar rcs libft.a $O_FILES
