/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:22:47 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/03 15:15:04 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_args(int argc, char **argv, t_fd *fd)
{
	if (argc < 5)
	{
		ft_printerror(FEW_ARGS);
		exit(1);
	}
	else if (argc > 5)
	{
		ft_printerror(TOOMANY_ARGS);
		exit(1);
	}
	fd->infile = open(argv[1], O_RDONLY, 0777);
	fd->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00700);
	if (fd->infile < 0)
	{
		ft_printerror(INFILERR);
		exit(1);
	}
	else if (fd->outfile < 0)
	{
		ft_printerror(OUTFILERR);
		exit(1);
	}
	return (0);
}





/* char	*ft_extractargs(char **argv)
{

	int		i;
	char	*argv_str;

	i = 1;
	while (argv[++i])
	{
		argv_str = ft_strjoin(argv[i], argv[i+1]);
	}
} */

void	ft_setargs(t_args *args, char **argv, char **envp)
{
	char	**command_tokens1;
	char	*path_to_command1;
	char	**command_tokens2;
	char	*path_to_command2;

	command_tokens1 = ft_split(argv[2], ' ');
	path_to_command1 = ft_getpath(envp, command_tokens1[0]);
	args->cmd1[0] = path_to_command1;
	args->cmd1[1] = command_tokens1[1];
	args->cmd1[2] = command_tokens1[2];
	args->cmd2[3] = NULL;
	command_tokens2 = ft_split(argv[3], ' ');
	path_to_command2 = ft_getpath(envp, command_tokens2[0]);
	args->cmd2[0] = path_to_command2;
	args->cmd2[1] = command_tokens2[1];
	args->cmd2[2] = command_tokens2[2];
	args->cmd2[3] = NULL;
}
