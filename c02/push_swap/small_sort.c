/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:43:14 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/19 14:40:03 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list *stack_a, t_list *stack_b)
{
	int	comb;

	comb = get_permutation(stack_a);
	if (comb == 132)
		instructionsf(2, stack_a, stack_b, RRA, SA);
	if (comb == 213)
		sa_sb(stack_a, stack_b, SA);
	if (comb == 231)
		rra_rrb(stack_a, stack_b, RRA);
	if (comb == 312)
		ra_rb(stack_a, stack_b, RA);
	if (comb == 321)
		instructionsf(2, stack_a, stack_b, SA, RRA);
}

void	sort_four(t_list *stack_a, t_list *stack_b)
{
	int	comb;

	comb = get_permutation(stack_a);
	if (comb == 1243 || comb == 1324 || comb == 1432
		|| comb == 2143 || comb == 2314)
		instructionsf(2, stack_a, stack_b, PB, SA);
	if (comb == 1342 || comb == 3124 || comb == 4231)
		instructionsf(4, stack_a, stack_b, RRA, SA, RA, RA);
	if (comb == 2341 || comb == 3412 || comb == 3421)
		instructionsf(3, stack_a, stack_b, RRA, RRA, SA);
	if (comb == 2413 || comb == 3214)
		instructionsf(5, stack_a, stack_b, RRA, SA, RRA, RRA, SA);
	if (comb == 2134 || comb == 1423 || comb == 4312 || comb == 4321)
		instructionsf(4, stack_a, stack_b, SA, RA, RA, SA);
	if (comb == 3142 || comb == 3241)
		instructionsf(4, stack_a, stack_b, SA, RRA, SA);
	if (comb == 4123 || comb == 4213 || comb == 2431)
		instructionsf(4, stack_a, stack_b, RA, SA, RA, RA);
	if (comb == 4132)
		instructionsf(2, stack_a, stack_b, SA, PB);
}

int second_smallest(t_list *stack) {
	int smallest = stack->first->pos;
	int second_smallest = 501;
	t_element *current = stack->first;

	while (current != NULL) {
		int pos = current->pos;

		if (pos < smallest) {
			second_smallest = smallest;
			smallest = pos;
		} else if (pos < second_smallest && pos != smallest) {
			second_smallest = pos;
		}
		current = current->nxt;
	}
	return second_smallest;
}

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = second_smallest(stack_a);
	i = get_index(stack_a, i);
	if (i == 0)
		instructionsf(1, stack_a, stack_b, PB);
	if (i == 1)
		instructionsf(2, stack_a, stack_b, SA, PB);
	if (i == 2)
		instructionsf(3, stack_a, stack_b, RA, RA, PB);
	if (i == 3)
		instructionsf(3, stack_a, stack_b, RRA, RRA, PB);
	if (i == 4)
		instructionsf(2, stack_a, stack_b, RRA, PB);
}

void	small_sort(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 2)
		instructions(1, stack_a, stack_b, SA);
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
