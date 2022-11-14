/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:36:08 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/14 17:46:57 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_putstr(const char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}	
}


void	ft_vprintf(const char *format, va_list args)
{
	int state;
	const char *str;

	state = 0;
	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
				state = 1;
			else
				ft_putchar(*format);
		}
		else if (state == 1)
		{
			if (*format == 'c')
				ft_putchar(va_arg(args, int));
			else if (*format == 's')
				ft_putstr(va_arg(args, const char *));
			else if (*format == 'd')
				ft_putnbr(va_arg(args, int));
			else if (*format == 'x')
				ft_dectohex(va_arg(args, int));
			state = 0;
		}
		format++;
			
	}
}


int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start (args, format);

	ft_vprintf(format, args);

	return (1);

}


int main ()
{
	void *ptr_to_main = (void *) main;

	ft_printf("Print a Character: %c. Done!\n", 'H');
	ft_printf("Print a String: %s. Done!\n", "Hello World");
	ft_printf("Print a Integer: %d. Done!\n", 4);
	ft_printf("Print a Neg Interger: %d. Done!\n", -4);
	ft_printf("Print a Zero: %d. Done!\n", 0);
	ft_printf("Print a Hex Integer: %x. Done!\n", 4);
	ft_printf("Print a Hex Zero: %x. Done!\n", 0);
	ft_printf("Print a Pointers: %p. Done!\n", ptr_to_main);
	ft_putstr("\nFin du code!");
}