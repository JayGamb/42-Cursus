/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:27:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/23 15:45:46 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list *stack)
{
    t_element *temp;

    if (!stack->first || !stack->first->nxt)
        return;
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

void	push(t_list *dest, t_list *src)
{
	t_element	*temp;


	if (!src->first)
		return ;
		
	temp = src->first;
	if (src->first->nxt)
	{
		src->first = src->first->nxt;
		src->first->prev = NULL;
	}
	if (!dest->first)
	{
		dest->first = temp;
		dest->first->nxt = NULL;
		dest->first->prev = NULL;
	}
	else
	{
		
		temp->nxt = dest->first;
		dest->first->prev = temp;
		if (!dest->first->nxt)
			dest->last = dest->first;
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