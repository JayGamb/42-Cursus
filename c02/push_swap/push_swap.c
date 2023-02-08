/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/08 17:50:41 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdarg.h>


void pb_sorting2(t_list *stack_a, t_list *stack_b)
{
	int size; 
	int posclosest;
	t_element  *best_pos;
	int ops_a;
	int ops_b;

	size = stack_size(stack_a);
	int demi_size = stack_size(stack_a) / 2 ;
	while (size > demi_size)
	{
		best_pos = min_ops(stack_a, stack_b);
		posclosest = get_closest(best_pos, stack_b);

		ops_a = count_op(stack_a, best_pos->pos, size);
		ops_b = count_op(stack_b, posclosest, stack_size(stack_b));
/* 		printf("the closest to %d --> %d\n", best_pos->pos, posclosest);
		printf("In Stack_A number of ops for pos %d --> %d\n\n", best_pos->pos, ops_a);
		printf("In Stack_B number of ops for pos %d --> %d\n\n", posclosest, ops_b); */
		if (best_pos->pos < posclosest)
			ops_b++;
		ratate_ops(stack_a, stack_b, ops_a, "a");
		ratate_ops(stack_a, stack_b, ops_b, "b");
		pa_pb(stack_a, stack_b, "pb");
/* 		printf("\n");
		printf("\n");
		printlist(stack_a);
		printf("stack A\n");
		printlist(stack_b);
		printf("stack b\n");
		printf("\n"); */
		size = stack_size(stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));	
	check_args(argc, argv, stack_a);
	get_position(stack_a);


	instructions(2, stack_a, stack_b, "pb", "pb");

/* 	instructions(4, stack_a, stack_b, "pb", "pb", "pb", "pb"); */

	
/* 	printf("\n");
		printf("\n");
		printlist(stack_a);
		printf("stack A\n");
		printlist(stack_b);
		printf("stack b\n");
		printf("\n"); */
		printf("\n");
		printf("\n");
		printlist(stack_a);
		printf("stack A\n");
		printlist(stack_b);
		printf("stack b\n");
		printf("\n");

/* 		pb_sorting2(stack_a, stack_b);
		while (stack_size(stack_b) > 2 )
		{
			instructions(1, stack_a, stack_b, "pa");
			instructions(2, stack_a, stack_b, "ra", "ra");
		} */
		/* pb_sorting2(stack_a, stack_b);
		while (stack_size(stack_b) > 2 )
		{
			instructions(1, stack_a, stack_b, "pa");
			instructions(2, stack_a, stack_b, "ra", "ra");
		}
				pb_sorting2(stack_a, stack_b);
		while (stack_size(stack_b) > 2 )
		{
			instructions(1, stack_a, stack_b, "pa");
			instructions(2, stack_a, stack_b, "ra", "ra");
		}
		pb_sorting2(stack_a, stack_b);
		while (stack_size(stack_b) > 2 )
		{
			instructions(1, stack_a, stack_b, "pa");
			instructions(2, stack_a, stack_b, "ra", "ra");
		} */
	/* 	int i = 0;
		while (i < stack_size(stack_a)/2)
		{
			instructions(1, stack_a, stack_b, "ra");		
				i++;
		} */
		pb_sorting(stack_a, stack_b);
		/* pb_sorting2(stack_a, stack_b); */
		while (stack_size(stack_b) != 0 )
		{
			instructions(1, stack_a, stack_b, "pa");
		}
		int ops = count_op(stack_a, 1, stack_size(stack_a));
		ratate_ops(stack_a, stack_b, ops, "a");

		printf("\n");
		printf("\n");
		printlist(stack_a);
		printf("stack A\n");
		printlist(stack_b);
		printf("stack b\n");
		printf("\n");
	/* 	pb_sorting(stack_a, stack_b); */
/* 		while (stack_size(stack_b) != 0 )
			instructions(1, stack_a, stack_b, "pa");
		i = 0;
		while (i < stack_size(stack_a)/2)
		{
			instructions(1, stack_a, stack_b, "ra");		
				i++;
		}
		instructions(2, stack_a, stack_b, "pa");	
		pb_sorting(stack_a, stack_b);
		pb_sorting(stack_a, stack_b); */
/* 	int ops = count_op(stack_b, posclosest, stack_size(stack_b));
	printf("nb of ops: %d", ops); */
	

}