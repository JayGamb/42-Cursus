/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:19 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/23 16:56:37 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void dispatch_algo(int nb_elment, t_list *stack_a, t_list *stack_b)
{

} */

/* int	bigorsmall(t_list *stack_a)
{
	t_element *current;
	int comb = 0;

	current = stack_a->first;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
			{
				comb *= 10;
				comb += 1;
			}
			else
			{
				comb *= 10;
				comb += 2;
			}
		}
		current = current->nxt;
	}
	if(stack_a->last->val > stack_a->first->val)
	{
		comb *= 10;
		comb += 1;
	}
	else
	{
		comb *= 10;
		comb += 2;
	}
	return (comb);
} */

int get_position(t_list *stack)
{
    t_element	*current;
	t_element	*comp;
	int			comb;
	int			index;
  
	comb = 0;
	index = 0;
	current = stack->first;
	while (current)
    {
		if (current->pos)
			current->pos = 0;
		current = current->nxt;
	}
	current = stack->first;
    while (current)
    {
		comp = stack->first;
		while (comp)
		{
			if (current->val > comp->val)
				current->pos--;
			comp = comp->nxt;
		}
		current->pos += current->pos * -2 + 1;
		comb = comb * 10 + current->pos;
		current->index += index;
		index++;
		current = current->nxt;
    }
	return (comb);
}

void sort_three(t_list *stack_a, t_list *stack_b)
{
	int comb = get_position(stack_a);

	printf("combi %d", comb);

	if (comb == 132)
	{
		rra_rrb(stack_a, stack_b, "rra");
		sa_sb(stack_a, stack_b, "sa");
	}
	if (comb == 213)
		sa_sb(stack_a, stack_b, "sa");
	if (comb == 231)
		rra_rrb(stack_a, stack_b, "rra");
	if (comb == 312)
		ra_rb(stack_a, stack_b, "ra");
	if (comb == 321)
	{
		sa_sb(stack_a, stack_b, "sa");
		rra_rrb(stack_a, stack_b, "rra");
	}
}

void sort_four(t_list *stack_a, t_list *stack_b)
{
	t_element *current;
	int comb = get_position(stack_a);

	current = stack_a->first;
	while (current)
	{
		if (current->pos == 1)
			break;
		current = current->nxt;
	}
	printf("le premier se trouve a l'index: %d\n", current->index);
	if (current->index == 0)
		pa_pb(stack_a, stack_b, "pb");
	if (current->index == 1)
	{
		sa_sb(stack_a, stack_b, "sa");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 2)
	{
		rra_rrb(stack_a, stack_b, "rra");
		rra_rrb(stack_a, stack_b, "rra");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 3)
	{
		rra_rrb(stack_a, stack_b, "rra");
		pa_pb(stack_a, stack_b, "pb");
	}
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n");

	printf("combi avant le sort_three: %d", comb);
	sort_three(stack_a, stack_b);
	pa_pb(stack_a,	stack_b, "pa");
}

/* Placement de la pos 1 dans les comb de 5

A l’index 0
12345
pb
sort_four();

A l’index 1
51234
sa

A l’index 2
32145
rra, rra, pb

A l'index 3
34215
rra pb

A l'index 4
34251
rra pb


 */

void sort_five(t_list *stack_a, t_list *stack_b)
{
	t_element *current;
	int comb = get_position(stack_a);
   
   
	current = stack_a->first;
	while (current)
	{
		if (current->pos == 1)
			break;
		current = current->nxt;
	}
	printf("le premier se trouve a l'index: %d\n", current->index);
	if (current->index == 0)
		pa_pb(stack_a, stack_b, "pb");
	if (current->index == 1)
	{
		sa_sb(stack_a, stack_b, "sa");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 2)
	{
		rra_rrb(stack_a, stack_b, "rra");
		rra_rrb(stack_a, stack_b, "rra");
		pa_pb(stack_a, stack_b, "pb");
	}
	if (current->index == 3)
	{
		rra_rrb(stack_a, stack_b, "rra");
		pa_pb(stack_a, stack_b, "pb");
	}
	printlist(stack_a);
	ft_printf("A\n\n");
	printlist(stack_b);
	ft_printf("B\n\n");

	printf("combi avant le sort_three: %d", comb);
	sort_three(stack_a, stack_b);
	pa_pb(stack_a,	stack_b, "pa");

}

permutations = {21345, 31245, 13245, 23145, 32145, 32415, 23415, 43215, 34215, 
				24315, 42315, 41325, 14325, 34125, 43125, 13425, 
31425,
21435,
12435,
42135,
24135,
14235,
41235,
51234,
15234,
25134,
52134,
12534,
21534,
21354,
12354,
32154,
23154,
13254,
31254,
35214,
53214,
23514,
32514,
52314,
25314,
15324,
51324,
31524,
13524,
53124,
35124,
45123,
54123,
14523,
41523,
51423,
15423,
15243,
51243,
21543,
12543,
52143,
25143,
24153,
42153,
12453,
21453,
41253,
14253,
54213,
45213,
25413,
52413,
42513,
24513,
34512,
43512,
53412,
35412,
45312,
54312,
54132,
45132,
15432,
51432,
41532,
14532,
13542,
31542,
51342,
15342,
35142,
53142,
43152,
34152,
14352,
41352,
31452,
13452,
23451,
32451,
42351,
24351,
34251,
43251,
43521,
34521,
54321,
45321,
35421,
53421,
52431,
25431,
45231,
54231,
24531,
42531,
32541,
23541,
53241,
35241,
25341,
52341,
}