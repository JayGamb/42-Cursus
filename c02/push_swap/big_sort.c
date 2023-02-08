/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/08 17:55:22 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void put_index(t_list *stack)
{
	t_element	*current;
		int			index;
	
		index = 0;
		current = stack->first;
		while (current)
		{
			current->index = index;
			index++;
			current = current->nxt;
		}
}

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

int	get_closest(t_element *element, t_list *stack_b)
{
	t_element	*comp_b;
	int			closest_pos;
	int			difference;
	int			closest_difference;
	int			greatest;

	comp_b = stack_b->first;
	closest_pos = comp_b->pos;
	closest_difference = ft_abs(element->pos - comp_b->pos);
	comp_b = comp_b->nxt;
	while (comp_b)
	{
		difference = ft_abs(element->pos - comp_b->pos);
		if (difference <= closest_difference)
		{
				closest_difference = difference;
				closest_pos = comp_b->pos;
		}
		if (comp_b->pos > greatest)
			greatest = comp_b->pos;
		comp_b = comp_b->nxt;
	}
	if (closest_pos == 1 && element->pos != 2)
		closest_pos = greatest;
	
	return(closest_pos);
}

int	count_op(t_list *stack_b, int closest_pos, int size_b)
{
	t_element	*current;
	int			i;
	int			ops;

	current = stack_b->first;
	i = 0;
	ops = 0;
	while (current)
	{
		if (current->pos == closest_pos)
			break ;
		i++;
		current = current->nxt;
	}
	if (i < size_b / 2)
		ops = i;
	else
		ops = (i - size_b) ;
	
	return (ops);
}

int total_ops(int ops_a, int ops_b)
{
	int total_ops;

	total_ops = 0;
	ops_a = ft_abs(ops_a);
	ops_b = ft_abs(ops_b);
	if (ops_a == ops_b)
		total_ops = (ops_b + ops_a) / 2;
	else if (ops_a > ops_b)
		total_ops = ops_a - ops_b;
	else if (ops_a < ops_b)
		total_ops = ops_b - ops_a;
		
	return (total_ops + 1);
}

t_element *min_ops(t_list *stack_a, t_list *stack_b)
{
	int			total;
	t_element	*best_option;
	int			last_option;
	t_element	*current;
	int ops_a;
	int ops_b;

	ops_a = 0;
	ops_b = 0;
	put_index(stack_a);
	current = stack_a->first;
	last_option = 501;
	best_option = 0;
	while (current)
	{	
		ops_a = count_op(stack_a, current->pos, stack_size(stack_a));
		ops_b = count_op(stack_b, get_closest(current, stack_b), stack_size(stack_b));
		printf("ops_a:%d\n", ops_a);
		printf("ops_b:%d\n", ops_b);
		if (ops_b <= 0)
			ops_b++;
		if (current->pos > get_closest(current, stack_b))
			ops_b--;
		total = total_ops(ops_a, ops_b);
		printf("Total ops : %d\n\n", total);
		if (total < last_option)		
		{
			best_option = current;
			last_option = total;
		}
/* 		printf("current index : %d\t last option: %d \t best option: %d\t total: %d\n\n", current->index, last_option, best_option, total); */
		current = current->nxt;
	}
	printf("Best option ops : %d\n\n", best_option->pos);
	return (best_option);
}

void ratate_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ops < 0)
	{
		while (ops < 0)
		{
			rra_rrb(stack_a, stack_b, ft_strjoin("rr", stack_name));
			ops++;
		}
	}
	else if (ops > 0)
	{
		while (ops > 0)
		{
			ra_rb(stack_a, stack_b, ft_strjoin("r", stack_name));
			ops--;
		}
	}
}

void pa_sorting(t_list *stack_a, t_list *stack_b)
{
	int size;

	int i;
	int j;
	
	i = 0;
	j = 0;
	size = stack_size(stack_b);
	while (size > 0)
	{
		if (stack_b->first->pos < stack_a->first->pos)
			pa_pb(stack_a, stack_b, "pa");
		else if (i == stack_size(stack_a))
		{	j = 0;
			while (j != stack_size(stack_a))
			{	
				if (stack_b->first->pos - stack_a->last->pos  == 1)
				{	
					pa_pb(stack_a, stack_b, "pa");
					i = 0;
					continue ;
				}
				ra_rb(stack_a, stack_b, "ra");	
				j++;
			}
			
		}
		else
		{
			ra_rb(stack_a, stack_b, "ra");
			i++;
		}	
		size = stack_size(stack_b);
	}
}

void pb_sorting(t_list *stack_a, t_list *stack_b)
{
	int size; 
	int posclosest;
	t_element  *best_pos;
	int ops_a;
	int ops_b;

	size = stack_size(stack_a);
	while (size > 0)
	{
		best_pos = min_ops(stack_a, stack_b);
		posclosest = get_closest(best_pos, stack_b);

		ops_a = count_op(stack_a, best_pos->pos, size);
		ops_b = count_op(stack_b, posclosest, stack_size(stack_b));
		printf("the closest to %d --> %d\n", best_pos->pos, posclosest);
		printf("In Stack_A number of ops for pos %d --> %d\n\n", best_pos->pos, ops_a);
		printf("In Stack_B number of ops for pos %d --> %d\n\n", posclosest, ops_b);
		if (best_pos->pos < posclosest)
			ops_b++;
		ratate_ops(stack_a, stack_b, ops_a, "a");
		ratate_ops(stack_a, stack_b, ops_b, "b");
		pa_pb(stack_a, stack_b, "pb");
		printf("\n");
		printf("\n");
		printlist(stack_a);
		printf("stack A\n");
		printlist(stack_b);
		printf("stack b\n");
		printf("\n");
		size = stack_size(stack_a);
	}
}

