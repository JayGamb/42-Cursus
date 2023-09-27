/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:34:37 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/08/10 17:11:51 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*printthis(const char *str)
{
	printf("hezye : %s", str);
	return ("sheeesh!");
}

int	ft_isplayer(char c)
{
	if (c == PLAYER)
		return (1);
	else
		return (0);
}

int	ft_iscollectable(char c)
{
	if (c == COLLECTABLE)
		return (1);
	else
		return (0);
}

int	ft_isexit(char c)
{
	if (c == EXIT)
		return (1);
	else
		return (0);
}
