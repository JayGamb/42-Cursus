# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 12:54:38 by jgamboa-          #+#    #+#              #
#    Updated: 2023/01/02 17:21:04 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a

SOURCES	=	get_next_line.c get_next_line_utils.c


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
	$(CC) $(CFLAGS) -D BUFFER_SIZE=5 $(NAME) main.c -o $(NAME) && ./$(NAME) \
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

