/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:19 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/26 16:09:57 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int get_position(t_list *stack)
{
    t_element	*current;
	t_element	*comp;
	int			comb;
	int			index;
  
	comb = 0;
	index = 0;
	current = stack->first;
	while (current)
    {
		if (current->pos)
			current->pos = 0;
		if (current->index)
			current->index = 0;	
		current = current->nxt;
	}
	current = stack->first;
    while (current)
    {
		comp = stack->first;
		while (comp)
		{
			if (current->val > comp->val)
				current->pos--;
			comp = comp->nxt;
		}
		current->pos += current->pos * -2 + 1;
		comb = comb * 10 + current->pos;
		current->index += index;
		index++;
		current = current->nxt;
    }
	return (comb);
}

void sort_three(t_list *stack_a, t_list *stack_b)
{
	int comb = get_position(stack_a);

	if (comb == 132)
		instructionsf(2, stack_a, stack_b, "rra", "sa");
	if (comb == 213)
		sa_sb(stack_a, stack_b, "sa");
	if (comb == 231)
		rra_rrb(stack_a, stack_b, "rra");
	if (comb == 312)
		ra_rb(stack_a, stack_b, "ra");
	if (comb == 321)
		instructionsf(2, stack_a, stack_b, "sa", "rra");
}

void sort_four(t_list *stack_a, t_list *stack_b)
{
	t_element *current;
	
	get_position(stack_a);
	current = stack_a->first;
	while (current)
	{
		if (current->pos == 1)
			break;
		current = current->nxt;
	}
	if (current->index == 0)
		pa_pb(stack_a, stack_b, "pb");
	if (current->index == 1)
	{
		sa_sb(stack_a, stack_b, "sa");
		check_sort(stack_a);
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 2)
	{
		rra_rrb(stack_a, stack_b, "rra");
		rra_rrb(stack_a, stack_b, "rra");
		check_sort(stack_a);
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 3)
	{
		rra_rrb(stack_a, stack_b, "rra");
		check_sort(stack_a);
		pa_pb(stack_a, stack_b, "pb");
	}
	sort_three(stack_a, stack_b);
	pa_pb(stack_a,	stack_b, "pa");
}

void sort_five(t_list *stack_a, t_list *stack_b)
{
	t_element *current;
	get_position(stack_a);

	current = stack_a->first;
	while (current)
	{
		if (current->pos == 2)
			break;
		current = current->nxt;
	}
	if (current->index == 0)
		pa_pb(stack_a, stack_b, "pb");
	if (current->index == 1)
	{
		sa_sb(stack_a, stack_b, "sa");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 2)
	{
		ra_rb(stack_a, stack_b, "ra");
		ra_rb(stack_a, stack_b, "ra");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 3)
	{
		rra_rrb(stack_a, stack_b, "rra");
		rra_rrb(stack_a, stack_b, "rra");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 4)
	{
		rra_rrb(stack_a, stack_b, "rra");
		pa_pb(stack_a, stack_b, "pb");
	}
	sort_four(stack_a, stack_b);
	pa_pb(stack_a,	stack_b, "pa");
	sa_sb(stack_a, stack_b, "sa");
}

void sort_four2(t_list *stack_a, t_list *stack_b)
{
	int comb;

	comb = get_position(stack_a);
	if (comb == 1243 || comb == 1324 || comb == 1432 || comb == 2143 || comb == 2314)
		instructionsf(2, stack_a, stack_b, "pb","sa");
	if (comb == 1342 || comb == 3124 || comb == 4231)
		instructionsf(4, stack_a, stack_b, "rra", "sa", "ra", "ra");
	if (comb == 2341 || comb == 3412 || comb == 3421)
		instructionsf(3, stack_a, stack_b, "rra", "rra", "sa");
	if (comb == 2413 || comb == 3214)
		instructionsf(5, stack_a, stack_b, "rra", "sa", "rra", "rra", "sa");	
	if (comb == 2134 || comb == 1423 || comb == 4312 || comb == 4321)
		instructionsf(4, stack_a, stack_b, "sa", "ra", "ra", "sa");
	if (comb == 3142 || comb == 3241)
		instructionsf(4, stack_a, stack_b, "sa", "rra", "sa" );
	if (comb == 4123 || comb == 4213 || comb == 2431)
		instructionsf(4, stack_a, stack_b, "ra", "sa", "ra", "ra");
	if (comb == 4132)
		instructionsf(2, stack_a, stack_b, "sa", "pb");	
}
