/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:11:29 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/03 19:15:34 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

/* Structures */
typedef struct s_element t_element;
struct s_element
{
    int val;
    t_element *nxt;
};

typedef struct s_list
{
    t_element *first;
} t_list;

/* Functions listes chainées */
void swap(t_list *list);
t_list	*list_init(int value);
void stacking(t_list *list, int new_val);
void deletion(t_list *list);
void printlist(t_list *list);

/* fts swaps */
void sa(t_list *stack_a, t_list *stack_b);

#endif