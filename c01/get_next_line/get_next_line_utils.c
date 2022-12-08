/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:39:36 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/08 17:56:21 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest || n == 0)
		return (ft_strlen(src));
	else if (n > 1)
	{
		while (i < n - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	return (ft_strlen(src));
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	len = ft_strlen(s1);
	i = -1;
	while (s1[++i])
		new_s[i] = s1[i];
	i = -1;
	while (s2[++i])
		new_s[len + i] = s2[i];
	new_s[len + i] = 0;
	return (new_s);
}


void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc (nmemb * size);
	if (!p)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	char	*letter;
	int		i;

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