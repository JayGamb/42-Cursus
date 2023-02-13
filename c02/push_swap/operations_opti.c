/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:18:16 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/13 20:57:39 by jgamboa-         ###   ########.fr       */
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
	t_element	*comp_b;
	int			closest_pos;
	int			closest_difference;
	int			greatest;
	int			found_smaller;

	comp_b = stack_b->first;
	closest_pos = comp_b->pos;
	greatest = comp_b->pos;
	closest_difference = ft_abs(element->pos - comp_b->pos);
	found_smaller = 1;
	comp_b = comp_b->nxt;
	while (comp_b)
	{
		if (ft_abs(element->pos - comp_b->pos) <= closest_difference)
		{
			closest_difference = ft_abs(element->pos - comp_b->pos);
			closest_pos = comp_b->pos;
		}
		if (comp_b->pos > greatest)
			greatest = comp_b->pos;
		if (element->pos > comp_b->pos)
			found_smaller = 0;
		comp_b = comp_b->nxt;
	}
	if (closest_pos == 1 && closest_pos != greatest && found_smaller)
		closest_pos = greatest;
	return (closest_pos);
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

/* t_element	*min_ops(t_list *stack_a, t_list *stack_b)
{
	t_element	*best_option;
	t_element	*current;
	int			last_option;
	int			ops_a;
	int			ops_b;

	current = stack_a->first;
	last_option = 501;
	best_option = 0;
	while (current)
	{
		put_index(stack_a);
		if ((current->index >= 0 && current->index <= stack_size(stack_a) /4) ||
			(current->index <= stack_size(stack_a) - 1  && current->index >= (stack_size(stack_a) -1) - (stack_size(stack_a) -1) /4))
		{
			ops_a = count_op(stack_a, current->pos);
			ops_b = count_op(stack_b, get_closest(current, stack_b));
			fix_ops_b(ops_b, current->pos, get_closest(current, stack_b));
			if (total_ops(ops_a, ops_b) < last_option)
			{
				best_option = current;
				last_option = total_ops(ops_a, ops_b);
			}
		}
		current = current->nxt;
	}
	return (best_option);
} */

t_element	*min_ops(t_list *stack_a, t_list *stack_b, int limit_1, int limit_2, int limit_3)
{
	t_element	*best_option;
	t_element	*current;
	int			last_option;
	int			ops_a;
	int			ops_b;

	current = stack_a->first;
	last_option = 501;
	best_option = 0;
	while (current)
	{
		put_index(stack_a);
		if ((current->index >= 0 && current->index <= limit_1) ||
			(current->index <= limit_2 && current->index >= limit_3))
		{
			ops_a = count_op(stack_a, current->pos);
			ops_b = count_op(stack_b, get_closest(current, stack_b));
			fix_ops_b(ops_b, current->pos, get_closest(current, stack_b));
			if (total_ops(ops_a, ops_b) < last_option)
			{
				best_option = current;
				last_option = total_ops(ops_a, ops_b);
			}
		}
		current = current->nxt;
	}
	return (best_option);
}

t_best_ops	cheapest_op(t_list *stack_a, t_list *stack_b)
{
	t_best_ops	cheap;

	cheap.best_pos = min_ops(stack_a, stack_b, 6, 12, 25);
	cheap.closest_pos = get_closest(cheap.best_pos, stack_b);
	cheap.ops_a = count_op(stack_a, cheap.best_pos->pos);
	cheap.ops_b = count_op(stack_b, cheap.closest_pos);
	return (cheap);
}
