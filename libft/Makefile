# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:06:26 by jgamboa-          #+#    #+#              #
#    Updated: 2022/11/09 15:20:40 by jgamboa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
		ft_atoi.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c  ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strcat.c ft_char_malloc.c

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

AR = ar rc $(NAME)

# REiGLES

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	 rm -f $(NAME)

lego: all
	gcc $(FLAGS) $(NAME) -o $(NAME) main.c


go: all
	gcc $(FLAGS) $(NAME) -o $(NAME) main.c && ./$(NAME) \
	# \
	Output:
	#\
	Cleaning...:	
	make  fclean

re: aclean
	make go

