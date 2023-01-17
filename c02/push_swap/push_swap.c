/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/17 18:09:12 by jgamboa-         ###   ########.fr       */
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
/* 	list */

	ft_printf("\nfirst element : %d\n", stack_a->first->val);
	ft_printf("next element : %d\n", stack_a->first->nxt->val);
	ft_printf("Prev element de next du first : %d\n", stack_a->first->nxt->prev->val);
	ft_printf("last element : %d\n\n", stack_a->last->val);
	 printlist(stack_a);
	 ft_printf("A\n\n");
	 printlist(stack_b);
	 ft_printf("B\n\n");

	 ft_printf("\nஜ۩ PUSH_SWAP ۩ஜ\n");
	instructions(stack_a, stack_b, "pb");
	instructions(stack_a, stack_b, "pb");
	instructions(stack_a, stack_b, "pb");
	instructions(stack_a, stack_b, "pb");
	ft_printf("\nfirst element : %d\n", stack_a->first->val);
	ft_printf("next element : %d\n", stack_a->first->nxt->val);
	ft_printf("Prev element de next du first : %d\n", stack_a->first->nxt->prev->val);
	ft_printf("last element : %d\n", stack_a->last->val);
	 printlist(stack_a);
	 ft_printf("A\n\n");
	 printlist(stack_b);
	 ft_printf("B\n\n");

	 ft_printf("\nஜ۩ PUSH_SWAP ۩ஜ\n");
	instructions(stack_a, stack_b, "rrr");
	ft_printf("\nfirst element : %d\n", stack_a->first->val);
	ft_printf("next element : %d\n", stack_a->first->nxt->val);
	ft_printf("Prev element de next du first : %d\n", stack_a->first->nxt->prev->val);
	ft_printf("last element : %d\n", stack_a->last->val);
	 printlist(stack_a);
	 ft_printf("A\n\n");
	 printlist(stack_b);
	 ft_printf("B\n\n");

	instructions(stack_a, stack_b, "pa");
	instructions(stack_a, stack_b, "sa");
	instructions(stack_a, stack_b, "pb");
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n");


	instructions(stack_a, stack_b, "rr");
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n");
}
