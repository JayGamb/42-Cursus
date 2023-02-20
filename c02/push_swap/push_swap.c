/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/20 12:31:43 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	free_stack(t_list *stack_a)
{
	t_element	*current;

	while (stack_a->first)
	{
		current = stack_a->first;
		stack_a->first = stack_a->first->nxt;
		free(current);
	}
} */

/* void	free_stack(t_list *stack_a)
{
	t_element	*current;
	t_element	*comp;

	current = stack_a->first;
	comp = stack_a->first;
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
} */

void free_stack(t_list *stack_a)
{
	t_element *current = stack_a->first;
	while (current)
	{
		t_element *next = current->nxt;
		free(current);
		current = next;
	}
	stack_a->first = NULL;
	stack_a->last = NULL;
}
void free_all(t_list *stack_a, t_list *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		exit(0);
	check_args(argc, argv, stack_a, stack_b);
	if (check_sort(stack_a))
	{
		free_all(stack_a, stack_b);
		return (0);
	}
	size_a = stack_size(stack_a);
	if (size_a <= 5)
		small_sort(stack_a, stack_b, size_a);
	else
		big_sort(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
