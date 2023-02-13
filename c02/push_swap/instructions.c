/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:27:03 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/12 14:24:53 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(char *inst, int size, t_list *stack_a, t_list *stack_b)
{
	if (ft_strcmp(inst, "pb") == 0)
	{
		size--;
		if (size == 3)
		{
			sort_three(stack_a, stack_b);
			pa_pb(stack_a, stack_b, "pa");
		}
		else if (size == 4)
		{
			sort_four(stack_a, stack_b);
			pa_pb(stack_a, stack_b, "pa");
			sa_sb(stack_a, stack_b, "sa");
		}
	}
}

void	instructionsf(int num, t_list *stack_a, t_list *stack_b, ...)
{
	va_list	args;
	char	*inst;
	int		size;

	va_start(args, stack_b);
	while (num > 0)
	{	
		size = stack_size(stack_a);
		inst = va_arg(args, char *);
		if (is_swap(inst))
			sa_sb(stack_a, stack_b, inst);
		else if (is_push(inst))
		{
			pa_pb(stack_a, stack_b, inst);
			select_sort(inst, size, stack_a, stack_b);
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
