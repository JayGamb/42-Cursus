/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:18:16 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/17 18:05:48 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fix_ops_b(int ops_b, int current_pos, int closest_pos)
{
	if (ops_b <= 0)
		ops_b++;
	if (current_pos > closest_pos)
		ops_b--;
	return (ops_b);
}

int	get_closest(t_element *element, t_list *stack_b)
{
	int			var[4];
	t_element	*comp_b;

	comp_b = stack_b->first;
	var[0] = comp_b->pos;
	var[2] = comp_b->pos;
	var[1] = ft_abs(element->pos - comp_b->pos);
	var[3] = 1;
	comp_b = comp_b->nxt;
	while (comp_b)
	{
		if (ft_abs(element->pos - comp_b->pos) <= var[1])
		{
			var[1] = ft_abs(element->pos - comp_b->pos);
			var[0] = comp_b->pos;
		}
		if (comp_b->pos > var[2])
			var[2] = comp_b->pos;
		if (element->pos > comp_b->pos)
			var[3] = 0;
		comp_b = comp_b->nxt;
	}
	if (var[0] == 1 && var[0] != var[2] && var[3])
		var[0] = var[2];
	return (var[0]);
}

int	count_op(t_list *stack, int position)
{
	int			i;
	int			ops;
	int			size;

	size = stack_size(stack);
	if (size == 1)
		return (0);
	i = get_index(stack, position);
	ops = 0;
	if (i < size / 2)
		ops = i;
	else
		ops = (i - size);
	return (ops);
}

t_element	*min_ops(t_list *stack_a, t_list *stack_b, int l1)
{
	t_element	*best_option;
	t_element	*current;
	int			var[3];

	current = stack_a->first;
	var[0] = 501;
	best_option = 0;
	while (current)
	{
		put_index(stack_a);
		if ((current->index >= 0 && current->index <= l1)
			/* || (current->index <= l2 && current->index >= l2) */)
		{
			var[1] = count_op(stack_a, current->pos);
			var[2] = count_op(stack_b, get_closest(current, stack_b));
			fix_ops_b(var[2], current->pos, get_closest(current, stack_b));
			if (total_ops(var[1], var[2]) < var[0])
			{
				best_option = current;
				var[0] = total_ops(var[1], var[2]);
			}
		}
		current = current->nxt;
	}
	return (best_option);
}

t_best_ops	cheapest_op(t_list *stack_a, t_list *stack_b)
{
	t_best_ops	cheap;
	int			limit[2];

	if (stack_size(stack_a) + stack_size(stack_b) <= 250)
	{
		limit[0] = 5;
		limit[1] = limit[0];
	}
	if (stack_size(stack_a) + stack_size(stack_b) > 250)
	{
		limit[0] = 10;
		limit[1] = limit[0];
	}
	cheap.best_pos = min_ops(stack_a, stack_b, limit[0]);
	cheap.closest_pos = get_closest(cheap.best_pos, stack_b);
	cheap.ops_a = count_op(stack_a, cheap.best_pos->pos);
	cheap.ops_b = count_op(stack_b, cheap.closest_pos);
	return (cheap);
}
