# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 17:12:25 by inajah            #+#    #+#              #
#    Updated: 2024/07/11 17:05:35 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_cat.c main.c ft_util.c
HEADER = .
OBJ := $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I $(HEADER) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

