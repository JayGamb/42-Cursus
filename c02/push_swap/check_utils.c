/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:52 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/10 16:10:33 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || str[i] == '-'
			|| str[i] == '+' || str[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	find_occurrences(t_list *stack)
{
	t_element	*current;
	t_element	*comp;

	current = stack->first;
	while (current)
	{
		comp = current->nxt;
		while (comp)
		{
			if (current->pos == comp->pos)
				return (1);
			comp = comp->nxt;
		}
		current = current->nxt;
	}
	return (0);
}

int	pushatoi(t_list *stack, char **array)
{
	size_t	i;
	long	val;

	i = 0;
	val = 0;
	while (array[i])
	{
		val = ft_atol(array[i]);
		if (val > INT_MAX || val < INT_MIN || !is_all_digits(array[i]))
			return (1);
		stacking(stack, (int)val);
		i++;
	}
	return (0);
}

int	check_stack(t_list *stack_a, t_list *stack_b)
{
	get_position(stack_a);
	if (find_occurrences(stack_a))
	{
		free_all(stack_a);
		free_all(stack_b);
		error();
		return (1);
	}
	if (check_sort(stack_a))
	{
		free_all(stack_a);
		free_all(stack_b);
		return (1);
	}
	return (0);
}

int	check_args(char **array, t_list *stack_a, t_list *stack_b)
{
	if (pushatoi(stack_a, array))
	{
		error();
		return (1);
	}
	if (check_stack(stack_a, stack_b))
		return (1);
	return (0);
}
