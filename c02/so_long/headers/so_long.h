/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:19:41 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/06/05 16:19:44 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"

# define FEW_ARGS_ERR		"Too few arguments"
# define MANY_ARGS_ERR		"Too many arguments"
# define EXTENSION_ERR		"Invalid file extension. Expected .ber"
# define FOPEN_ERR			"Error open file"

# define EXPECTED_EXTENSION	".ber"


typedef struct s_map
{
	int		fd;
	char	*name;
	char	**map;
	size_t	r;
	size_t	c;

}	t_map;

char	*printthis(const char *str);

#endif