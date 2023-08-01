/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:19:56 by ugerkens          #+#    #+#             */
/*   Updated: 2023/06/13 14:34:50 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	size_t	len;

	len = 0;
	len += ft_printstr("0x");
	len += ft_printptr_addr((uintptr_t)ptr, 'x');
	return (len);
}

int	ft_printptr_addr(uintptr_t n, const char format)
{
	size_t	len;
	char	ref;

	len = 0;
	ref = 'a';
	if (format == 'X')
		ref = 'A';
	if (n >= 16)
		len += ft_printptr_addr(n / 16, format);
	n %= 16;
	if (n <= 9)
		ft_printchar(n + '0');
	else
		ft_printchar(n - 10 + ref);
	return (len + 1);
}

int	ft_printint(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	if (n < 0)
	{
		len += ft_printchar('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_printint(n / 10);
	len += ft_printchar('0' + (n % 10));
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_printunsigned(n / 10);
	len += ft_printchar('0' + (n % 10));
	return (len);
}

int	ft_printhex(unsigned int n, const char format)
{
	size_t	len;
	char	ref;

	len = 0;
	ref = 'a';
	if (format == 'X')
		ref = 'A';
	if (n >= 16)
		len += ft_printptr_addr(n / 16, format);
	n %= 16;
	if (n <= 9)
		ft_printchar(n + '0');
	else
		ft_printchar(n - 10 + ref);
	return (len + 1);
}
