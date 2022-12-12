/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:58:34 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/12 16:28:47 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    
    int fd = open("emptyLines.txt",  O_RDONLY);
    // printf("fd: %d\n", fd);
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%s", get_next_line(fd));
    // }
    printf("\n\n- - - - - - - - - - - - - - next file - - - - - - - - - - - - - - -\n\n");
    fd = open("les_lines.txt",  O_RDONLY);
    printf("fd: %d\n", fd);
    for (int i = 0; i < 4; i++)
    {
        printf("\n-- Dans le main --\n");
        printf("--- Line #%d: ->%s<-\n", i+1, get_next_line(fd));

    }
    return (0);
   
}