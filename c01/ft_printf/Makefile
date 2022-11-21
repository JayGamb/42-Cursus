# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:56:21 by jgamboa-          #+#    #+#              #
#    Updated: 2022/11/21 00:41:24 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SOURCES	=	ft_printf.c ft_vprintf.c ft_printchar.c ft_dectohex_min.c ft_dectohex_maj.c\
			ft_intoa.c ft_uitoa.c ft_hexminmaj.c ft_printstr.c ft_dectohex_min_ptr.c  

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -rf

OBJ_DIR	=	objets
OBJETS	=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)


$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME)	:			$(OBJ_DIR) $(OBJETS) 
						$(AR) $(NAME) $(OBJETS)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

go: all
	$(CC) $(CFLAGS) $(NAME) main.c -o $(NAME) && ./$(NAME) \
	# \
	Output:
	#\
	Cleaning...:	
	make  fclean


clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

