/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:34:37 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/09 15:33:24 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	exit(0);
	return (0);
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
