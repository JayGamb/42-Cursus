/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:23:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/08 16:01:05 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (0);
	i = -1;
	if (src > dest)
		while (++i < n)
			d[i] = s[i];
	else if (dest > src)
	{
		i = n;
		while (i--)
		{
			d[i] = s[i];
		}
	}
	return (dest);
}
