/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:13:22 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 12:44:16 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_tab(char *str, unsigned int number, long int len)
{
	while (number > 0)
	{
		str[len--] = (number % 10) + '0';
		number = number / 10;
	}
	return (str);
}

static long int	ft_lennbr(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_intoa(int n)
{
	char				*str;
	long int			len;

	len = ft_lennbr(n);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	str[len--] = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	ft_tab(str, n, len);
	len = ft_printstr(str);
	free(str);
	return (len);
}
