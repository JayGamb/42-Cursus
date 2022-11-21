/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:16:01 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 11:43:22 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_lentnbr(unsigned long int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i = 1;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static char	*ft_tab2(char *str, unsigned int number, long int len)
{
	while (number > 0)
	{
		str[len--] = (number % 10) + '0';
		number = number / 10;
	}
	return (str);
}

int	ft_uitoa(unsigned int n)
{
	char				*str;
	unsigned long int	i;

	i = ft_lentnbr(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i--] = 0;
	if (n == 0)
		str[0] = '0';
	ft_tab2(str, n, i);
	i = ft_printstr(str);
	free(str);
	return (i);
}
