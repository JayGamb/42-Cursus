/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:05:43 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 15:31:06 by jgamboa-         ###   ########.fr       */
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

void	free_all(t_list *stack_a)
{
	if (stack_a->first)
		free_stack(stack_a);
	free(stack_a);
}

void	free_stack(t_list *stack_a)
{
	t_element	*current;
	t_element	*next;

	current = stack_a->first;
	while (current)
	{
		next = current->nxt;
		free(current);
		current = next;
	}
	stack_a->first = NULL;
	stack_a->last = NULL;
}
