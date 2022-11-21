/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:43:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 12:27:33 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(const char *format, va_list args)
{
	int	j;

	j = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's')
				j += ft_charstr(*format, args);
			else if (*format == 'd' || *format == 'i')
				j += ft_intoa(va_arg(args, int));
			else if (*format == 'u')
				j += ft_uitoa(va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X' || *format == 'p')
				j += ft_hexminmaj(*format, args);
			else if (*format == '%')
				j += ft_printchar(*format);
		}
		else
			j += ft_printchar(*format);
		format++;
	}
	return (j);
}
