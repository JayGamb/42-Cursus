/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:58:34 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/24 20:41:35 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    
    int fd = open("les_conquerents.txt",  O_RDONLY);
    for (int i = 0; i < 3; i++)
    {
        printf("%s", get_next_line(fd));
    }

    return (0);
   
}