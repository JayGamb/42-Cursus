/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:08:54 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/21 12:39:53 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <libc.h>

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list args);
int			ft_printchar(char c);
int			ft_dectohex_min(unsigned int decimal);
int			ft_dectohex_min_ptr(unsigned long long decimal);
int			ft_dectohex_maj(unsigned int n);
int			ft_hexminmaj(char c, va_list args);
int			ft_intoa(int n);
int			ft_uitoa(unsigned int n);
int			ft_printstr(const char *str);
int			ft_charstr(char c, va_list args);

#endif