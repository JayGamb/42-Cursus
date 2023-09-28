/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:08:48 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/09/28 17:12:20 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_printerror.c */

#include "libft.h"

void	ft_printerror(char *message, int exitcode)
{
	ft_putendl_fd(message, 2);
	exit(exitcode);
}
