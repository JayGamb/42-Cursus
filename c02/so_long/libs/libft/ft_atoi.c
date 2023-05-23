/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:33:28 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/28 17:05:44 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		pos_neg;
	char	*src;

	num = 0;
	i = 0;
	pos_neg = 1;
	src = (char *)str;
	while (src[i] == '\t' || src[i] == '\v' || src[i] == '\n' || src[i] == '\r'
		|| src[i] == '\f' || src[i] == ' ')
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-' )
			pos_neg = -1;
		i++;
	}
	while (src[i] && ft_isdigit(src[i]))
	{
		num = num * 10 + src[i] - '0';
		i++;
	}
	return (num * pos_neg);
}
