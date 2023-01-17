/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:52 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/17 17:29:02 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* char **joinsplit_args(char **argv)
{
	char *joined_str;
	char **args_array;
	int total_len;
	int i;

	i = 1;
	total_len = 0;
	while (argv[i])
	{
		total_len += ft_strlen(argv[i]);
		i++;
	}
	joined_str = (char *)malloc(sizeof(char) * total_len + 1);
	i = 1;
	while (argv[i])
	{   
		if (!joined_str)
			strlcpy(joined_str, argv[i], ft_strlen(argv[i]));
		joined_str = ft_strjoin(joined_str, " ");
		joined_str = ft_strjoin(joined_str, argv[i]);
		i++;
	}
	args_array = ft_split(joined_str, ' ');
	return (args_array);
} */

/* int    find_occurrencesint(int **array)
{
    int    c1;
    int    c2;
    int c3;

    c1 = 0;
    while (array[c1])
    {
        c2 = c1 + 1;
        while (array[c2])
        {
            c3 = (array[c1] - array[c2])
            if (c3 == 0)
            {
                printf("Error\n");
                exit (EXIT_FAILURER);
            }
            c2++++;
        }
        c1++;
    }
    return (0);
} */

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
				printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	atoi_check(const char *str)
{
	int		num;
	int		i;
	int		pos_neg;
	char	*src;

	num = 0;
	i = 0;
	pos_neg = 1;
	src = (char *)str;
	while (src[i] == '\t' || src[i] == '\v' || src[i] == '\n' || src[i] == '\r'
		|| src[i] == '\f' || src[i] == ' ')
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-' )
			pos_neg = -1;
		i++;
	}
	if (ft_isdigit(src[i]))
	{
		while (src[i] && ft_isdigit(src[i]))
			{
				num = num * 10 + src[i] - '0';
				i++;
			}
		return (num * pos_neg);
	}
	else
	{
		ft_printf("Error\n");
		exit (1);
	}
}

void pushatoi(t_list *stack, char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
/* 		if (ft_strchr(array[i], '.') && ft_strchr(array[i + 1], '/'))
			i++; */
		stacking(stack, atoi_check(array[i]));
		i++;
	}
}

void	check_args(int argc, char  **argv, t_list *stack_a)
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