# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:06:26 by jgamboa-          #+#    #+#              #
#    Updated: 2023/05/02 18:53:11 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
		ft_iswhitespace.c ft_abs.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
		ft_atoi.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c  ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_strcmp.c ft_strcat.c ft_atol.c ft_getpath.c ft_printerror.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_arrlen.c free_join.c get_next_line.c get_next_line_utils.c\

HEADERS = ../../headers

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -rf

OBJ_DIR	=	objets
OBJETS	=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)

# REiGLES
$(OBJ_DIR)/%.o	:		%.c
					$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@
					
all				:	$(NAME)

$(NAME)			:	$(OBJ_DIR) $(OBJETS) 
					$(AR) $(NAME) $(OBJETS)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

clean			: 
					$(RM) -f $(OBJ_DIR)

fclean			:	clean
						rm -f $(NAME)

re: fclean all

