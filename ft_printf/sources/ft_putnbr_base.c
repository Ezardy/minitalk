/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:20:37 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/12 15:49:55 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	isunique(char *str);
static int	isusable(char *str);
static void	print_in_base(unsigned long nbr, char *base, size_t size);

void	ft_putnbr_base(long nbr, char *base, int omit_sign)
{
	size_t	size;

	size = ft_strlen(base);
	if (isunique(base) && isusable(base) && size > 1)
	{
		if (nbr == 0)
			ft_putchar(*base);
		else if (nbr < 0 && !omit_sign)
		{
			ft_putchar('-');
			print_in_base(-nbr, base, ft_strlen(base));
		}
		else
			print_in_base(nbr, base, ft_strlen(base));
	}
}

static int	isunique(char *str)
{
	int		res;
	char	*strn;

	res = 1;
	while (res && *str)
	{
		strn = str + 1;
		while (*strn && *strn != *str)
			strn++;
		if (*strn == *str)
			res = 0;
		str++;
	}
	return (res);
}

static int	isusable(char *str)
{
	while (*str && *str > 32 && *str < 127 && *str != '+' && *str != '-')
		str++;
	return (*str == 0);
}

static void	print_in_base(unsigned long nbr, char *base, size_t size)
{
	if (nbr)
	{
		print_in_base(nbr / size, base, size);
		ft_putchar(*(base + nbr % size));
	}
}
