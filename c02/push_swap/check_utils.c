/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:52 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/03 18:30:46 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

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

int	check_args(int argc, int is_array, char **array, t_list *stack_a, t_list *stack_b)
{
	if (argc == 2)
	{
		if (is_array == 1)
		{
			free_array(array);
			free(array);
		}
	}
	if (pushatoi(stack_a, array))
	{
		error();
	}
	get_position(stack_a);
	if (find_occurrences(stack_a))
	{
		free_all(stack_a);
		free_all(stack_b);
		error();
	}
	if (check_sort(stack_a))
	{
		free_all(stack_a);
		free_all(stack_b);
		exit(1);
	}
	return (0);
}
