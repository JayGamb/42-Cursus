/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:11:29 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/02/08 17:04:16 by jgamboa-         ###   ########.fr       */
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
void	instructions(int num, t_list *stack_a, t_list *stack_b, ...);
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
int	count_op(t_list *stack_b, int pos, int size);
int	get_closest(t_element *element, t_list *stack_b);
void pb_unlessbig(t_list *stack_a, t_list *stack_b);
void pb_sorting(t_list *stack_a, t_list *stack_b);
void best_sort_option(t_list *stack_a, t_list *stack_b);
int get_bigtop(t_list *stack_b);
int get_smalltop(t_list *stack_b);
int get_bigbottom(t_list *stack_b);
int get_smallbottom(t_list *stack_b);
void nb_rb (t_list *stack_a, t_list *stack_b, int ret_pos);
void nb_rrb (t_list *stack_a, t_list *stack_b, int ret_pos);
void caca_sort_ex(t_list *stack_a, t_list *stack_b);
void caca_sort(t_list *stack_a, t_list *stack_b);
t_element *min_ops(t_list *stack_a, t_list *stack_b);
void ratate_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name);
void pa_sorting(t_list *stack_a, t_list *stack_b);
int total_ops(int ops_a, int ops_b);
void put_index(t_list *stack);
#endif