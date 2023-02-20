/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:52 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/20 13:51:41 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
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
		if (val > INT_MAX || !is_all_digits(array[i]))
			return (1);
		stacking(stack, (int)val);
		i++;
	}
	return (0);
}

int	check_args(char **array, t_list *stack_a, t_list *stack_b)
{
	if (pushatoi(stack_a, array))
	{
		free_all(stack_a, stack_b);
		free(array);
		error();
	}
	get_position(stack_a);
	if (find_occurrences(stack_a))
	{
		free_all(stack_a, stack_b);
		free(array);
		error();
	}
	free(array);
	return (0);
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
