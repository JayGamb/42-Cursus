/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:51:04 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/08 18:24:50 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_negative(int nb, int fd)
{	
	if (nb <= 0 && nb > -10)
	{
		ft_putchar_fd(nb * -1 + '0', fd);
	}
	else if (nb <= 10)
	{	
		int_negative(nb / 10, fd);
		int_negative(nb % 10, fd);
	}
}

void	int_positive(int nb, int fd)
{	
	if (nb >= 0 && nb < 10)
	{	
		ft_putchar_fd(nb + '0', fd);
	}
	else if (nb >= 10)
	{
		int_positive(nb / 10, fd);
		int_positive(nb % 10, fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		int_negative(nb, fd);
	}
	else
	{
		int_positive(nb, fd);
	}
}
