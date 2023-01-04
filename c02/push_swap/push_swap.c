/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/03 19:46:36 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *pile_a;
	t_list *pile_b;
	int i;

	pile_b = list_init(0);
	if (argc > 1)
	{
		pile_a = list_init(ft_atoi(argv[i]));
		i++;
		while (argv[i])
		{
			stacking(pile_a, ft_atoi(argv[i]));
			i++;
		}
	}
	printlist(pile_a);
	swap(pile_a);
	printlist(pile_a);
	return (0);
}