/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:27:03 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/27 23:39:18 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructionsf(int num, t_list *stack_a, t_list *stack_b, ...)
{
	va_list args;
	va_start(args, stack_b);
	char *inst;

	while (num > 0)
	{	
		int size = check_sort(stack_a);
/* 		printf("\nsize: %d\n\n", size); */
		inst = va_arg(args, char *);
		if (ft_strcmp(inst, "sa") == 0 || ft_strcmp(inst, "sb") == 0|| ft_strcmp(inst, "ss") == 0)
			sa_sb(stack_a, stack_b, inst);
		else if (ft_strcmp(inst, "pa") == 0 || ft_strcmp(inst, "pb") == 0)
		{	
			pa_pb(stack_a, stack_b, inst);
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
					sort_four2(stack_a, stack_b);
					pa_pb(stack_a, stack_b, "pa");
					sa_sb(stack_a, stack_b, "sa");		
				}
			}
		}
		else if (ft_strcmp(inst, "ra") == 0 || ft_strcmp(inst, "rb") == 0
		|| ft_strcmp(inst, "rr") == 0)
			ra_rb(stack_a, stack_b, inst);
		else if (ft_strcmp(inst, "rra") == 0 || ft_strcmp(inst, "rrb") == 0
		|| ft_strcmp(inst, "rrr") == 0)
			rra_rrb(stack_a, stack_b, inst);
		else
			ft_printf("Error: instruction '%s' does not exist.", inst);	
		if (check_sort(stack_a) == 0)
			return ;
		num--;
	}
}

void	sa_sb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(inst, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(inst, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	ft_printf("%s\n", inst);
}

void	pa_pb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(inst, "pb") == 0)
		push(stack_b, stack_a);
	ft_printf("%s\n", inst);
}

void ra_rb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(inst, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(inst, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	ft_printf("%s\n", inst);
}

void	rra_rrb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "rra") == 0)
		reverse(stack_a);
	else if (ft_strcmp(inst, "rrb") == 0)
		reverse(stack_b);
	else if (ft_strcmp(inst, "rrr") == 0)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
	ft_printf("%s\n", inst);
}
