/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:26:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/11 15:01:33 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_element	*temp;

	if (!stack->first || !stack->first->nxt)
		return ;
	temp = stack->first;
	stack->first = stack->first->nxt;
	temp->nxt = stack->first->nxt;
	stack->first->prev = NULL;
	if (temp->nxt)
		temp->nxt->prev = temp;
	else
		stack->last = temp;
	stack->first->nxt = temp;
	temp->prev = stack->first;
}

void	sa_sb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(inst, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(inst, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	ft_printf("%s\n", inst);
}
