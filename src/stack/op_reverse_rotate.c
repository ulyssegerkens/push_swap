/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:47 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:08:50 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	r_rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->stack[stk->top] = stk->stack[stk->bottom];
		stk->stack[stk->bottom] = 0;
		stk->bottom = next_up(stk, stk->bottom);
	}
}

void	r_rotate_a(t_ps *data)
{
	r_rotate(&data->a);
	if (data->writing_mode)
		save_op(data, rra);
}

void	r_rotate_b(t_ps *data)
{
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrb);
}

void	r_rotate_ab(t_ps *data)
{
	r_rotate(&data->a);
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrr);
}