/* 
void caca_sort(t_list *stack_a, t_list *stack_b)
{
	instructions(2, stack_a, stack_b, "pb", "pb");
    pb_sorting(stack_a, stack_b);

} */

/* -------- herman ------------ *//* -------- herman ------------ *//* -------- herman ------------ */
/* -------- herman ------------ *//* -------- herman ------------ *//* -------- herman ------------ */

// void caca_sort_ex(t_list *stack_a, t_list *stack_b)
// {

// 	int size;

//     pb_unlessbig(stack_a, stack_b);
// 	size = stack_size(stack_b);
//     while (size)
//     {
//         best_sort_option(stack_a, stack_b);
// 		size--;
//     }
//     while(stack_a->first->pos != 1)
// 	{
// 		instructionsf(1, stack_a, stack_b, "ra");
// 	}
// }


// void pb_unlessbig(t_list *stack_a, t_list *stack_b)
// {
// 	int size;

// 	size = stack_size(stack_a);
// 	t_element *current = stack_a->first;
// 	int current_size = size;
// 	while (current_size > 1)
// 	{
// 		if (current->pos == size)
// 		{
// 			ra_rb(stack_a, stack_b, "ra");
// 			current = stack_a->first;
// 		}
// 		if (current->pos < size)
// 		{
// 			pa_pb(stack_a, stack_b, "pb");
// 			current = stack_a->first;
// 		}
// 		current_size--;
// 	}
// }

// void best_sort_option (t_list *stack_a, t_list *stack_b)
// {
//     int bigger_top = get_bigtop(stack_b);
//     int bigger_bottom = get_bigbottom(stack_b);
//     int smaller_top = get_smalltop(stack_b);
//     int smaller_bottom = get_smallbottom(stack_b);
//     if (bigger_top <= bigger_bottom && bigger_top <= smaller_top && bigger_top <= smaller_bottom)
//     {
//         nb_rb(stack_a, stack_b, bigger_top);
// 		pa_pb(stack_a, stack_b, "pa");
// /*         instructionsf(1, stack_a, stack_b, "pa"); */
//     }
//     else if (bigger_bottom <= bigger_top && bigger_bottom <= smaller_top && bigger_bottom <= smaller_bottom)
//     {
//         nb_rrb(stack_a,stack_b, bigger_bottom);
// 		pa_pb(stack_a, stack_b, "pa");
//         /* instructionsf(1, stack_a, stack_b, "pa"); */
//     }
//         else if (smaller_top <= bigger_top && smaller_top <= bigger_bottom && smaller_top <= smaller_bottom)
//     {
//         nb_rb(stack_a, stack_b, bigger_bottom);
//         instructionsf(2, stack_a, stack_b, "pa", "ra");	
//     }
//         else if (smaller_bottom <= bigger_top && smaller_bottom <= bigger_bottom && smaller_bottom <= smaller_top)
//     {
//         nb_rrb(stack_a, stack_b, bigger_bottom);
// 		instructionsf(2, stack_a, stack_b, "pa", "ra");	
//     }
// }

// int get_bigtop (t_list *stack_b)
// {
//     int closest_pos_pos = 0;
//     int position = 1;
//     int position_return = 0;
//     t_element *current;
//     current = stack_b->first;
//     while (current)
//     {
//         if (current->pos > closest_pos_pos)
//         {
//             closest_pos_pos = current->pos;
//             position_return = position;
//         }
//         current = current->nxt;
//         position++;
//     }
//     return (position_return);
// }

// int get_smalltop (t_list *stack_b)
// {
//     int smallest_pos = stack_size(stack_b);
//     int position = 1;
//     int position_return = 0;
//     t_element *current;

//     current = stack_b->first;
//     while (current)
//     {
//         if (current->pos < smallest_pos)
//         {
//             smallest_pos = current->pos;
//             position_return = position;
//         }
//         current = current->nxt;
//         position++;
//     }
//     return (position_return);
// }

// int get_bigbottom(t_list *stack_b)
// {
//     int closest_pos_pos = 0;
//     int position = 1;
//     int position_return = 0;
//     t_element *current;
//     current = stack_b->last;
//     while (current)
//     {
//         if (current->pos > closest_pos_pos)
//         {
//             closest_pos_pos = current->pos;
//             position_return = position;
//         }
//         current = current->prev;
//         position++;
//     }
//     return (position_return);
// }

// int get_smallbottom(t_list *stack_b)
// {
//     int smallest_pos = 0;
//     int position = 1;
//     int position_return = 0;
//     t_element *current;
//     current = stack_b->last;
//     while (current)
//     {
//         if (current->pos < smallest_pos)
//         {
//             smallest_pos = current->pos;
//             position_return = position;
//         }
//         current = current->prev;
//         position++;
//     }
//     return (position_return);
// }

// void nb_rb(t_list *stack_a, t_list *stack_b, int ret_pos)
// {
//     while (ret_pos != 1)
//     {
//         instructionsf(1, stack_a, stack_b, "rb");
//         ret_pos--;
//     }
// }

// void nb_rrb(t_list *stack_a, t_list *stack_b, int ret_pos)
// {
//     while (ret_pos != 0)
//     {
//        	instructionsf(1, stack_a, stack_b, "rb");
//         ret_pos--;
//     }
// }