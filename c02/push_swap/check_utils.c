/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:52 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/13 14:00:02 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_occurrences(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (!ft_strcmp(array[i], array[j]))
			{
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	atoi_check(char *str)
{
	int	i[3];

	i[0] = 0;
	i[1] = 1;
	i[2] = 0;
	while (ft_iswhitespace(str[i[0]]))
		i[0]++;
	if (str[i[0]] == '-' || str[i[0]] == '+')
	{
		if (str[i[0]++] == '-' )
			i[1] = -1;
	}
	if (ft_isdigit(str[i[0]]))
	{
		while (str[i[0]] && ft_isdigit(str[i[0]]))
				i[2] = i[2] * 10 + str[i[0]++] - '0';
		return (i[2] * i[1]);
	}
	else
	{
		ft_printf("Error\n");
		exit (1);
	}
}

void	pushatoi(t_list *stack, char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		stacking(stack, atoi_check(array[i]));
		i++;
	}
}

void	check_args(int argc, char **argv, t_list *stack_a)
{
	char	**array;

	if (argc < 2)
		exit (1);
	if (argc == 2)
	{
		array = malloc(sizeof(array) * argc + 1);
		array = ft_split(argv[1], ' ');
		find_occurrences(array);
		pushatoi(stack_a, array);
	}
	else
	{
		find_occurrences(&argv[1]);
		pushatoi(stack_a, &argv[1]);
	}
}

int	check_sort(t_list *stack)
{
	t_element	*current;
	int			is_sorted;

	is_sorted = 1;
	current = stack->first;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
				is_sorted = 0;
		}
		current = current->nxt;
	}
	return (is_sorted);
}
