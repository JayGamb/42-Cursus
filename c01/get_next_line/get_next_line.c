/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:40:44 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/12 16:28:18 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line(char *str)
{
	int i;
	char *dest;
	char *ret;

	i = 0;
	while (str[i]!= '\n')
		i++;
	i++;		
	dest = malloc(sizeof(char *) * i + 1);
	ret = ft_strlcpy(dest, str, i + 1);
	free(dest);
	return (ret);
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
	dest = malloc(BUFFER_SIZE * sizeof(char) + 1);
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
	buff = malloc(BUFFER_SIZE * sizeof(char *) + 1);
	if (!buff)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		free(dst);
		dst = 0;
		return (0);
	}
	while ( c >= 1) 
	{
		c = read(fd, buff, BUFFER_SIZE);
		dst = ft_strjoin(dst, buff);
		if (ft_strchr(dst, '\n'))
			break; 
    }
	free(buff);
	return (dst);
}

char	*get_next_line(int fd)
{
	char *str;
	char *line;
	static char *dst;

	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	dst = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	if (!dst)
		return (0);
	str = ft_linebro(fd, dst);
	line = ft_line(str);
	dst = following_line(str);
	free(dst);
	return (line);
}