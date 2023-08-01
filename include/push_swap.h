/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:55:45 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/29 23:30:34 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

enum			e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
};

typedef struct s_chunk
{
	enum e_loc	loc;
	int			size;
}				t_chunk;

typedef struct s_split_dest
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}				t_split_dest;

// MAIN PUSH_SWAP
int				main(int argc, char *argv[]);

// SORT
void			sort(t_ps *data);
void			sort_three_a(t_ps *data);
void			sort_five_a(t_ps *data);

// CHUNK SORT
void			chunk_sort(t_ps *data);
void			rec_chunk_sort(t_ps *data, t_chunk *to_sort);
void			sort_two(t_ps *data, t_chunk *to_sort);
void			sort_one(t_ps *data, t_chunk *to_sort);

// CHUNK UTILS
int				chunk_value(t_ps *data, t_chunk *chunk, int n);
int				chunk_max_value(t_ps *data, t_chunk *chunk);
t_stack			*loc_to_stack(t_ps *data, enum e_loc loc);

// CHUNK SPLIT
void			chunk_split(t_ps *data, t_chunk *to_split, t_split_dest *dest);
void			innit_size(t_chunk *min, t_chunk *mid, t_chunk *max);
void			set_split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid,
					t_chunk *max);
void			set_third_pivots(enum e_loc loc, int crt_size, int *pivot_1,
					int *pivot_2);

// MOVE
int				move_from_to(t_ps *data, enum e_loc from, enum e_loc to);
void			move_from_top_a(t_ps *data, enum e_loc to);
void			move_from_top_b(t_ps *data, enum e_loc to);
void			move_from_bottom_a(t_ps *data, enum e_loc to);
void			move_from_bottom_b(t_ps *data, enum e_loc to);

// OPTIMIZATION: EASY SORT
void			easy_sort(t_ps *data, t_chunk *to_sort);
void			easy_sort_second(t_ps *data, t_chunk *to_sort);
void			handle_top_b(t_ps *data, t_chunk *to_sort);
void			handle_bottom_a(t_ps *data, t_chunk *to_sort);
void			handle_bottom_b(t_ps *data, t_chunk *to_sort);

// OPTIMIZATION: SORT THREE
void			sort_three(t_ps *data, t_chunk *to_sort);
void			sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *stk,
					int max);
void			sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *stk,
					int max);
void			sort_three_bottom_a(t_ps *data, t_chunk *to_sort, t_stack *stk,
					int max);
void			sort_three_bottom_b(t_ps *data, t_chunk *to_sort, t_stack *stk,
					int max);

// OPTIMIZATION: SORT ASAP
void			split_max_reduction(t_ps *data, t_chunk *max);
bool			a_partly_sort(t_ps *data, int from);
bool			is_consecutive(int a, int b, int c, int d);
void			sort_three_numbers(int *a, int *b, int *c);

// OPTIMIZATION: TO THE TOP
void			chunk_to_the_top(t_ps *data, t_chunk *to_sort);

// POST SORT OPTIMIZATION
void			post_sort_optimization(t_ps *data);
void			eliminate_neutral_op(t_list *op_list);
void			merge_op(t_list *op_list);

// POST SORT OPTIMIZATION: UTILS
enum e_op		neutral_op(enum e_op op);
bool			op_on_same_stack(enum e_op ref, enum e_op to_check);
enum e_op		child_op(enum e_op first, enum e_op second);
void			remove_op(t_list *to_delete);

#endif