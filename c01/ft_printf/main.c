/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:57:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/20 22:38:27 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int main ()
{
	int a;
	int b;
	void *ptr_to_main = &b;

	ft_printf("format 'c' %c. OK!\n", 'H');
	ft_printf("format 's': %s. OK!\n", "Hello World");
	ft_printf("format 'p': %p. OK!\n", ptr_to_main);
	ft_printf("format 'd': %d. OK!\n", 4);
	ft_printf("format 'i': %i. OK!\n", 4);
	ft_printf("format 'u': %u. OK!\n", 56);
	ft_printf("format 'x': %x. OK!\n", 8);
	ft_printf("format 'X': %X. OK!\n", 45);

	// printf("\nFin du code!\n\n");


	printf("--- TEST DU LENGHT A: ---\n");
	printf("variable a avec printf() printf return: \n");
	a = printf("afs");
	printf("lenght de la vraible a avec printf(): \t");
	printf("%d\n", a);
	printf("lenght de la vraible a avec ft_printf(): \t");
	ft_printf("%d\n", a);


	printf("\n\n--- TEST DU LENGHT b: ---\n");
	ft_printf("variable b avec ft_printf() ft_printf return: \n");
	b = ft_printf("");
	ft_printf("lenght de la vraible b avec fT_printf(): \t");
	ft_printf("%d\n", b);
	ft_printf("lenght de la vraible b avec printf(): \t");
	printf("%d\n", b);

}