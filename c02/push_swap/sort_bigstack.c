/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 14:59:31 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(int ops_a, int ops_b)
{
	int	total_ops;

	total_ops = 0;
	ops_a = ft_abs(ops_a);
	ops_b = ft_abs(ops_b);
	if (ops_a == ops_b)
		total_ops = (ops_b + ops_a) / 2;
	else if (ops_a > ops_b)
		total_ops = ops_a - ops_b;
	else if (ops_a < ops_b)
		total_ops = ops_b - ops_a;
	return (total_ops + 1);
}

void	pa_sorting(t_list *stack_a, t_list *stack_b)
{
	t_best_ops	c;

	while (stack_size(stack_b) > 0)
	{
		c.closest_pos = get_closest(stack_b->first, stack_a);
		c.ops_a = count_op(stack_a, c.closest_pos);
		rotrev_ops(stack_a, stack_b, c.ops_a, "a");
		if (stack_b->first->pos < c.closest_pos)
			pa_pb(stack_a, stack_b, PA);
		else
			instructions(2, stack_a, stack_b, RA, PA);
	}
	c.ops_a = count_op(stack_a, 1);
	rotrev_ops(stack_a, stack_b, c.ops_a, "a");
}

void	big_sort(t_list *stack_a, t_list *stack_b)
{
	t_best_ops	c;

	instructions(2, stack_a, stack_b, PB, PB);
	while (stack_size(stack_a) > 3)
	{
		c = cheapest_op(stack_a, stack_b);
		if (c.best_pos->pos < c.closest_pos)
			c.ops_b++;
		c.ops_ab = rrr_ops(c.ops_a, c.ops_b);
		rotrev_ops(stack_a, stack_b, c.ops_ab, "r");
		rotrev_ops(stack_a, stack_b, c.ops_a - c.ops_ab, "a");
		rotrev_ops(stack_a, stack_b, c.ops_b - c.ops_ab, "b");
		pa_pb(stack_a, stack_b, PB);
	}
	sort_three(stack_a, stack_b);
	pa_sorting(stack_a, stack_b);
}
