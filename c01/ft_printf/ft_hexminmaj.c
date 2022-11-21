/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexminmaj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:36:20 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 01:39:13 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexminmaj(char c, va_list args)
{
	if (c == 'x')
		return (ft_dectohex_min(va_arg(args, int)));
	else if (c == 'X')
		return (ft_dectohex_maj(va_arg(args, unsigned int)));
	return (1);
}