/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkdlist_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:24 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/16 18:39:13 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_init(t_list *stack, int value)
{
	t_element   *element;

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
}

void stacking(t_list *stack, int new_val)
{
	t_element *new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element || !stack)
		exit(EXIT_FAILURE);
	new_element->val = new_val;
	new_element->prev = stack->last;
	new_element->nxt = NULL;
	if (stack->first != NULL)
	{
		if (stack->last == NULL)
		{
			stack->first->nxt = new_element;
			stack->last = new_element;
			new_element->prev = stack->first;
		}
		stack->last->nxt = new_element;
		stack->last = new_element;
	}
	else
		stack->first = new_element;
}

void deletion(t_list *stack)
{
	t_element *eltodel;

	if (!stack)
		exit(EXIT_FAILURE);
	if (stack->first != 0)
	{
		eltodel = stack->first;
		stack->first = stack->first->nxt;
		free(eltodel);
	}
}

void printlist(t_list *stack)
{
	t_element *current;
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
		ft_printf("%d\n", current->val);
		current = current->nxt;
	}
	ft_printf("----------\n");
}

void printstacks(t_list *list_a, t_list *list_b)
{
	t_element *current_a;
	t_element *current_b;

	if (!list_a)
	{
		ft_printf("NOP!");
		exit(EXIT_FAILURE);
	}
	current_a = list_a->first;
	current_b = list_b->first;
	while (current_a != NULL )
	{
		ft_printf("%d\t\t", current_a->val);
		if (!current_b->val)
		{
			ft_printf(" \n");
		}
		else
		{
			ft_printf("%d\n", current_b->val);
			current_b = current_b->nxt;
		}
		current_a = current_a->nxt;
		
	}
	ft_printf("----------\t----------\n");
	ft_printf("A\t\tB\n");
}
