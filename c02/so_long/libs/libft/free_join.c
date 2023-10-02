/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:16:20 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/02 14:05:42 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_join(char *dst, char *buff)
{
	char	*ret_line;

	if (!dst)
	{
		dst = (char *)malloc(1 * sizeof(char));
		dst[0] = 0;
	}
	ret_line = ft_strjoin_gnl(dst, buff);
	free(dst);
	return (ret_line);
}
