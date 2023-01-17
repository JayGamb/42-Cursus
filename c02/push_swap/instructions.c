/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:27:03 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/17 17:23:28 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "sa") == 0 || ft_strcmp(inst, "sb") == 0
	|| ft_strcmp(inst, "ss") == 0)
		sa_sb(stack_a, stack_b, inst);
	else if (ft_strcmp(inst, "pa") == 0 || ft_strcmp(inst, "pb") == 0)
		pa_pb(stack_a, stack_b, inst);
    else if (ft_strcmp(inst, "ra") == 0 || ft_strcmp(inst, "rb") == 0
	|| ft_strcmp(inst, "rr") == 0)
		ra_rb(stack_a, stack_b, inst);
    else if (ft_strcmp(inst, "rra") == 0 || ft_strcmp(inst, "rrb") == 0
	|| ft_strcmp(inst, "rrr") == 0)
		rra_rrb(stack_a, stack_b, inst);
	else
		ft_printf("Error: instruction '%s' does not exist.", inst);	
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



