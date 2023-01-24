/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/24 16:44:30 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;


	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));	
	check_args(argc, argv, stack_a);
	int size = check_sort(stack_a);
/* 	printf("List:\n");
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n"); */
	if (size == 3)
		sort_three(stack_a, stack_b);
	if (size == 4)
		sort_four(stack_a, stack_b);
	if (size == 5)
		sort_five(stack_a, stack_b);

/* 	printf("\nfin de la Liste:\n"); */
/* 	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n"); */

/* 	t_element *current = stack_a->first;
	while (current)
	{
	 printf("A l'index %d -> %d\n", current->index, current->val);
	 current = current->nxt;

	}
	printf("index %d\n", stack_a->first->index); */
	

/* 	sort_three(stack_a, stack_b); */
}