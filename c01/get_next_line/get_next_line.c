/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:40:44 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/29 18:49:04 by jgamboa-         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
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


char	*ft_linebro(char *dst, int fd)
{
    int c;
	char *temp;

	c = 1;
	if (c == -1 || !c)
		return NULL;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	while ( c != 0 && !strchr(dst, '\n')) 
	{
		c = read(fd, temp, BUFFER_SIZE);
		dst = ft_strjoin(dst, temp);
		if (c == 0)
			break ;
		temp[c] = '\0';
    }

	free(temp);
    return (dst);
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
// }

char	*get_next_line(int fd)
{
	// static char buffer[1000];
	char *str;
	// int dex = 0;
	static char *temp;

	if (!fd || fd < 0)
		return (0);
	str = (char *)malloc(sizeof(char*) * BUFFER_SIZE);
	if (!str)
		return (0);
	temp = (char *)malloc(sizeof(char*) * BUFFER_SIZE);
	str = ft_linebro(temp, fd);
	return (str);
}


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