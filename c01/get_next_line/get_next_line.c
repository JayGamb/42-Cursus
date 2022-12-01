/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:40:44 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/01 18:10:11 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// cahr *change_malloc(char *alloc_str, size_t size)
// {
// 	char *tempalloc;
// 	tempalloc = strdup(alloc_str);
// 	free(alloc_str);
// 	strjoin(alloc_str, tempalloc);
// 	free(tempalloc);
// 	return (alloc_str)
	
// }
// void ChangeDynamicArraySize(int** dArray, int oldSize, int newSize){

//     int* tempArray = (int*) malloc(sizeof(int) * oldSize);
//     CopyArray(tempArray, *dArray, oldSize);
//     free(*dArray);
//     *dArray = (int*) malloc(sizeof(int) * newSize);
//     CopyArray(*dArray, tempArray, oldSize);

//     for (int i = oldSize; i < newSize; i++){
//         scanf("%i", dArray[i]);
//     }
//     PrintArray(*dArray, newSize);
//     free(tempArray);
// }
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
	size_t	len_dest;

	len_dest = ft_strlen(dest);
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

static int	count_words(const char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			w++;
		i++;
	}
	return (w);
}

static int	get_word_index(const char *s, int index, char c)
{
	int	i;

	i = 0;
	i += index;
	if (c == '\0')
		return (0);
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static int	ft_strlen_chr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		word_len;
	int		i;
	int		j;
	char	**string;

	string = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !string)
		return (0);
	word_len = 0;
	index = 0;
	j = -1;
	while (++j < count_words(s, c))
	{
		i = index + word_len;
		index = get_word_index(s, i, c);
		word_len = ft_strlen_chr(&s[index], c);
		string[count_words(s, c)] = 0;
		string[j] = ft_substr(s, index, word_len);
		if (!string[j])
			while (j != 0)
				free(string[j--]);
	}
	string[j] = 0;
	return (string);
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

// char *ft_linebro(char *dst, int fd, int size)
// {
//     int c;
//     char *p;
// 	char x;

// 	p = dst;
//     while (size-- > 0) 
// 	{
// 		c = read(fd, &x, 1);
//         *p++ = x;
//         if (x == '\n')
// 		{
// 			*p = 0;
// 			return (dst);
// 		}
//     }
//     *p = 0;
//     if (p == dst || c == -1 || !c)
//         return NULL;
//     return (dst);
// }

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
char	*ft_addchar(char *s1, int c)
{
	size_t		i;
	size_t		i2;

	i = 0;
	i2 = 0;
	while (s1[i])
		i++;
	s1[i] = c;
	i++;
	s1[i] = '\0';
	return (s1);
}
char *ft_line(char *str)
{
	char **tab;
	char *line;

	
	tab = ft_split(str, '\n');
	line = ft_addchar(tab[0], '\n');
	free(tab);
	free(str);
	return (line);
}

char	*ft_linebro(char *dst, int fd)
{
    int c;
	char *temp;
	char *line;
	char *lecture;

	c = 1;
	if (c == -1 || !c)
		return NULL;
	// temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	temp = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	while ( c != 0 && !ft_strchr(dst, '\n')) 
	{
		c = read(fd, dst, BUFFER_SIZE);
		temp = ft_strjoin(temp, dst);
		line = ft_line(temp);
    }
	free(dst);
	return (line);
}

char	*get_next_line(int fd)
{
	// static char buffer[1000];
	char *str;
	// int dex = 0;
	static char *temp;

	if (!fd || fd < 0)
		return (0);
	temp = (char *)malloc(sizeof(char*) * BUFFER_SIZE + 1);
	str = ft_linebro(temp, fd);
	return (str);
}

// char	*ft_read(int fd, char *save)
// {
// 	char	*buf;
// 	int		ret;

// 	if (!save)
// 		save = ft_calloc(1, 1);
// 	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	ret = 1;
// 	while (!(ft_strchr(save, '\n')) && ret != 0)
// 	{
// 		ret = read(fd, buf, BUFFER_SIZE);
// 		if (ret == -1)
// 		{
// 			free(buf);
// 			free(save);
// 			return (NULL);
// 		}
// 		if (ret == 0)
// 			break ;
// 		buf[ret] = '\0';
// 		save = ft_strjoin(save, buf);
// 	}
// 	free(buf);
// 	return (save);
// }

// char	*get_next_line(int fd)
// {
// 	int c;
//     char *str;
// 	static char buffer[1000];
// 	if (!fd || fd == -1)
// 		return (0);
// 	c = 1;
//     while ( c != 0 && (!strchr(str, '\n'))) 
// 	{
// 		c = read(fd, buffer, BUFFER_SIZE);
//         str = ft_strjoin(str, buffer);
// 		if (strchr(str, '\n'))
// 			break;
//     }
// 	if (c == -1 || !c)
//         return NULL;
//     return (str);
// 

/* ----------- code de merde --- */
// char *ft_linebro(int fd)
// {
//     int c;
//     // char *temp;
// 	// temp = malloc(sizeof(char *) * size + 2);
// 	// while (fd)
// 	// {
// 	c = 1;
// 	while (c != 0 && strchr(ret_line, '\n'))
// 		c = read(fd, ret_line, BUFFER_SIZE);
// 	// 	strcpy(temp, buff);
// 	// 	if (strchr(buff, '\n'))
// 	// 	{
// 	// 		return (temp);
// 	// 	}
// 	// }
// 	// 	if (c == -1 || !c)
// 	// 		return NULL;
//     return (ret_line);
// }

// char	*get_next_line(int fd)
// {
// 	static char *ret_line;
// 	// int dex = 0;
// 	char *line;
// 	line = ft_linebro(fd);
// 	return (line);
// }



// char	*get_next_line(int fd)
// {
// 	// static char buffer[1000];
// 	char *str;
// 	// int dex = 0;
// 	char *temp;

// 	if (!fd || fd < 0)
// 		return (0);
// 	str = (char *)malloc(sizeof(char*) * BUFFER_SIZE);
// 	if (!str)
// 		return (0);
// 	temp = (char *)malloc(sizeof(char*) * BUFFER_SIZE);
// 	while (fd)
// 	{
// 		temp = ft_linebro(temp, fd);
// 		str = ft_strjoin(str, temp);
// 		if (strchr(temp, '\n'))
// 		{

// 				return(str);	
// 		}
// 	}
// 	return (str);
// }