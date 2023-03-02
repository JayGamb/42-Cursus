/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:11:29 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/02 17:34:25 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

/* Macros */
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/* Structures */
typedef struct s_element	t_element;
struct s_element
{
	int			val;
	int			pos;
	int			index;
	t_element	*prev;
	t_element	*nxt;
};

typedef struct s_list
{
	t_element	*first;
	t_element	*last;
}	t_list;

typedef struct s_instructions
{
	char	*instruction;
}	t_instructions;

typedef struct s_best_ops
{
	t_element	*best_pos;
	int			closest_pos;
	int			ops_a;
	int			ops_b;
	int			ops_ab;
}	t_best_ops;

/* Functions listes chainées */
t_list		*list_init(t_list *stack, int value);
void		stacking(t_list *list, int new_val);
void		deletion(t_list *list);
void		printlist(t_list *list);
void		printstacks(t_list *list_a, t_list *list_b);

/* Check Utils */
int			find_occurrences(t_list *stack);
int			arrlen(char **str);
int			check_sort(t_list *stack);
int			check_args(int argc, char **array, t_list *stack_a, t_list *stack_b);
int			pushatoi(t_list *stack, char **array);
void		free_all(t_list *stack_a);
void		free_stack(t_list *stack_a);
void		error(void);
void		free_array(char **array);

/* Instructions functions */
int			is_swap(char *inst);
int			is_push(char *inst);
int			is_rotate(char *inst);
int			is_reverse(char *inst);
void		instructions(int num, t_list *stack_a, t_list *stack_b, ...);
void		instructionsf(int num, t_list *stack_a, t_list *stack_b, ...);
void		swap(t_list *stack);
void		push(t_list *dest, t_list *src);
void		rotate(t_list *stack);
void		reverse(t_list *stack);
void		sa_sb(t_list *stack_a, t_list *stack_b, char *inst);
void		pa_pb(t_list *stack_a, t_list *stack_b, char *inst);
void		ra_rb(t_list *stack_a, t_list *stack_b, char *inst);
void		rra_rrb(t_list *stack_a, t_list *stack_b, char *inst);

/* sorting */
void		sort_three(t_list *stack_a, t_list *stack_b);
void		sort_four(t_list *stack_a, t_list *stack_b);
void		sort_five(t_list *stack_a, t_list *stack_b);
void		small_sort(t_list *stack_a, t_list *stack_b, int size);

/* Sorting utils */
/* t_element	*min_ops(t_list *stack_a, t_list *stack_b); */
t_element	*min_ops(t_list *stack_a, t_list *stack_b, int l1, int l2);
t_best_ops	cheapest_op(t_list *stack_a, t_list *stack_b);
int			*stock_pos(t_list *stack);
int			rrr_ops(int ops_a, int ops_b);
int			get_index(t_list *stack, int pos);
int			stack_size(t_list *stack);
int			get_permutation(t_list *stack);
int			count_op(t_list *stack, int position);
int			get_closest(t_element *element, t_list *stack_b);
int			total_ops(int ops_a, int ops_b);
void		get_position(t_list *stack);
void		big_sort(t_list *stack_a, t_list *stack_b);
void		rotate_ops(t_list *stack_a, t_list *stack_b, \
				int ops, char *stack_name);
void		put_index(t_list *stack);
#endif