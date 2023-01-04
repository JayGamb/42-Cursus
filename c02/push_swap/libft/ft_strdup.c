/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:01:02 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/05 18:04:09 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
