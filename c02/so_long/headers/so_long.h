/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:19:41 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/25 16:40:33 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	int		file_fd;
	char	**compo;
	size_t	w;
	size_t	h;



}	t_map;

char	*printthis(const char *str);

#endif