/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:27:34 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 15:28:10 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ft_strcmp(stack_name, "a") == 0)
	{
		while (ops++ < 0)
			rra_rrb(stack_a, stack_b, "rra");
	}
	else if (ft_strcmp(stack_name, "b") == 0)
	{
		while (ops++ < 0)
			rra_rrb(stack_a, stack_b, "rrb");
	}
	else
	{
		while (ops++ < 0)
			rra_rrb(stack_a, stack_b, "rrr");
	}
}

void	rotate_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ft_strcmp(stack_name, "a") == 0)
	{
		while (ops-- > 0)
			ra_rb(stack_a, stack_b, "ra");
	}
	else if (ft_strcmp(stack_name, "b") == 0)
	{
		while (ops-- > 0)
			ra_rb(stack_a, stack_b, "rb");
	}
	else
	{
		while (ops-- > 0)
			ra_rb(stack_a, stack_b, "rr");
	}
}

void	rotrev_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ops < 0)
		reverse_ops(stack_a, stack_b, ops, stack_name);
	else if (ops > 0)
		rotate_ops(stack_a, stack_b, ops, stack_name);
}

void	reverse(t_list *stack)
{
	t_element	*temp;

	if (!stack->first || !stack->first->nxt)
		return ;
	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->nxt = NULL;
	temp->nxt = stack->first;
	temp->prev = NULL;
	stack->first->prev = temp;
	stack->first = temp;
}

void	rra_rrb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "rra") == 0)
		reverse(stack_a);
	else if (ft_strcmp(inst, "rrb") == 0)
		reverse(stack_b);
	else if (ft_strcmp(inst, "rrr") == 0)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
	ft_printf("%s\n", inst);
}
