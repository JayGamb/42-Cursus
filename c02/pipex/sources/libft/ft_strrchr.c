/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:30:03 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/05 17:46:12 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*letter;
	int		i;

	letter = (char *)s;
	i = ft_strlen(s);
	if (!s)
		return (0);
	while (i >= 0)
	{
		if (letter[i] == (unsigned char)c)
			return (&letter[i]);
		i--;
	}
	return (0);
}
