/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_post_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:15:00 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:15:11 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

enum e_op	neutral_op(enum e_op op)
{
	if (op == pa)
		return (pb);
	if (op == pb)
		return (pa);
	if (op == ra)
		return (rra);
	if (op == rb)
		return (rrb);
	if (op == rra)
		return (ra);
	if (op == rrb)
		return (rb);
	if (op == sa)
		return (sa);
	if (op == sb)
		return (sb);
	if (op == rr)
		return (rrr);
	return (null_op);
}

bool	op_on_same_stack(enum e_op ref, enum e_op to_check)
{
	if (ref == pa || ref == pb || ref == rr || ref == rrr)
		return (true);
	if (to_check == pa || to_check == pb || to_check == rr || to_check == rrr)
		return (true);
	else if (ref == ra || ref == rra || ref == sa)
		return (to_check == ra || to_check == rra || to_check == sa);
	else if (ref == rb || ref == rrb || ref == sb)
		return (to_check == rb || to_check == rrb || to_check == sb);
	return (false);
}

enum e_op	child_op(enum e_op first, enum e_op second)
{
	if ((first == ra && second == rb) || (first == rb && second == ra))
		return (rr);
	else if ((first == rra && second == rrb) || (first == rrb && second == rra))
		return (rrr);
	else if ((first == sa && second == sb) || (first == sb && second == sa))
		return (ss);
	else
		return (null_op);
}

void	remove_op(t_list *to_delete)
{
	to_delete->prev->next = to_delete->next;
	if (to_delete->next)
		to_delete->next->prev = to_delete->prev;
	ft_lstdelone(to_delete, NULL);
}
