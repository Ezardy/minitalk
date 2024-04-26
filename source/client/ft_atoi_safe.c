/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:55:16 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/26 15:20:48 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(unsigned char c);
static int	ft_atoi_count(const char *str, int *num, int size);
static int	check_prefix(const char **str, int *sign);

int	ft_atoi_safe(const char *str, int *num)
{
	int	sign;
	int	error;
	int	minor;
	int	offset;

	error = check_prefix(&str, &sign);
	minor = 0;
	if (!error)
		offset = ft_atoi_count(str, num, 9);
	error = error || !offset || ((offset < 9 && str[offset])
			|| (offset == 9 && !ft_isdigit(str[9]) && str[9]));
	if (!error && offset == 9 && ft_isdigit(str[9]))
	{
		error = *num > 214748364 || str[10]
			|| !ft_atoi_count(str + 9, &minor, 1)
			|| (*num == 214748364 && (minor > 8 || (minor == 8 && sign == 1)));
		if (!error)
			*num *= 10;
	}
	*num = sign * (*num + minor);
	return (error);
}

static int	check_prefix(const char **str, int *sign)
{
	while (ft_isspace(**str))
		(*str)++;
	*sign = 1 - 2 * (**str == '-');
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str && *(*str + 1) && **str == '0')
		(*str)++;
	return (!ft_isdigit(**str));
}

static int	ft_atoi_count(const char *str, int *num, int size)
{
	int	offset;

	*num = 0;
	offset = 0;
	while (size && ft_isdigit(*str))
	{
		offset++;
		*num = *num * 10 + *str++ - '0';
		size--;
	}
	return (offset);
}

static int	ft_isspace(unsigned char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
