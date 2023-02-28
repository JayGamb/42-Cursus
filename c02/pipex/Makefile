# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 15:35:38 by jgamboa-          #+#    #+#              #
#    Updated: 2023/02/28 17:19:29 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

LPIPEX = pipex.a
LIBS_MERGE = libtool -static -o $(LPIPEX) $(LPIPEX) ./sources/ft_printf/libftprintf.a\
			 ./sources/libft/libft.a ./sources/p-master/p.a
HEADERS = ./headers
SOURCES	=	test_p.c


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
					make -C ./sources/libft && make -C ./sources/ft_printf && make -C ./sources/p-master
					$(AR) $(LPIPEX) $(OBJETS)
					$(LIBS_MERGE)
					$(CC) $(CFLAGS) -g -I $(HEADERS) $(LPIPEX) main.c -o $(NAME)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)




clean		:
					$(RM) $(OBJ_DIR)

fclean			:	clean
						$(RM) $(NAME) $(LPIPEX) 
						make fclean -C ./sources/libft
						make fclean -C ./sources/ft_printf
						make fclean -C ./sources/p-master

re				:	fclean all