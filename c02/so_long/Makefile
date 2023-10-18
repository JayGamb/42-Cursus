# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 13:09:34 by jgamboa-          #+#    #+#              #
#    Updated: 2023/10/09 14:10:43 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFTSO_LONG	= libftso_long.a

LIBFTPRINTF_DIR	= ./libs/ft_printf
LIBFTPRINTF		= $(LIBFTPRINTF_DIR)/libftprintf.a

LIBFT_DIR		=./libs/libft
LIBFT			= $(LIBFT_DIR)/libft.a
LIBS_A			= $(LIBFTSO_LONG) $(LIBFT) $(LIBFTPRINTF)

HEADERS			= headers
SOURCES_DIR		= sources
SOURCES			=	$(SOURCES_DIR)/arg_check.c \
					$(SOURCES_DIR)/error_handling.c \
					$(SOURCES_DIR)/images_handling.c \
					$(SOURCES_DIR)/map_exploration.c \
					$(SOURCES_DIR)/map_manipulation.c \
					$(SOURCES_DIR)/queue_functions.c \
					$(SOURCES_DIR)/so_long_utils.c \
					$(SOURCES_DIR)/so_long_utils2.c



CC				= gcc
#CFLAGS			= -Wall -Wextra -Werror -I/opt/X11/include -Imlx -I$(HEADERS) #-Wall -Wextra -Werror #-fsanitize=address -g3
#LDFLAGS			= -Lmlx -L/opt/X11/lib -lX11 -lmlx -framework OpenGL -framework AppKit -lm 

CFLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g3
LDFLAGS			=-Lmlx -lmlx -framework OpenGL -framework AppKit -lm


AR				= ar rc
RM				= rm -rf

OBJ_DIR			= objets
OBJ_FILES		= 	$(OBJ_DIR)/arg_check.o \
					$(OBJ_DIR)/error_handling.o \
					$(OBJ_DIR)/images_handling.o \
					$(OBJ_DIR)/map_exploration.o \
					$(OBJ_DIR)/map_manipulation.o \
					$(OBJ_DIR)/queue_functions.o \
					$(OBJ_DIR)/so_long_utils.o \
					$(OBJ_DIR)/so_long_utils2.o

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJ_DIR)
#	$(CC) $(CFLAGS) -Imlx -I$(HEADERS) -c $< -o $@
	$(CC) $(CFLAGS) -Imlx -I$(HEADERS) -I/opt/X11/include -c $< -o $@

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
