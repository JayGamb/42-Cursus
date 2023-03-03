/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/03 18:30:08 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int argc, char **argv, t_list *stack_a, t_list *stack_b)
{
	char	**array;
	int		i;

	if (argc < 2)
		return ;
	array = malloc(sizeof(char *) * (argc - 1) + 1);
	if (!array)
		return ;
	if (argc == 2)
	{
		check_args(argc, 0, ft_split(argv[1], ' '), stack_a, stack_b);
	}
	else
	{
		i = -1;
		while (++i < argc - 1)
			array[i] = argv[i + 1];
		array[argc - 1] = 0;
		check_args(argc, 1, array, stack_a, stack_b);
	}
	free(array);
}

void	free_stack(t_list *stack_a)
{
	t_element	*current;
	t_element	*next;

	current = stack_a->first;
	while (current)
	{
		next = current->nxt;
		free(current);
		current = next;
	}
	stack_a->first = NULL;
	stack_a->last = NULL;
}

void	free_all(t_list *stack_a)
{
	if (stack_a->first)
		free_stack(stack_a);
	free(stack_a);
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
