/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:11:29 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/02 17:12:15 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void push_swap(int *a, int *b);

typedef struct s_pile
{
    int val;
    struct s_pile *nxt;
} t_pile;

#endif PUSH_SWAP_H