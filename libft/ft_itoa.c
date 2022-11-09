/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:54:58 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/09 16:42:07 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_tab(char *x, unsigned int number, long int len)
{
	while (number > 0)
	{
		x[len--] = (number % 10) + '0';
		number = number / 10;
	}
	return (x);
}

long int	ft_len(int n)
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

char	*ft_itoa(int n)
{
	char				*x;
	long int			len;

	len = ft_len(n);
	x = ft_char_malloc(len);
	if (x)
	{
		x[len--] = 0;
		if (n == 0)
			x[0] = '0';
		if (n < 0)
		{
			n *= -1;
			x[0] = '-';
		}
		ft_tab(x, n, len);
	}
	return (x);
}
