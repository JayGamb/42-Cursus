/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:52 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/13 16:15:28 by jgamboa-         ###   ########.fr       */
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
	args_array = ft_split(joined_str, " ");
	return (args_array);
}
 */

int arrlen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	check_args(int argc, char  **argv, t_list *stack_a)
{
	char **array;
	size_t i;

	array = malloc(sizeof(array) * argc + 1);
	if (argc < 2)
		exit (1);
	
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		i = arrlen(array);
		while (i)
		{
			stacking(stack_a, atoi_check(array[i-1]));
			i--;
		}
	}
	else
	{
		i = argc;
		while (i > 1)
		{
			stacking(stack_a, atoi_check(argv[i-1]));
			i--;
		}
	}	



}

