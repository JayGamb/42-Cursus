/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:34:37 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/05 20:51:25 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		mlx_destroy_window(game->vars.mlx, game->vars.win);
		exit(0);
	}
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
