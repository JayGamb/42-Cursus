/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:27:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/16 16:47:02 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_element	*temp;

	if (!stack->first)
		return ;
	temp = stack->first->nxt;
	stack->first->prev = temp;
	stack->first->nxt = temp->nxt;
	temp->prev = NULL;
	temp->nxt = stack->first;
	stack->first = temp;
}

void	push(t_list *dest, t_list *src)
{
	t_element	*temp;


	if (!src->first)
		return ;
	temp = src->first;
	src->first = src->first->nxt;
	src->first->prev = temp->prev;
	if (!dest->first)
		list_init(dest, temp->val);
	else if (!dest->first->nxt)
	{
		temp->nxt = dest->first;
		dest->first->prev = temp;
		dest->last = temp->nxt;
		dest->first =  temp;
	}
	else
	{
		temp->nxt = dest->first;
		dest->first->prev = temp;
		dest->first =  temp;

	}		

}

void	rotate(t_list *stack)
{
	t_element	*temp;
	
	if (!stack->first && !stack->first->nxt)
		return ;
	temp = stack->first;
	stack->first = stack->first->nxt;
	stack->first->prev = NULL;
	temp->prev = stack->last;
	temp->nxt = NULL;
	stack->last->nxt = temp;
	stack->last = temp;
}

void	reverse(t_list *stack)
{
	t_element	*temp;
	
	if (!stack->first && !stack->first->nxt)
		return ;
	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->nxt = NULL;
	temp->nxt = stack->first;
	temp->prev = NULL;
	stack->first->prev = temp;
	stack->first = temp;
}