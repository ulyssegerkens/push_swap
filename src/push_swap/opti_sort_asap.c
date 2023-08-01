/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_asap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:30 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 23:12:37 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_max_reduction(t_ps *data, t_chunk *max)
{
	t_stack	*a;

	a = &data->a;
	if (max->loc == TOP_A && max->size == 3 && is_consecutive(value(a, 1),
			value(a, 2), value(a, 3), value(a, 4)) && a_partly_sort(data, 4))
	{
		sort_three(data, max);
		return ;
	}
	if (max->loc == TOP_A && value(a, 1) == value(a, 3) - 1
		&& a_partly_sort(data, 3))
	{
		swap_a(data);
		max->size--;
	}
	if (max->loc == TOP_A && a_partly_sort(data, 1))
		max->size--;
}

bool	a_partly_sort(t_ps *data, int from)
{
	int		i;
	t_stack	*a;
	int		value;

	a = &data->a;
	i = a->top;
	while (--from)
		i = next_down(a, i);
	while (a->stack[i] != data->a.size)
	{
		value = a->stack[i];
		i = next_down(a, i);
		if (a->stack[i] != value + 1)
			return (false);
	}
	return (true);
}

bool	is_consecutive(int a, int b, int c, int d)
{
	sort_three_numbers(&a, &b, &c);
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

void	sort_three_numbers(int *a, int *b, int *c)
{
	int	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}
