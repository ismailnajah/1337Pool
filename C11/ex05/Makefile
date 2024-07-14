# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 09:58:08 by inajah            #+#    #+#              #
#    Updated: 2024/07/14 15:06:45 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = main.c ft_op.c ft_atoi.c ft_print.c
S_DIR = srcs
INCLUDE = includes
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ:%=$(S_DIR)/%)	
	@$(CC) $(CFLAGS) -I $(INCLUDE) $^ -o $(NAME)

$(S_DIR)/%.o: $(S_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

clean:
	@/bin/rm -f $(OBJ:%=$(S_DIR)/%)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 

