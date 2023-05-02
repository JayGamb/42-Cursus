/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:37:22 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/02 18:45:19 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <libc.h>

char	*get_next_line(int fd);
int		ft_strlen_gnl(const char *s);
size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t n);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif