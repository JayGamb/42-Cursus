/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:23:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 15:46:30 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr_ops(int ops_a, int ops_b)
{
	int	ops_ab;

	ops_ab = 0;
	if ((ops_a > 0 && ops_b > 0) || (ops_a < 0 && ops_b < 0))
	{
		if (ops_a > ops_b)
		{
			ops_ab = ops_b;
			ops_a = ops_a - ops_b;
			ops_b = 0;
		}
		else
		{
			ops_ab = ops_a;
			ops_b = ops_b - ops_a;
			ops_a = 0;
		}
	}
	return (ops_ab);
}

int	is_rotate(char *inst)
{
	return (ft_strcmp(inst, RA) == 0 || ft_strcmp(inst, RB) == 0
		|| ft_strcmp(inst, RR) == 0);
}

int	is_reverse(char *inst)
{
	return (ft_strcmp(inst, RRA) == 0 || ft_strcmp(inst, RRB) == 0
		|| ft_strcmp(inst, RRR) == 0);
}

void	rotate(t_list *stack)
{
	t_element	*temp;

	if (!stack->first && !stack->first->nxt)
		return ;
	temp = stack->first;
	stack->first = stack->first->nxt;
	stack->first->prev = NULL;
	temp->prev = stack->last;
	temp->nxt = NULL;
	stack->last->nxt = temp;
	stack->last = temp;
}

void	ra_rb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(inst, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(inst, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	ft_printf("%s\n", inst);
}
