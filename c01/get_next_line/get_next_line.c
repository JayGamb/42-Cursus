/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:40:44 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/25 17:24:48 by jgamboa-         ###   ########.fr       */
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
//     if (c == -1 || !c)
//         return NULL;
//     return (dst);
// }

char	*get_next_line(int fd)
{
	int c;
    char *str;
	static char buffer[1000];

    while ( fd > 0) 
	{
		c = read(fd, buffer, BUFFER_SIZE);
        str = ft_strjoin(str, buffer);
		if (strchr(str, '\n'))
			break;
    }
    if (c == -1 || !c)
        return NULL;
    return (str);
}





// char	*get_next_line(int fd)
// {
// 	// static char buffer[1000]
// 	char *str;
// 	// int dex = 0;
// 	char *temp;

// 	if (!fd || fd == -1)
// 		return (0);
// 	str = (char *)malloc(sizeof(char*) * BUFFER_SIZE);
// 	temp = (char *)malloc(sizeof(char*) * BUFFER_SIZE);
// 	if (!str)
// 		return (0);
// 	while (fd)
// 	{
// 		temp = ft_linebro(temp, fd, BUFFER_SIZE);
// 		str = ft_strjoin(str, temp);
// 		if (strchr(temp, '\n'))
// 		{
// 				return(str);	
// 		}
// 	}
// 	return (str);
// }
