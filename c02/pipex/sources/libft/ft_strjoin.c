/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:58:06 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/05 14:11:24 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
