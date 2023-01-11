/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/07 14:11:50 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *pile_a;
	t_list *stack_b;
	int i;

	stack_b = malloc(sizeof(t_list));
	if (argc > 1)
	{
		pile_a = list_init(ft_atoi(argv[i]));
		i++;
		while (i < argc / 2)
		{
			stacking(pile_a, ft_atoi(argv[i]));
			i++;
		}
	}
	for (int j = 0; j < 10; j++)
	{
		sa_sb(pile_a);
		pa_pb(pile_a, stack_b);
		sa_sb(pile_a);
	}
	// printlist(pile_a);
	// ft_printf("A\n\n");
	// printlist(stack_b);
	// ft_printf("B\n\n");
}
