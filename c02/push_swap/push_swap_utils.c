/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:27:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/03 21:01:17 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sa(t_list *stack_a, t_list *stack_b)
// {

// 	int n;

// 	n = stack_a->first->val;
// 	if (stack_b->first->val == 0 && stack_b->first->nxt == NULL)
// 	{
// 		deletion(stack_b);
// 		stacking(stack_b, n);
		
// 	}
// }

void swap(t_list *list)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->first = list->first->nxt;
	list->first->nxt = temp->first->nxt;
	temp->first->nxt = list->first;
	list->first = temp->first;
	free(temp);
}