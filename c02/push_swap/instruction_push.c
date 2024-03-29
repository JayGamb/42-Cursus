/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:21:48 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 14:55:35 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_push(char *inst)
{
	return (ft_strcmp(inst, PA) == 0 || ft_strcmp(inst, PB) == 0);
}

void	push(t_list *dest, t_list *src)
{
	t_element	*temp;

	if (!src->first)
		return ;
	temp = src->first;
	if (src->first == src->last)
	{
		src->first = NULL;
		src->last = NULL;
	}
	else
	{
		src->first = temp->nxt;
		src->first->prev = NULL;
	}
	temp->nxt = dest->first;
	temp->prev = NULL;
	if (dest->first)
		dest->first->prev = temp;
	dest->first = temp;
	if (!dest->last)
		dest->last = temp;
}

void	pa_pb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(inst, "pb") == 0)
		push(stack_b, stack_a);
	ft_printf("%s\n", inst);
}
