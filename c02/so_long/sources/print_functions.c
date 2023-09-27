/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:36:36 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/08/03 15:37:40 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printarray(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		ft_printf("%s\n", array[i]);
}