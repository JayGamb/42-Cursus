/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/22 18:07:20 by jgamboa-         ###   ########.fr       */
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
	
	sort_three(stack_a, stack_b);
	

	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n");

/* 	sort_three(stack_a, stack_b); */
}