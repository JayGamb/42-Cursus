/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:27:03 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/02 15:13:47 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(char *inst, int size, t_list *stack_a, t_list *stack_b)
{
	if (ft_strcmp(inst, PB) == 0)
	{
		if (size == 3)
		{
			sort_three(stack_a, stack_b);
			pa_pb(stack_a, stack_b, PA);
		}
		else if (size == 4)
		{
			sort_four(stack_a, stack_b);
			instructionsf(2, stack_a, stack_b, PA, SA);
		}
	}
}

void	instructionsf(int num, t_list *stack_a, t_list *stack_b, ...)
{
	va_list	args;
	char	*inst;

	va_start(args, stack_b);
	while (num > 0)
	{	
		inst = va_arg(args, char *);
		if (is_swap(inst))
			sa_sb(stack_a, stack_b, inst);
		else if (is_push(inst))
		{
			pa_pb(stack_a, stack_b, inst);
			select_sort(inst, stack_size(stack_a), stack_a, stack_b);
		}
		else if (is_rotate(inst))
			ra_rb(stack_a, stack_b, inst);
		else if (is_reverse(inst))
			rra_rrb(stack_a, stack_b, inst);
		if (check_sort(stack_a))
			return ;
		num--;
	}
}

void	instructions(int num, t_list *stack_a, t_list *stack_b, ...)
{
	va_list	args;
	char	*inst;

	va_start(args, stack_b);
	while (num > 0)
	{	
		inst = va_arg(args, char *);
		if (is_swap(inst))
			sa_sb(stack_a, stack_b, inst);
		else if (is_push(inst))
			pa_pb(stack_a, stack_b, inst);
		else if (is_rotate(inst))
			ra_rb(stack_a, stack_b, inst);
		else if (is_reverse(inst))
			rra_rrb(stack_a, stack_b, inst);
		else
			ft_printf("Error: instruction '%s' does not exist.", inst);
		num--;
	}
}

void	error(void)
{
	ft_printf("Error\n");
	exit (EXIT_FAILURE);
}
