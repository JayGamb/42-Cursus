/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:19:41 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/06/12 13:45:11 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"

# define EXTENSION_ERR		"Invalid file extension. Expected .ber"
# define WALL '1'
# define PLAYER 'P'


# define EXPECTED_EXTENSION	".ber"


typedef struct s_map
{
	int		fd;
	char	*name;
	char	**map;
	int	r;
	int	c;

}	t_map;

char	*printthis(const char *str);

#endif