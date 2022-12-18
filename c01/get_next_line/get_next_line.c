/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:40:44 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/17 00:15:46 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char *ft_line(char *dst)
// {
// 	int i;
// 	char *ret_line;

// 	i = 0;
// 	if(!dst[i])
// 		return (0);
// 	while (dst[i] && dst[i] != '\n')
// 		i++;		
// 	ret_line = (char *)malloc(sizeof(char) * (i + 2));
// 	if (!ret_line)
// 		return (0);
// 	i = 0;
// 	while (dst[i] && dst[i] != '\n')
// 	{
// 		ret_line[i] = dst[i];
// 		i++;
// 	}
// 	if (dst[i] == '\n')
// 	{
// 		ret_line[i] = dst[i];
// 		i++;
// 	}
// 	ret_line[i] = '\0';
// 	return (ret_line);
// }

// char *following_line(char *dst)
// {
// 	int i;
// 	int j;
// 	char *ret_line;

// 	i = 0;
// 	while (dst[i] && dst[i] != '\n')
// 		i++;
// 	if (!dst)
// 	{
// 		free(dst);
// 		return (0);
// 	}
// 	ret_line = (char *)malloc(sizeof(char) * (ft_strlen(dst) - i + 1));
// 	if (!ret_line)
// 		return (0);
// 	i++;
// 	j = 0;
// 	while(dst[i])
// 	{
// 		ret_line[j] = dst[i];
// 		i++;
// 		j++;
// 	}
// 	ret_line[j] = 0;
// 	free(dst);
// 	return (ret_line);
// }

char *get_fline(char *dst)
{
	int i;
	int len_ret;
	char *ret_line;

	i = 0;
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst)
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

char *get_line(char *dst)
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

char	*readline(int fd, char *dst)
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
		return (0);
	dst = readline(fd, dst);
	if (!dst)
		return (0);
	line = get_line(dst);
	dst = get_fline(dst);
	return (line);
}