/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexminmaj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:36:20 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 12:13:09 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexminmaj(char c, va_list args)
{
	if (c == 'x')
		return (ft_dectohex_min(va_arg(args, int)));
	else if (c == 'X')
		return (ft_dectohex_maj(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_dectohex_min_ptr(va_arg(args, unsigned long long)));
	return (0);
}
