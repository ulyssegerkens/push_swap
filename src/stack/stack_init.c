/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:09:08 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 18:44:51 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_stack(t_ps *data, t_stack *stk, int size, char **arg)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		error(data);
	i = 0;
	while (arg[i])
	{
		if (!valid_arg(arg[i]))
			error(data);
		numbers[i] = ft_atoi(arg[i]);
		i++;
	}
	check_duplication(data, numbers, size);
	random_to_rank(numbers, stk->stack, size);
	stk->bottom = size - 1;
	free(numbers);
}

bool	valid_arg(char *arg)
{
	long long	num;
	int			sign;

	sign = 1;
	if (*arg == '\0')
		return (false);
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
		if (*arg == '\0')
			return (false);
	}
	num = 0;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		num = num * 10 + (*arg - '0');
		if (((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN)))
			return (false);
		arg++;
	}
	return (true);
}

void	check_duplication(t_ps *data, int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				error(data);
			}
			j++;
		}
		i++;
	}
}

void	random_to_rank(int *numbers, int *rank, int size)
{
	int	i;
	int	j;
	int	count_smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		count_smaller = 0;
		while (j < size)
			if (numbers[j++] <= numbers[i])
				count_smaller++;
		rank[i] = count_smaller;
		i++;
	}
}
