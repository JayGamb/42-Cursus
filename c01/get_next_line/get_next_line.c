/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:39:25 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/25 12:35:39 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char buffer[100];
	int bytes_read;
	char *str;
	char *save;
	
	str = (char *)malloc(sizeof(char*) * 10 + 1);
	if (!str)
				str = strdup("");
	while (fd != '\n')
	{
		bytes_read = read(fd, buffer, 10);
		while (*buffer != '\n')
		{
			printf("%d\n", bytes_read);
			save = strncpy(str, buffer, 10);
		}
	}
	return (str);
}