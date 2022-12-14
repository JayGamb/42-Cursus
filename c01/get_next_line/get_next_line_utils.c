/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:39:36 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/14 19:42:25 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
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

char *free_join(char *dst, char *buff)
{
	char *ret_line;

	if (!dst)
	{
		dst = (char *)malloc(1 * sizeof(char));
		dst[0] = '\0';
	}
	ret_line = ft_strjoin(dst, buff);
	free(dst);
	return (ret_line);
}

// char	*ft_strjoin(char *left_str, char *buff)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!left_str)
// 	{
// 		left_str = (char *)malloc(1 * sizeof(char));
// 		left_str[0] = '\0';
// 	}
// 	if (!left_str || !buff)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (left_str)
// 		while (left_str[++i] != '\0')
// 			str[i] = left_str[i];
// 	while (buff[j] != '\0')
// 		str[i++] = buff[j++];
// 	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
// 	free(left_str);
// 	return (str);
// }

char	*ft_strchr(const char *s, int c)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (start >= ft_strlen(s) || !(*s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (new_s)
	{
		ft_strlcpy(new_s, s + start, len + 1);
		return (new_s);
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*mem;

	mem = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (mem == NULL)
		return (0);
	ft_memcpy(mem, s, ft_strlen(s) * sizeof(char) + 1);
	mem[ft_strlen(s)] = 0;
	return (mem);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	if (dest || src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
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

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, '\0', n);
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