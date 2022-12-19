/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:40:44 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/19 21:24:42 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_fline(char *dst)
{
	int i;
	int len_ret;
	char *ret_line;
	
	i = 0;
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst[i])
	{
		free(dst);
		return (0);
	}
	len_ret = ft_strlen(dst) - i;
	ret_line = (char *)malloc(sizeof(char) * len_ret + 1);
	if (!ret_line)
		return (0);
	ft_strlcpy(ret_line, &dst[i + 1], len_ret);
	free(dst);
	return (ret_line);
}

static char *get_theline(char *dst)
{
	int i;
	char *ret_line;

	i = 0;
	if(!dst[i])
		return (0);
	while (dst[i] && dst[i] != '\n')
		i++;		
	ret_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret_line)
		return (0);
	ft_strlcpy(ret_line, dst, i + 2);

	return (ret_line);
}

static char *readline(int fd, char *dst)
{
    int c;
	char *buff;

	buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buff)
		return (0);
	c = 1;
	while (!ft_strchr(dst, '\n') && c != 0) 
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c == -1)
		{
			free(buff);
			return (0);
		}
		buff[c] = 0;
		dst = free_join(dst, buff);
    }
	free(buff);
	return (dst);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(dst);
		line = 0;
		return (0);
	}
	dst = readline(fd, dst);
	if (!dst)
		return (0);
	line = get_theline(dst);
	dst = get_fline(dst);
	// printf("dst value: *%s*\n", dst);
	return (line);
}