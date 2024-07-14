# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 09:58:08 by inajah            #+#    #+#              #
#    Updated: 2024/07/14 10:35:09 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = main.c ft_op.c ft_atoi.c ft_print.c
INCLUDE = .
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)	
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 

