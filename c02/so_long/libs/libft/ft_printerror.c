/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:08:48 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/19 15:52:19 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_printerror.c */

#include "libft.h"

void	ft_printerror(char *message, int exitcode)
{
	if (errno == 0)
		ft_putendl_fd(message, 2);
	else
		perror(message);
	exit(exitcode);
}
