# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 17:12:25 by inajah            #+#    #+#              #
#    Updated: 2024/07/11 11:01:20 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_NAME = ft_tail

C_FILES = main.c ft_tail.c ft_util.c
INCLUDES = .
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(PROG_NAME)

$(PROG_NAME): $(C_FILES:.c=.o)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(C_FILES:.c=.o)

fclean: clean
	rm -f $(PROG_NAME)

re: fclean all

