/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:58:34 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/29 18:29:02 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    
    int fd = open("emptyLines.txt",  O_RDONLY);
    printf("fd: %d\n", fd);
    for (int i = 0; i < 4; i++)
    {
        printf("%s", get_next_line(fd));
    }
    printf("\n\n- - - - - - - - - - - - - - next file - - - - - - - - - - - - - - -\n\n");
    fd = open("les_conquerents.txt",  O_RDONLY);
    printf("fd: %d\n", fd);
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", get_next_line(fd));
    }
    return (0);
   
}