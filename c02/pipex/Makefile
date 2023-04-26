# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 15:35:38 by jgamboa-          #+#    #+#              #
#    Updated: 2023/04/26 15:49:55 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

LPIPEX = pipex.a
LIBS_MERGE = libtool -static -o $(LPIPEX) $(LPIPEX) ./libs/ft_printf/libftprintf.a\
			 ./libs/libft/libft.a ./libs/p-master/p.a
HEADERS = ./headers
SOURCES	=	check_args.c set_pipes.c


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
					make -C ./libs/libft && make -C ./libs/ft_printf && make -C ./libs/p-master
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
						make fclean -C ./libs/p-master

re				:	fclean all