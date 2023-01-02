# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 12:54:38 by jgamboa-          #+#    #+#              #
#    Updated: 2023/01/02 15:15:57 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIB =		push_swap.a

SOURCES	=	push_swap.c


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -rf

OBJ_DIR	=	objets
OBJETS	=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)


$(OBJ_DIR)/%.o	:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all				:	$(NAME)

					
$(NAME)			:	$(OBJ_DIR) $(OBJETS) 
						$(AR) $(LIB) $(OBJETS)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)


go				:	all

					$(CC) $(CFLAGS) $(LIB) main.c -o $(NAME) && ./$(NAME) \
					# \
					Output:
					#\
					Cleaning...:	
					make  fclean


clean		:
					$(RM) $(OBJ_DIR)

fclean			:	clean
						$(RM) $(NAME) $(LIB)

re				:	fclean all