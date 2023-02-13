/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:27:34 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/11 15:15:43 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list *stack)
{
	t_element	*temp;

	if (!stack->first || !stack->first->nxt)
		return ;
	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->nxt = NULL;
	temp->nxt = stack->first;
	temp->prev = NULL;
	stack->first->prev = temp;
	stack->first = temp;
}

void	rra_rrb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "rra") == 0)
		reverse(stack_a);
	else if (ft_strcmp(inst, "rrb") == 0)
		reverse(stack_b);
	else if (ft_strcmp(inst, "rrr") == 0)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
	ft_printf("%s\n", inst);
}
