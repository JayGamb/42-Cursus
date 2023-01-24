/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:19 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/24 16:12:37 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void dispatch_algo(int nb_elment, t_list *stack_a, t_list *stack_b)
{

} */

/* int	bigorsmall(t_list *stack_a)
{
	t_element *current;
	int comb = 0;

	current = stack_a->first;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
			{
				comb *= 10;
				comb += 1;
			}
			else
			{
				comb *= 10;
				comb += 2;
			}
		}
		current = current->nxt;
	}
	if(stack_a->last->val > stack_a->first->val)
	{
		comb *= 10;
		comb += 1;
	}
	else
	{
		comb *= 10;
		comb += 2;
	}
	return (comb);
} */

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

/* 	printf("combi %d", comb); */

	if (comb == 132)
	{
		rra_rrb(stack_a, stack_b, "rra");
		sa_sb(stack_a, stack_b, "sa");
	}
	if (comb == 213)
		sa_sb(stack_a, stack_b, "sa");
	if (comb == 231)
		rra_rrb(stack_a, stack_b, "rra");
	if (comb == 312)
		ra_rb(stack_a, stack_b, "ra");
	if (comb == 321)
	{
		sa_sb(stack_a, stack_b, "sa");
		rra_rrb(stack_a, stack_b, "rra");
	}
}

void sort_four(t_list *stack_a, t_list *stack_b)
{
	t_element *current;
	get_position(stack_a);

	
	current = stack_a->first;
/* 	printf("sort_four comb: %d\n", comb); */
	while (current)
	{
		if (current->pos == 1)
			break;
		current = current->nxt;
	}
/* 	printf("\nsort_four - index %d -> pos: %d\n", current->index, current->pos); */


	if (current->index == 0)
		pa_pb(stack_a, stack_b, "pb");
	if (current->index == 1)
	{
		sa_sb(stack_a, stack_b, "sa");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 2)
	{
		rra_rrb(stack_a, stack_b, "rra");
		rra_rrb(stack_a, stack_b, "rra");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 3)
	{
		rra_rrb(stack_a, stack_b, "rra");
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
/* 	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n"); */
	sort_four(stack_a, stack_b);
	pa_pb(stack_a,	stack_b, "pa");
	sa_sb(stack_a, stack_b, "sa");
}