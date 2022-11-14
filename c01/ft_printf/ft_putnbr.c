/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:43:06 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/14 15:36:19 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	int_negative(int nb)
{	
	if (nb <= 0 && nb > -10)
	{
		ft_putchar(nb * -1 + '0');
	}
	else if (nb <= 10)
	{	
		int_negative(nb / 10);
		int_negative(nb % 10);
	}
}

static void	int_positive(int nb)
{	
	if (nb >= 0 && nb < 10)
	{	
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		int_positive(nb / 10);
		int_positive(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		int_negative(nb);
	}
	else
	{
		int_positive(nb);
	}
}