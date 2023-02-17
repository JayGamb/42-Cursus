/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/17 17:23:29 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdarg.h>

void	free_stack(t_list *stack_a)
{
	t_element	*current;
	t_element	*comp;

	current = stack_a->first;
	while (current || comp)
	{
		if (current->nxt)
		{
			current = comp->nxt;
			free(comp);
		}
		else if (comp->nxt)
		{
		comp = current->nxt;
			free(current);
		}
		else
		{
			free(comp);
			free(current);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		exit (1);
	check_args(argc, argv, stack_a);
	if (check_sort(stack_a))
		exit(1);
	size_a = stack_size(stack_a);
	if (size_a < 6)
		small_sort(stack_a, stack_b, size_a);
	else
		big_sort(stack_a, stack_b);
	free_stack(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
