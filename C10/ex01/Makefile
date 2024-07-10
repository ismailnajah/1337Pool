# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 17:12:25 by inajah            #+#    #+#              #
#    Updated: 2024/07/09 19:45:07 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_NAME = ft_display_file

C_FILES = ft_display_file.c

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(PROG_NAME)


$(PROG_NAME): $(C_FILES:.c=.o)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(C_FILES:.c=.o)

fclean: clean
	rm -f $(PROG_NAME)
