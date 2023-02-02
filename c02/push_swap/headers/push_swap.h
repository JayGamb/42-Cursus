/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:11:29 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/02 18:43:00 by jgamboa-         ###   ########.fr       */
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
	int pos;
	int index;
	t_element	*prev;
	t_element   *nxt;
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
t_list	*list_init(t_list *stack, int value);
void stacking(t_list *list, int new_val);
void deletion(t_list *list);
void printlist(t_list *list);
void printstacks(t_list *list_a, t_list *list_b);

/* Check Utils */
void	check_args(int argc, char  **argv, t_list *stack_a);
int		arrlen(char **str);
void	pushatoi(t_list *stack, char **array);
int 	find_occurrences(char **array);

/* fts swaps */
void	instructions(t_list *stack_a, t_list *stack_b, char *inst);
void	instructionsf(int num, t_list *stack_a, t_list *stack_b, ...);
/* void	instructionsf(int num, t_list *stack_a, t_list *stack_b, char *ins1, char  *inst2,  */
void	swap(t_list *stack);
void	push(t_list *dest, t_list *src);
void	rotate(t_list *stack);
void	reverse(t_list *stack);
void	sa_sb(t_list *stack_a, t_list *stack_b, char *inst);
void	pa_pb(t_list *stack_a, t_list *stack_b, char *inst);
void	ra_rb(t_list *stack_a, t_list *stack_b, char *inst);
void	rra_rrb(t_list *stack_a, t_list *stack_b, char *inst);
int		check_sort(t_list *stack);




/* sorting */
void 	sort_three(t_list *stack_a, t_list *stack_b);
void	sort_four(t_list *stack_a, t_list *stack_b);
void sort_four2(t_list *stack_a, t_list *stack_b);
void sort_five(t_list *stack_a, t_list *stack_b);
int get_position(t_list *stack);

int stack_size(t_list *stack);
int	smallest_diff(t_element *element, t_list *stack_b);
int	count_op(t_list *stack_b, int pos, int size);
#endif