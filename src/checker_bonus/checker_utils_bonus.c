/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:56:40 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 22:58:13 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_read_op(t_ps *data, char *line)
{
	if (line)
		free(line);
	error(data);
}

int	get_next_line_ps(int fd, char *line)
{
	int		i;
	int		read_status;
	char	char_buffer;

	i = 0;
	char_buffer = ' ';
	while (char_buffer != '\n')
	{
		read_status = read(fd, &char_buffer, 1);
		if (read_status == -1)
			return (EXIT_FAILURE);
		if (read_status == 0)
			break ;
		line[i++] = char_buffer;
		if (i > 4)
			return (EXIT_FAILURE);
	}
	if ((i > 0 && line[i - 1] != '\n') || line[0] == '\n')
		return (EXIT_FAILURE);
	if (read_status == 0)
		line[0] = '\0';
	else
		line[i - 1] = '\0';
	return (EXIT_SUCCESS);
}

enum e_op	string_to_op(const char *str)
{
	if (!ft_strcmp(str, "pa"))
		return (pa);
	else if (!ft_strcmp(str, "pb"))
		return (pb);
	else if (!ft_strcmp(str, "rra"))
		return (rra);
	else if (!ft_strcmp(str, "rrb"))
		return (rrb);
	else if (!ft_strcmp(str, "rrr"))
		return (rrr);
	else if (!ft_strcmp(str, "ra"))
		return (ra);
	else if (!ft_strcmp(str, "rb"))
		return (rb);
	else if (!ft_strcmp(str, "rr"))
		return (rr);
	else if (!ft_strcmp(str, "sa"))
		return (sa);
	else if (!ft_strcmp(str, "sb"))
		return (sb);
	else if (!ft_strcmp(str, "ss"))
		return (ss);
	else
		return (null_op);
}

void	call_op(t_ps *data, enum e_op op)
{
	if (op == pa)
		push_a(data);
	else if (op == pb)
		push_b(data);
	else if (op == rra)
		r_rotate_a(data);
	else if (op == rrb)
		r_rotate_b(data);
	else if (op == rrr)
		r_rotate_ab(data);
	else if (op == ra)
		rotate_a(data);
	else if (op == rb)
		rotate_b(data);
	else if (op == rr)
		rotate_ab(data);
	else if (op == sa)
		swap_a(data);
	else if (op == sb)
		swap_b(data);
	else if (op == ss)
		swap_ab(data);
	else
		error(data);
}
