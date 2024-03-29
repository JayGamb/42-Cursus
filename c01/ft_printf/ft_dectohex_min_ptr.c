/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex_min_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:56:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 11:59:09 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dectohex_min_ptr(unsigned long long n)
{
	int		i;
	int		j;
	int		temp;
	char	num[100];

	i = 1;
	if (n == 0)
		return (ft_printstr("0x0"));
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		num[i++] = temp;
		n = n / 16;
	}
	j = i - 1;
	i += ft_printstr("0x");
	while (j > 0)
		ft_printchar(num[j--]);
	return (i - 1);
}
