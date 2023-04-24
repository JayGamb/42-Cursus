/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:15:24 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/05 17:52:22 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*letter;
	size_t			i;

	letter = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (letter[i] == (unsigned char)c)
			return (&letter[i]);
		i++;
	}
	return (0);
}
