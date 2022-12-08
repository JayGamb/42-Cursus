/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:40:44 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/08 18:36:42 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line(char *str)
{
	int i;
	char *dest;

	i = 0;
	while (str[i]!= '\n')
		i++;
	i++;		
	dest = malloc(sizeof(char *) * i + 1);
	ft_strlcpy(dest, str, i + 1);
	return (dest);
}

char *following_line(char *str)
{
	int i;
	int j;
	char *dest;

	i = 0;
	while (str[i]!= '\n')
		i++;
	i++;
	j = 0;
	dest = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	while(str[i])
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	*ft_linebro(int fd, char *dst)
{
    int c;
	char *buff;

	c = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	while ( c != 0 && !ft_strchr(dst, '\n')) 
	{
		c = read(fd, buff, BUFFER_SIZE);
		dst = ft_strjoin(dst, buff);
    }
	free(buff);
	return (dst);
}

char	*get_next_line(int fd)
{
	char *str;
	char *line;
	static char *dst;
	
	if (!dst)
		dst = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	if (!dst)
		return (0);
	if (!fd || fd < 0)
		return (0);
	str = ft_linebro(fd, dst);
	line = ft_line(str);
	dst = following_line(str);
	free(dst);
	return (line);
}