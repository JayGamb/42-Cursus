/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/02 19:10:04 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_list *stack)
{
	t_element	*current;
	int size;


	size = 0;
    current = stack->first;
    while (current)
    {
		current = current->nxt;
	 	size++;
    }
	return (size);
}

int	smallest_diff(t_element *element, t_list *stack_b)
{
	t_element	*comp_b;
	int			biggest;

	comp_b = stack_b->first; 
	biggest = comp_b->pos;
	while (comp_b)
	{
		if (element->pos > comp_b->pos)
		{
			if (element->pos - comp_b->pos < element->pos - biggest)
				biggest = comp_b->pos;
		}
		comp_b = comp_b->nxt;
	}
	return(biggest); 
}

int	count_op(t_list *stack_b, int pos, int size)
{
	t_element	*current;
	int			i;

	current = stack_b->first;
	i = 0;
	while (current)
	{
		if (current->pos == pos)
			break ;
		i++;
		current = current->nxt;
	}
	if (i <= size / 2)
		return (i);
	else
		return (size - i);
}

/* void big_sort(t_list *stack_a, t_list *stack_b)
{
    get_position(stack_a);
    
    instructionsf(2, stack_a, stack_b, "pb", "pb");
    if ()

} */