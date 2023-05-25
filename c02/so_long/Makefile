# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 13:09:34 by jgamboa-          #+#    #+#              #
#    Updated: 2023/05/25 05:45:23 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LSO_LONG = so_long.a

LIBFTPRINTF_DIR = ./libs/ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = headers
SOURCES_DIR = sources
SOURCES = $(shell find $(SOURCES_DIR) -type f -name '*.c')

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LDFLAGS = -Imlx -framework OpenGL -framework AppKit
AR = ar rc
RM = rm -rf

OBJ_DIR = objets
OBJ_FILES = $(patsubst $(SOURCES_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)
	make -C $(LIBFTPRINTF_DIR)
	$(AR) $(LSO_LONG) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(HEADERS) $(LSO_LONG) main.c -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LSO_LONG)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all
