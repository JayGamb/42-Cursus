/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:19 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/22 18:40:04 by jgamboa-         ###   ########.fr       */
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
    t_element *current;
	int comb;
  
	comb = 0;
	current = stack->first;
    while (current)
    {
		t_element *comp = stack->first;
		while (comp)
		{
			if (current->val > comp->val)
			{
				current->pos--;
			}
			comp = comp->nxt;
		}
		current->pos += current->pos * -2 + 1;
		comb = comb * 10 + current->pos;
		printf("position comb: %d\n", comb);
        current = current->nxt;
    }
/* 	current = stack->first; */
/* 	while (current)
    {
		comb = comb * 10 + current->pos;
		printf("gtcomb: %d\n", comb);
        current = current->nxt;
	} */
	return (comb);
}

void sort_three(t_list *stack_a, t_list *stack_b)
{
	int comb = get_position(stack_a);
	printf("comb: %d\n", comb);

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
