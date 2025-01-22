/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:55:45 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:09:23 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}			t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}			t_chunk;

typedef struct s_split_dest
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}			t_split_dest;

// MAIN PUSH_SWAP
int			main(int argc, char *argv[]);

// SORT
void		sort(t_ps *data);
void		sort_three_a(t_ps *data);
void		sort_five_a(t_ps *data);

// CHUNK SORT
void		chunk_sort(t_ps *data);
void		rec_chunk_sort(t_ps *data, t_chunk *to_sort);
void		sort_two(t_ps *data, t_chunk *to_sort);
void		sort_one(t_ps *data, t_chunk *to_sort);

// CHUNK UTILS
int			chunk_value(t_ps *data, t_chunk *chunk, int n);
int			chunk_max_value(t_ps *data, t_chunk *chunk);
t_stack		*loc_to_stack(t_ps *data, t_loc loc);

// CHUNK SPLIT
void		chunk_split(t_ps *data, t_chunk *to_split, t_split_dest *dest);
void		innit_size(t_chunk *min, t_chunk *mid, t_chunk *max);
void		set_split_loc(t_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max);
void		set_third_pivots(t_loc loc, int crt_size, int *pivot_1,
				int *pivot_2);

// MOVE
int			move_from_to(t_ps *data, t_loc from, t_loc to);
void		move_from_top_a(t_ps *data, t_loc to);
void		move_from_top_b(t_ps *data, t_loc to);
void		move_from_bottom_a(t_ps *data, t_loc to);
void		move_from_bottom_b(t_ps *data, t_loc to);

// OPTIMIZATION: EASY SORT
void		easy_sort(t_ps *data, t_chunk *to_sort);
void		easy_sort_second(t_ps *data, t_chunk *to_sort);
void		handle_top_b(t_ps *data, t_chunk *to_sort);
void		handle_bottom_a(t_ps *data, t_chunk *to_sort);
void		handle_bottom_b(t_ps *data, t_chunk *to_sort);

// OPTIMIZATION: SORT THREE
void		sort_three(t_ps *data, t_chunk *to_sort);
void		sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *stk,
				int max);
void		sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *stk,
				int max);
void		sort_three_bottom_a(t_ps *data, t_chunk *to_sort, t_stack *stk,
				int max);
void		sort_three_bottom_b(t_ps *data, t_chunk *to_sort, t_stack *stk,
				int max);

// OPTIMIZATION: SORT ASAP
void		split_max_reduction(t_ps *data, t_chunk *max);
bool		a_partly_sort(t_ps *data, int from);
bool		is_consecutive(int a, int b, int c, int d);
void		sort_three_numbers(int *a, int *b, int *c);

// OPTIMIZATION: TO THE TOP
void		chunk_to_the_top(t_ps *data, t_chunk *to_sort);

// POST SORT OPTIMIZATION
void		post_sort_optimization(t_ps *data);
void		eliminate_neutral_op(t_list *op_list);
void		merge_op(t_list *op_list);

// POST SORT OPTIMIZATION: UTILS
t_op		neutral_op(t_op op);
bool		op_on_same_stack(t_op ref, t_op to_check);
t_op		child_op(t_op first, t_op second);
void		remove_op(t_list *to_delete);

#endif