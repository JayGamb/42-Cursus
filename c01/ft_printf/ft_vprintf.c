/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:43:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 01:05:23 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(const char *format, va_list args)
{
	int j = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				j +=ft_printchar(va_arg(args, int));
			else if (*format == 's')
				j += ft_printstr(va_arg(args, const char *));
			else if (*format == 'p')
			{
				j += ft_printstr("0x");
				j += ft_dectohex_min_ptr(va_arg(args, unsigned long long));
			}
			else if (*format == 'd' || *format == 'i')
				j += ft_intoa(va_arg(args, int));
			else if (*format == 'u')
				j += ft_uitoa(va_arg(args, unsigned int));			
			else if (*format == 'x')
				j += ft_dectohex_min(va_arg(args, int));
			else if (*format == 'X')
				j += ft_dectohex_maj(va_arg(args, unsigned int));
			else if (*format == '%')
				j += ft_printchar(*format);
		}
		else
			j += ft_printchar(*format);
		format++;
	}
	return (j);
}