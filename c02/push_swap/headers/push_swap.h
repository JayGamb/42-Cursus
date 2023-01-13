/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:11:29 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/13 15:45:51 by jgamboa-         ###   ########.fr       */
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
    t_element   *nxt;
    t_element	*prev;
};

typedef struct s_list
{
    t_element 	*first;
	t_element	*last;
} t_list;

typedef struct s_instructions
{
	char *instruction;
} t_instructions;



/* Functions listes chainées */
void sa_sb(t_list *list);
t_list	*list_init(int value);
void stacking(t_list *list, int new_val);
void deletion(t_list *list);
void printlist(t_list *list);
void printstacks(t_list *list_a, t_list *list_b);

/* fts swaps */
void    sa(t_list *stack_a, t_list *stack_b);
void    pa_pb(t_list *stack_a, t_list *stack_b);
void    check_args(int argc, char  **argv, t_list *stack_a);
int arrlen(char **str);

#endif