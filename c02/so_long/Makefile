# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 13:09:34 by jgamboa-          #+#    #+#              #
#    Updated: 2023/05/25 16:57:57 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFTSO_LONG	= libftso_long.a

LIBFTPRINTF_DIR	= ./libs/ft_printf
LIBFTPRINTF		= $(LIBFTPRINTF_DIR)/libftprintf.a

LIBFT_DIR		=./libs/libft
LIBFT			= $(LIBFT_DIR)/libft.a
LIBS_A			= $(LIBFT) $(LIBFTPRINTF) $(LIBFTSO_LONG)

HEADERS			= headers
SOURCES_DIR		= sources
SOURCES			= $(shell find $(SOURCES_DIR) -type f -name '*.c')

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g3
LDFLAGS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
AR				= ar rc
RM				= rm -rf

OBJ_DIR			= objets
OBJ_FILES		= $(patsubst $(SOURCES_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -I$(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)
	make -C $(LIBFTPRINTF_DIR)
	make -C ./mlx
	$(AR) $(LIBFTSO_LONG) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(HEADERS) $(LIBS_A) main.c -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFTSO_LONG)
	make clean -C ./mlx
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all
