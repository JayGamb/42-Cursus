/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:19 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/12 13:46:27 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list *stack)
{
	t_element	*current;
	int			index;
	
	index = 0;
	current = stack->first;
	while (current)
	{
		current->index = index;
		current = current->nxt;
		index++;
	}
}

int	get_index(t_list *stack, int pos)
{
	t_element	*current;
	put_index(stack);
	current = stack->first;
	while (current)
	{
		if (current->pos == pos)
		{
			break ;
		}
		current = current->nxt;
	}
	return (current->index);
}

void	get_position(t_list *stack)
{
	t_element	*current;
	t_element	*comp;

	current = stack->first;
	while (current)
	{
		if (current->pos)
			current->pos = 0;
		current = current->nxt;
	}
	current = stack->first;
	while (current)
	{
		comp = stack->first;
		while (comp)
		{
			if (current->val > comp->val)
				current->pos--;
			comp = comp->nxt;
		}
		current->pos += current->pos * -2 + 1;
		current = current->nxt;
	}
}

int	get_permutation(t_list *stack)
{	
	t_element	*current;
	int			comb;
	int			*array;
	int			i;

	array = malloc(sizeof(int) * stack_size(stack));
	current = stack->first;
	i = 0;
	while (current)
	{
		array[i++] = current->pos;
		current = current->nxt;
	}
	get_position(stack);
	current = stack->first;
	comb = 0;
	i = 0;
	while (current)
	{
		comb = comb * 10 + current->pos;
		current->pos = array[i];
		current = current->nxt;
		i++;
	}
	return (comb);
}
