/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:39:36 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/02 18:37:22 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		free((char *)s);
		return (0);
	}
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*letter;
	int		i;

	if (!s)
		return (0);
	letter = (char *)s;
	i = 0;
	while (letter[i])
	{
		if (letter[i] == (unsigned char)c)
			return (&letter[i]);
		i++;
	}
	if (letter[i] == (unsigned char)c)
		return (&letter[i]);
	return (0);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (ft_strlen_gnl(src));
	else if (n > 1)
	{
		while (i < n - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	return (ft_strlen_gnl(src));
}
