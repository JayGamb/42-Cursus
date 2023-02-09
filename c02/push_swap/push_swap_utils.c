/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:27:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/09 16:41:14 by jgamboa-         ###   ########.fr       */
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


void push(t_list *dest, t_list *src) 
{
	 t_element *temp;

    if (!src->first)
        return;
    temp = src->first;
    if (src->first == src->last) 
        src->first = src->last = NULL;
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

/* void   reverse(t_list *stack)
{
    t_element    *temp_first;
    t_element    *temp_last;
    t_element    *temp_second;

    if (stack->first == NULL || stack->last == NULL)
        return ;
    temp_first = stack->first;
    temp_last = stack->last;
    temp_second = temp_first->nxt;
    stack->first = temp_second;
    temp_second->prev = NULL;
    stack->last = temp_first;
    temp_first->nxt = NULL;
    temp_first->prev = temp_last;
    temp_last->nxt = stack->first;
} */