# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 13:15:43 by inajah            #+#    #+#              #
#    Updated: 2024/07/09 11:41:34 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
rm -f libft.a
find . -name "*.c" -type f -exec gcc -Wall -Werror -Wextra -c {} \;
ar rcs libft.a *.o
find . -name "*.o" -type f -delete
