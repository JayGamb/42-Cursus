/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:35:24 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/05 15:47:10 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (start >= ft_strlen(s) || !(*s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (new_s)
	{
		ft_strlcpy(new_s, s + start, len + 1);
		return (new_s);
	}
	return (0);
}
