# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 17:12:25 by inajah            #+#    #+#              #
#    Updated: 2024/07/14 11:36:05 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c ft_hexdump.c ft_util.c ft_print.c
HEADERS = .
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -I $(HEADERS) -o $(NAME)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $^

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

