/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/03 18:54:37 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_list *stack)
{
	t_element	*current;
	int size;


	size = 0;
    current = stack->first;
    while (current)
    {
		current = current->nxt;
	 	size++;
	}
	return (size);
}

int	smallest_diff(t_element *element, t_list *stack_b)
{
	t_element	*comp_b;
	int			biggest;

	comp_b = stack_b->first; 
	biggest = comp_b->pos;
	while (comp_b)
	{
		if (element->pos > comp_b->pos)
		{
			if (element->pos - comp_b->pos < element->pos - biggest)
				biggest = comp_b->pos;
		}
		comp_b = comp_b->nxt;
	}
	return(biggest); 
}

int	count_op(t_list *stack_b, int pos, int size)
{
	t_element	*current;
	int			i;

	current = stack_b->first;
	i = 0;
	while (current)
	{
		if (current->pos == pos)
			break ;
		i++;
		current = current->nxt;
	}
	if (i <= size / 2)
		return (i);
	else
		return (size - i);
}

void caca_sort_ex (t_list *stack_a, t_list *stack_b)
{

	int size;

	size = stack_size(stack_b);
    pb_unlessbig(stack_a, stack_b);
    while (size)
    {
        best_sort_option(stack_a, stack_b);
		size--;
    }
    while(stack_a->first->pos != 1)
	{
		instructionsf(1, stack_a, stack_b, "ra");
	}
}

void pb_unlessbig(t_list *stack_a, t_list *stack_b)
{
	t_element    *current;
	int 	size;

    current = stack_a->first;
	size = stack_size(stack_a);
/* 	int i = 0; */
	while (current->nxt && current->pos != size)
    {

			if (current->pos == size)
			{
				printf("ehool\n");
				ra_rb(stack_a, stack_b, "ra");
				current = stack_a->first;
			}  
			else if (current->pos < size)
			{
				printf("ehaaaal\n");
				pa_pb(stack_a, stack_b, "pb");
				current = stack_a->first;
			} 
/* 		i++;	 */
    }
}


void best_sort_option (t_list *stack_a, t_list *stack_b)
{
    int bigger_top = get_bigtop(stack_b);
    int bigger_bottom = get_bigbottom(stack_b);
    int smaller_top = get_smalltop(stack_b);
    int smaller_bottom = get_smallbottom(stack_b);
    if (bigger_top <= bigger_bottom && bigger_top <= smaller_top && bigger_top <= smaller_bottom)
    {
        nb_rb(stack_a, stack_b, bigger_top);
        instructionsf(1, stack_a, stack_b, "pa");
    }
    else if (bigger_bottom <= bigger_top && bigger_bottom <= smaller_top && bigger_bottom <= smaller_bottom)
    {
        nb_rrb(stack_a,stack_b, bigger_bottom);
        instructionsf(1, stack_a, stack_b, "pa");
    }
        else if (smaller_top <= bigger_top && smaller_top <= bigger_bottom && smaller_top <= smaller_bottom)
    {
        nb_rb(stack_a, stack_b, bigger_bottom);
        instructionsf(2, stack_a, stack_b, "pa", "ra");	
    }
        else if (smaller_bottom <= bigger_top && smaller_bottom <= bigger_bottom && smaller_bottom <= smaller_top)
    {
        nb_rrb(stack_a, stack_b, bigger_bottom);
		instructionsf(2, stack_a, stack_b, "pa", "ra");	
    }
}

int get_bigtop (t_list *stack_b)
{
    int biggest_pos = 0;
    int position = 1;
    int position_return = 0;
    t_element *current;
    current = stack_b->first;
    while (current)
    {
        if (current->pos > biggest_pos)
        {
            biggest_pos = current->pos;
            position_return = position;
        }
        current = current->nxt;
        position++;
    }
    return (position_return);
}

int get_smalltop (t_list *stack_b)
{
    int smallest_pos = stack_size(stack_b);
    int position = 1;
    int position_return = 0;
    t_element *current;

    current = stack_b->first;
    while (current)
    {
        if (current->pos < smallest_pos)
        {
            smallest_pos = current->pos;
            position_return = position;
        }
        current = current->nxt;
        position++;
    }
    return (position_return);
}

int get_bigbottom(t_list *stack_b)
{
    int biggest_pos = 0;
    int position = 1;
    int position_return = 0;
    t_element *current;
    current = stack_b->last;
    while (current)
    {
        if (current->pos > biggest_pos)
        {
            biggest_pos = current->pos;
            position_return = position;
        }
        current = current->prev;
        position++;
    }
    return (position_return);
}

int get_smallbottom(t_list *stack_b)
{
    int smallest_pos = 0;
    int position = 1;
    int position_return = 0;
    t_element *current;
    current = stack_b->last;
    while (current)
    {
        if (current->pos < smallest_pos)
        {
            smallest_pos = current->pos;
            position_return = position;
        }
        current = current->prev;
        position++;
    }
    return (position_return);
}

void nb_rb(t_list *stack_a, t_list *stack_b, int ret_pos)
{
    while (ret_pos != 1)
    {
        instructionsf(1, stack_a, stack_b, "rb");
        ret_pos--;
    }
}

void nb_rrb(t_list *stack_a, t_list *stack_b, int ret_pos)
{
    while (ret_pos != 0)
    {
       	instructionsf(1, stack_a, stack_b, "rb");
        ret_pos--;
    }
}