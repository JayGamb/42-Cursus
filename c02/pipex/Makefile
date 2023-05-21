# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 15:35:38 by jgamboa-          #+#    #+#              #
#    Updated: 2023/05/21 15:33:28 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

LPIPEX = pipex.a
LIBS_MERGE = libtool -static -o $(LPIPEX) $(LPIPEX) ./libs/ft_printf/libftprintf.a\
			 ./libs/libft/libft.a
HEADERS = ./headers
SOURCES	=	pipex_utils.c


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=address -g3
AR		=	ar rc
RM		=	rm -rf

OBJ_DIR	=	objets
OBJETS	=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)


$(OBJ_DIR)/%.o	:		%.c
					$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

all				:	$(NAME)
		
$(NAME)			:	$(OBJ_DIR) $(OBJETS) 
					make -C ./libs/libft && make -C ./libs/ft_printf
					$(AR) $(LPIPEX) $(OBJETS)
					$(LIBS_MERGE)
					$(CC) $(CFLAGS) -g -I $(HEADERS) $(LPIPEX) main.c -o $(NAME)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)




clean		:
					$(RM) $(OBJ_DIR)

fclean			:	clean
						$(RM) $(NAME) $(LPIPEX) 
						make fclean -C ./libs/libft
						make fclean -C ./libs/ft_printf

re				:	fclean all