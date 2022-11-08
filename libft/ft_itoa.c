/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:54:58 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/08 18:37:49 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int n_digits( int n)
{
	long long nb;
	int count;

	nb = n;
	count = 0;
	while (nb != 0)
	{
		nb /= 10;
		count++;
		nb--;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(char) * (n_digits(nb) + 1));
	if (!str)
		return (0);
	i = n_digits(nb);
	while (nb)
	{
		if (nb == 0)
		{
			str[0] = 48;
			return (str);
		}
		if (nb < 0)
		{
			str[0] = '-';
			nb = nb * -1;
		}
		while (nb > 0)
		{
			str[i] = 48 + (nb % 10);
			nb = nb / 10;
			i++;
			nb--;
		} 
	}
	return (str);
}