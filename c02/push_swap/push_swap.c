/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 15:23:04 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int argc, char **argv, t_list *stack_a, t_list *stack_b)
{
	char	**array;
	char	**split_array;
	int		i;

	if (argc < 2)
		return ;
	array = malloc(sizeof(char *) * (argc - 1) + 1);
	if (!array)
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
	{
		i = 0;
		while (i++ < argc - 1)
			array[i] = argv[i + 1];
		array[argc - 1] = 0;
		if (check_args(&argv[2], stack_a, stack_b))
			exit(1);
	}
	free(array);
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
