# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 17:12:25 by inajah            #+#    #+#              #
#    Updated: 2024/07/11 17:20:33 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c ft_tail.c ft_util.c
HEADERS = .
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I $(HEADERS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

