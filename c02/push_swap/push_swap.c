/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/02 19:24:38 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdarg.h>

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;


	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));	
	check_args(argc, argv, stack_a);
	get_position(stack_a);


	int size = stack_size(stack_a);
	instructionsf(4, stack_a, stack_b, "pb", "pb", "pb", "pb");
	int posdif = smallest_diff(stack_a->first, stack_b);
	int ops = count_op(stack_b, posdif, size);

	printf("List:\n");
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("b\n\n");

	
	ft_printf("size: %d\n", size);
	ft_printf("pos diff: %d\n", posdif);
	ft_printf("nb ops: %d\n", ops);

 


}