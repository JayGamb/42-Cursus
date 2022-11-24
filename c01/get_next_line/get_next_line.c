/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:39:25 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/24 20:38:34 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_linebro(char *dst, int fd, int size)
{
    int c;
    char *p;
	static char x;

	p = dst;
    while (size-- > 0) 
	{
		c = read(fd, &x, 1);
        *p++ = x;
        if (x == '\n')
		{
			*p = 0;
			return (dst);
		}

    }
    *p = 0;
    if (p == dst || c == -1 || !c)
        return NULL;
    return (dst);
}

char	*get_next_line(int fd)
{
	// char buffer[100]
	char *str;
	// int dex = 0;
	int size = 10;
	char *temp;

	
	str = (char *)malloc(sizeof(char*) * size + 1);
	temp = (char *)malloc(sizeof(char*) * size + 1);
	if (!str)
		str = strdup("");
	if (!fd)
		return (0);
	while (fd)
	{
		temp = ft_linebro(temp, fd, size);
		str = strcat(str, temp);
		if (strchr(temp, '\n'))
				return(str);
			
	}
	return (str);
}
