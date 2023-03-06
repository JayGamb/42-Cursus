/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:24 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 15:46:52 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacking(t_list *stack, int new_val)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element || !stack)
		exit(EXIT_FAILURE);
	new_element->val = new_val;
	new_element->prev = stack->last;
	new_element->nxt = NULL;
	if (stack->first != NULL)
	{
		stack->last->nxt = new_element;
		stack->last = new_element;
	}
	else
	{
		stack->first = new_element;
		stack->last = new_element;
	}
}

int	stack_size(t_list *stack)
{
	t_element	*current;
	int			size;

	size = 0;
	current = stack->first;
	while (current)
	{
		current = current->nxt;
		size++;
	}
	return (size);
}

void	printlist(t_list *stack)
{
	t_element	*current;

	if (!stack)
	{
		ft_printf("NOP!");
		exit(EXIT_FAILURE);
	}
	if (!stack->first)
		ft_printf("(empty stack)\n");
	current = stack->first;
	while (current != NULL)
	{
		ft_printf("%d\t", current->val);
		printf("%d\n", current->pos);
		current = current->nxt;
	}
	ft_printf("----------\n");
}

int	check_sort(t_list *stack)
{
	t_element	*current;
	int			is_sorted;

	is_sorted = 1;
	current = stack->first;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
				is_sorted = 0;
		}
		current = current->nxt;
	}
	return (is_sorted);
}
