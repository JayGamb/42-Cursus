/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkdlist_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:24 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/16 16:58:04 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_list	*list_init(t_list *stack, int value)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!stack || !element)
	{
		if (stack == NULL)
			free(element);
		if (element == NULL)
			free(stack);
		exit (EXIT_FAILURE);
	}
	element->val = value;
	element->nxt = NULL;
	element->prev = NULL;
	stack->first = element;
	return (stack);
} */

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
		current = current->nxt;
	}
	ft_printf("----------\n");
}
