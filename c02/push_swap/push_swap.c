/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/12 15:49:34 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdarg.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));	
	check_args(argc, argv, stack_a);
	get_position(stack_a);
	if (check_sort(stack_a))
		exit(1);
	size_a = stack_size(stack_a);
	if (size_a < 6)
		small_sort(stack_a, stack_b, size_a);
	else
	{
		pb_sorting(stack_a, stack_b);
		sort_four(stack_a, stack_b);

	}	
	return (0); 
}