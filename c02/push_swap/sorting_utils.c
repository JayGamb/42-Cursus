/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:19 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/20 12:22:38 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void dispatch_algo(int nb_elment, t_list *stack_a, t_list *stack_b)
{

} */

int	bigorsmall(t_list *stack_a)
{
	t_element *current;
	int is_big_or_small = 0;

	current = stack_a->first;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
			{
				is_big_or_small *= 10;
				is_big_or_small += 1;
			}
			else
			{
				is_big_or_small *= 10;
				is_big_or_small += 2;
			}
		}
		current = current->nxt;
	}
	if(stack_a->last->val > stack_a->first->val)
	{
		is_big_or_small *= 10;
		is_big_or_small += 1;
	}
	else
	{
		is_big_or_small *= 10;
		is_big_or_small += 2;
	}
	return (is_big_or_small);
}

void sort_three(t_list *stack_a, t_list *stack_b)
{
	int is_big_or_small = bigorsmall(stack_a);

	if (is_big_or_small == 112)
	{
		ra_rb(stack_a, stack_b, "ra");
		sa_sb(stack_a, stack_b, "sa");
	}
	if (is_big_or_small == 121)
		sa_sb(stack_a, stack_b, "sa");
	if (is_big_or_small == 122)
		ra_rb(stack_a, stack_b, "ra");
	if (is_big_or_small == 211)
	{
		sa_sb(stack_a, stack_b, "sa");
		ra_rb(stack_a, stack_b, "ra");
	}
	if (is_big_or_small == 212)
		ra_rb(stack_a, stack_b, "rra");
}

void get_index(t_list *stack_a, t_list * stack_b)
{
	int greater;
	int size;
	int max_bits;
	int	i;
	int j;
	int num;

	i = 0;
	max_bits = 0;
	j = 0;
	size = check_sort(stack_a);
	greater = size - 1;

	while ((greater >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		while (j < size)
		{
			num = stack_a->first->val;
			if (((num >> i)&1) == 1)
				instructions(stack_a, stack_b, "ra");
			else
			{
				instructions(stack_a, stack_b, "pb");
			}
			j++;
		}
		i++;
	}
	while (stack_b->first)
	{
		if (!stack_b->first->nxt)
			break;
		instructions(stack_a, stack_b, "pa");

	}
}

void get_sortedpos(t_list *stack)
{
	t_element	*current;
	t_element	*temp;
	int			pos;
	int			size;

	size = check_sort(stack);
	temp = stack->first;
	current = temp;
	pos = 1;
	while (pos < size)
	{
		current = temp;
		while (current)
		{
			if (current->val < current->nxt->nxt)
			{
				
				current->pos = pos;
			}
			current = current->nxt;

		}

	}


}