/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:58:34 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/12/19 17:22:18 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
        
    int fd = open("nl",  O_RDONLY);
    printf("\n\n- - - - - - - - - - - - - - next file n1- - - - - - - - - - - - - - -\n\n");
    for (int i = 0; i < 4; i++)
    {
        printf("\n-- FILE LINES --\n");
        printf("--- Line #%d: ->%s<-\n", i+1, get_next_line(fd));

    }
    
    printf("\n\n- - - - - - - - - - - - - - next file n2: multiple_nlx5 - - - - - - - - - - - - - - -\n\n");
    fd = open("multiple_nlx5",  O_RDONLY);
    for (int i = 0; i < 4; i++)
    {
        printf("\n-- FILE LINES --\n");
        printf("--- Line #%d: ->%s<-\n", i+1, get_next_line(fd));

    }

    printf("\n\n- - - - - - - - - - - - - - next file n3: emptyFile - - - - - - - - - - - - - - -\n\n");
    fd = open("41_no_nl",  O_RDONLY);
    for (int i = 0; i < 4; i++)
    {
        printf("\n-- FILE LINES --\n");
        printf("--- Line #%d: ->%s<-\n", i+1, get_next_line(fd));

    }
    return (0);
}