/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/25 16:54:46 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check args
// check extension fichier .ber |||| example map.ber \\ a.ber
// check la map si elle est rectangulaire

void	ft_printarray(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		ft_printf("%s\n", array[i]);
}

size_t	ft_fcountlines(char *filename)
{
	int	file_fd;
	int	lines;

	file_fd = open(filename, O_RDONLY, 0777);
	if (file_fd < 0)
		return (-1);
	lines = 0;
	while (get_next_line(file_fd) != NULL)
	{
		lines++;
	}
	close(file_fd);
	return (lines);
}

/* char	**ft_get_map_compo(char *map_name)
{
	int		file_fd;
	char	**map;
	size_t	lines;
	size_t	w;

	t_map	*map_data;

	map_data->h = ft_fcountlines(map_name);
	map_data->compo = (char **)malloc((map_data->h  + 1) * sizeof(char *));
	if (!map_data->compo)
		ft_printerror(MALLOC_ERR, EXIT_FAILURE);
	map_data->file_fd = open(map_name, O_RDONLY, 0777);
	if (map_data->file_fd < 0)
		ft_printerror(map_name, errno);
	i = 0;
	while (i < lines)
	{
		map_data->compo[i] = get_next_line(map_data->file_fd);
		j = 0;
		while (map_data->compo[i][j] != '\n')
				j++;
		i++;
	}
	close(map_data->file_fd);
	return (map);
} */

/* t_map	*ft_get_mapinfo(char *map_name)
{
	int	i;
	int	j;
	i = 0;
*/


int	main(/* int argc, char **argv */)
{
	void	*mlx;
	void	*mlx_win;

/* 	if (argc < 2)
		return (1);
	else
		ft_checkmap(argv[1]);
	 */

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}