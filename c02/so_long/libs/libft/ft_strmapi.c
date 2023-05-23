/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:48:42 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/08 17:37:44 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	if (!s)
		return (0);
	string = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!string)
		return (0);
	i = -1;
	while (s[++i])
		string[i] = f(i, s[i]);
	string[i] = 0;
	return (string);
}
