/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:02:06 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/05 15:57:00 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
