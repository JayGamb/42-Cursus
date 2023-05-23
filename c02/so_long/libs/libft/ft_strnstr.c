/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:31:28 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/05 17:59:42 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((s2 != NULL) && (s2[0] == '\0'))
		return ((char *)s1);
	while (i != n && s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while ((s2[j] && s1[i + j] == s2[j]))
			{	
				if (s2[j + 1] == 0 && (ft_strlen(s2) + i) <= n)
					return ((char *)&s1[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
