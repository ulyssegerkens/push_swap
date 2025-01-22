/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:55:38 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:07:42 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "stack.h"

// MAIN CHECKER
int		main(int argc, char *argv[]);
void	read_op(t_ps *data);
bool	test_sort(t_ps *data);

// CHECK SORT
void	error_read_op(t_ps *data, char *line);
int		get_next_line_ps(int fd, char *line);
t_op	string_to_op(const char *str);
void	call_op(t_ps *data, t_op op);

#endif