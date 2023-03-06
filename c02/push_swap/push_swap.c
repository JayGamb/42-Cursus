/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 20:56:08 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int argc, char **argv, t_list *stack_a, t_list *stack_b)
{
	char	**split_array;

	if (argc < 2)
		return ;
	if (argc == 2)
	{
		split_array = ft_split(argv[1], ' ');
		if (check_args(split_array, stack_a, stack_b))
		{
			free_array(split_array);
			free(split_array);
			exit(1);
		}
		free_array(split_array);
		free(split_array);
	}
	else
		if (check_args(&argv[1], stack_a, stack_b))
			exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		exit(0);
	parsing(argc, argv, stack_a, stack_b);
	if (stack_size(stack_a) <= 5)
		small_sort(stack_a, stack_b, stack_size(stack_a));
	else
		big_sort(stack_a, stack_b);
	free_all(stack_a);
	free_all(stack_b);
	return (0);
}
