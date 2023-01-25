/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/25 20:58:12 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdarg.h>

void instructionstest(int num, ...) {
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; i++) {
        char *instruction = va_arg(args, char*);
        // Perform the instruction here
        printf("Performing instruction: %s\n", instruction);
    }
    va_end(args);
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	int size;


	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));	
	check_args(argc, argv, stack_a);
	size = check_sort(stack_a);


/* 	printf("List:\n");
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n"); */
	if (size == 3)
		sort_three(stack_a, stack_b);
	if (size == 4)
		sort_four2(stack_a, stack_b);
	if (size == 5)
		sort_five(stack_a, stack_b);
	
/* 	printf("List:\n");
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n"); */
}