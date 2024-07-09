# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 17:38:40 by inajah            #+#    #+#              #
#    Updated: 2024/07/09 09:02:38 by inajah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

S_DIR = srcs

H_DIR = includes

C_FILES = ft_putchar.c \
		  ft_putstr.c \
		  ft_swap.c \
		  ft_strlen.c \
		  ft_strcmp.c

CFLAGS = -Wall -Wextra -Werror
CC = cc

O_FILES := $(C_FILES:.c=.o)
all: $(LIB_NAME)

$(LIB_NAME): $(O_FILES:%=$(S_DIR)/%)
	libtool $^ -o $(LIB_NAME)

$(S_DIR)/%.o : $(S_DIR)/%.c
	$(CC) $(CFLAGS) -I $(H_DIR) -c $^ -o $@

clean:
	rm -f $(O_FILES:%=$(S_DIR)/%)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
