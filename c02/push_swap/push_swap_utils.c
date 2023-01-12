/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:27:07 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/12 17:27:57 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(t_list *stack_a, t_list *stack_b)
{
	t_list *temp_a;

	
	temp_a = malloc(sizeof(t_list));
	if (!temp_a)
		exit(EXIT_FAILURE);
	if (!stack_b->first)
	{
		temp_a->first = stack_a->first->nxt;
		stack_b->first = stack_a->first;
		stack_b->first->nxt = NULL;
		stack_a->first = temp_a->first;
		free(temp_a);
		ft_printf("pb\n");
	}
}

void sa_sb(t_list *list)
{
	t_list *temp;

	if (!list->first)
		return ;
	temp = malloc(sizeof(t_list));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->first = list->first->nxt;
	list->first->nxt = temp->first->nxt;
	temp->first->nxt = list->first;
	list->first = temp->first;
	free(temp);
	ft_printf("sa\n");
}


void fill_stack(t_list stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	stack_a = list_init(ft_atoi(argv[i]));
	i++;
	while (i < argc)
	{
		stacking(stack_a, ft_atoi(argv[i]));
		i++;
	}
}

int args(char **argv)
{

}