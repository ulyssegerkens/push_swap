/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:57 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:09:00 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->stack[next_down(stk, stk->top)] == 0)
		return ;
	tmp = stk->stack[next_down(stk, stk->top)];
	stk->stack[next_down(stk, stk->top)] = stk->stack[stk->top];
	stk->stack[stk->top] = tmp;
}

void	swap_a(t_ps *data)
{
	swap(&data->a);
	if (data->writing_mode)
		save_op(data, sa);
}

void	swap_b(t_ps *data)
{
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, sb);
}

void	swap_ab(t_ps *data)
{
	swap(&data->a);
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, ss);
}
