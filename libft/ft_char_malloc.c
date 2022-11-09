/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:38 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/09 15:21:54 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_char_malloc(size_t size)
{
    char *m;

    m = (char *)malloc(sizeof(char) * (size + 1));
    if (!m)
        return (0);
    return m;
}
