/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/19 14:46:23 by jgamboa-         ###   ########.fr       */
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

void	rotate_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ops < 0)
	{
		while (ops++ < 0)
			rra_rrb(stack_a, stack_b, ft_strjoin("rr", stack_name));
	}
	else if (ops > 0)
	{
		while (ops-- > 0)
			ra_rb(stack_a, stack_b, ft_strjoin("r", stack_name));
	}
}

void	pa_sorting(t_list *stack_a, t_list *stack_b)
{
	t_best_ops	c;

	while (stack_size(stack_b) > 0)
	{

		c.closest_pos = get_closest(stack_b->first, stack_a);
		c.ops_a = count_op(stack_a, c.closest_pos);
		rotate_ops(stack_a, stack_b, c.ops_a, "a");
		if (stack_b->first->pos < c.closest_pos)
			pa_pb(stack_a, stack_b, PA);
		else
			instructions(2, stack_a, stack_b, RA, PA);
	}
	c.ops_a = count_op(stack_a, 1);
	rotate_ops(stack_a, stack_b, c.ops_a, "a");
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
		rotate_ops(stack_a, stack_b, c.ops_ab, "r");
		rotate_ops(stack_a, stack_b, c.ops_a - c.ops_ab, "a");
		rotate_ops(stack_a, stack_b, c.ops_b - c.ops_ab, "b");
		pa_pb(stack_a, stack_b, PB);
	}
	sort_three(stack_a, stack_b);
	pa_sorting(stack_a, stack_b);
}