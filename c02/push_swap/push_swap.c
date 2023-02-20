/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/20 13:58:02 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing(int argc, char **argv)
{
	char	**array;
	int		i;

	if (argc < 2)
		return (0);
	array = malloc(sizeof(char *) * (argc - 1) + 1);
	if (!array)
		return (NULL);
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
	{
		i = -1;
		while (++i < argc - 1)
			array[i] = argv[i + 1];
		array[argc - 1] = NULL;
	}
	return (array);
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

void	free_all(t_list *stack_a, t_list *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		exit(0);
	check_args(parsing(argc, argv), stack_a, stack_b);
	if (check_sort(stack_a))
	{
		free_all(stack_a, stack_b);
		return (0);
	}
	if (stack_size(stack_a) <= 5)
		small_sort(stack_a, stack_b, stack_size(stack_a));
	else
		big_sort(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
