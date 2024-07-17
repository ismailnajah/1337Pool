# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 18:16:59 by inajah            #+#    #+#              #
#    Updated: 2024/07/17 20:43:20 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_bsq_solver.c ft_map.c ft_map_metadata.c ft_dp_matrix.c ft_util.c
SRC_D = srcs
INCLUDE = includes
OBJ := $(SRC:.=.o)
OBJ := $(OBJ:%=$(SRC_D)/%)

NAME = bsq

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I $(INCLUDE) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re 
