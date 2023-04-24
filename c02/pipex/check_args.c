/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:22:47 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/04/20 18:33:36 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_args(int argc, char **argv, t_fd fd)
{
	if (argc < 5)
	{
		ft_printf(FEW_ARGS);
		exit(1);
	}
	else if (argc > 5)
	{
		ft_printf(TOOMANY_ARGS);
		exit(1);
	}
	if (fd.infile == -1)
		perror(argv[1]);
	else if (fd.outfile == -1)
		perror(argv[4]);
	if (fd.infile == -1 || fd.outfile == -1)
		exit (1);
	return (0);
}

char	*ft_get_path(char **envp, char *prog)
{
	char	**var_paths;
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
		i++;
	}
	var_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (var_paths[i])
	{
		path = ft_strjoin(var_paths[i], "/");
		path = ft_strjoin(path, prog);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	ft_setargs(t_args *args, char **argv, char **envp)
{
	char	**command_tokens1;
	char	*path_to_command1;
	char	**command_tokens2;
	char	*path_to_command2;

	command_tokens1 = ft_split(argv[2], ' ');
	path_to_command1 = ft_get_path(envp, command_tokens1[0]);
	args->cmd1[0] = path_to_command1;
	args->cmd1[1] = command_tokens1[1];
	command_tokens2 = ft_split(argv[3], ' ');
	path_to_command2 = ft_get_path(envp, command_tokens2[0]);
	args->cmd2[0] = path_to_command2;
	args->cmd2[1] = command_tokens2[1];
	args->cmd2[2] = NULL;
}