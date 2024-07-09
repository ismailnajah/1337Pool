# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 17:12:25 by inajah            #+#    #+#              #
#    Updated: 2024/07/09 17:16:52 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_NAME = ft_display_file

C_FILES = ft_display_file.c

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(PROG_NAME)


$(PROG_NAME): $(C_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	echo $(C_FILES:.c=.o)

fclean: clean
	echo $(PROG_NAME)
