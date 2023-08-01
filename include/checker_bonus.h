/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:55:38 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 22:52:20 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "stack.h"

// MAIN CHECKER
int			main(int argc, char *argv[]);
void		read_op(t_ps *data);
bool		test_sort(t_ps *data);

// CHECK SORT
void		error_read_op(t_ps *data, char *line);
int			get_next_line_ps(int fd, char *line);
enum e_op	string_to_op(const char *str);
void		call_op(t_ps *data, enum e_op op);

#endif