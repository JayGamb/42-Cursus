/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:27:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/14 17:18:44 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_swap(char *inst)
{
	return (ft_strcmp(inst, SA) == 0 || ft_strcmp(inst, SB) == 0
		|| ft_strcmp(inst, SS) == 0);
}

int	is_push(char *inst)
{
	return (ft_strcmp(inst, PA) == 0 || ft_strcmp(inst, PB) == 0);
}

int	is_rotate(char *inst)
{
	return (ft_strcmp(inst, RA) == 0 || ft_strcmp(inst, RB) == 0
		|| ft_strcmp(inst, RR) == 0);
}

int	is_reverse(char *inst)
{
	return (ft_strcmp(inst, RRA) == 0 || ft_strcmp(inst, RRB) == 0
		|| ft_strcmp(inst, RRR) == 0);
}

int	stack_size(t_list *stack)
{
	t_element	*current;
	int			size;

	size = 0;
	current = stack->first;
	while (current)
	{
		current = current->nxt;
		size++;
	}
	return (size);
}
