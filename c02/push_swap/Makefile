# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 12:54:38 by jgamboa-          #+#    #+#              #
#    Updated: 2023/02/20 11:29:15 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LPUSH_SWAP = push_swap.a
LIBS_MERGE = libtool -static -o $(LPUSH_SWAP) $(LPUSH_SWAP) ./ft_printf/libftprintf.a\
			 ./libft/libft.a
HEADERS = ./headers
SOURCES	=	push_swap_utils.c linkdlist_ops.c check_utils.c instructions.c\
			operations_opti.c sorting_utils.c big_sort.c small_sort.c swap.c push.c rotate.c reverse.c


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -rf

OBJ_DIR	=	objets
OBJETS	=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)


$(OBJ_DIR)/%.o	:		%.c
					$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

all				:	$(NAME)
		
$(NAME)			:	$(OBJ_DIR) $(OBJETS) 
					make -C libft && make -C ft_printf
					$(AR) $(LPUSH_SWAP) $(OBJETS)
					$(LIBS_MERGE)
					$(CC) $(CFLAGS) -I $(HEADERS) $(LPUSH_SWAP) push_swap.c -o $(NAME)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)


clean		:
					$(RM) $(OBJ_DIR)

fclean			:	clean
						$(RM) $(NAME) $(LPUSH_SWAP) 
						make fclean -C libft
						make fclean -C ft_printf

re				:	fclean all