/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:19:41 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/04 13:43:04 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"
/* # include <X11/X.h>
# include <X11/keysym.h> */


# define WALL '1'
# define PLAYER 'P'
# define COLLECTABLE 'C'
# define EXIT 'E'
# define SPACE '0'
# define EXPECTED_EXTENSION	".ber"
# define EXTENSION_ERR "Invalid file type. '.ber' expected."
# define WALLS_ERR "Invalid map structure. Please ensure walls are correctly \
			defined."
# define MAP_ERR "Invalid map. Review the map content."
# define ELEMENTS_ERR "Invalid element count. Ensure there's 1 player ('P') and\
 1 exit ('E') and at least 1 collectable 'C'."
# define COLLECTABLE_ERR "all collectables can be reached by the player. Please\
 check the map layout."

# define KEY_ESC			53
# define KEY_Q				12
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13


# define INIT_MALLOC_ERR -1
# define ARGS_ERROR 2

typedef struct s_position{
	int	x;
	int	y;
}	t_position;

typedef struct s_element
{
	t_position			position;
	struct s_element	*next;
}	t_element;

typedef struct s_queue
{
	t_element	*first;
	t_element	*last;
}	t_queue;

typedef struct s_image
{
	void	*xpm_ptr;
	int		img_width;
	int		img_height;
}	t_image;

typedef struct s_map
{
	int			fd;
	int			size[2];
	int			player;
	int			collectable;
	int			exit;
	char		*name;
	char		**map;
	t_position	p;
	bool		**visited;
}	t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_game
{
	t_vars		vars;
	t_map		map;
	t_queue		queue;
	t_image		image;
	int			steps;
}				t_game;



int			ft_printerr(char *message, int exit_code);
int			ft_check_args(int argc, char **argv, t_game *game);
void		ft_printarray(char **array);
size_t		ft_fcountlines(char *filename);
void		ft_get_map(t_game *game);
int			ft_check_ncolumn(t_game *game);
int			ft_check_walls(t_game *game);
int			ft_check_map(t_game *game);
int			ft_init_visited(t_game *game);
int			ft_enqueue(t_queue *queue, t_position positon);
t_position	ft_dequeue(t_queue *queue);
int			ft_isplayer(char c);
int			ft_iscolletable(char c);
int			ft_iscollectable(char c);
int			ft_isexit(char c);
t_position	ft_check_north(t_game *game, t_position current);
t_position	ft_check_south(t_game *game, t_position current);
t_position	ft_check_east(t_game *game, t_position current);
t_position	ft_check_west(t_game *game, t_position current);
void		t_explore_neighbors(t_game *game, t_position current);
int			ft_navigate(t_game *game);
char		*printthis(const char *str);
/* void		ft_check_initalloc(t_game *game); */
void		ft_free_elements(int exit_code, char *err_message, t_game *game);
void		ft_free_map(t_map* map);
void		ft_clean_map(t_map *map);
void		ft_clean_queue(t_queue *queue);

#endif