/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:23:45 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/15 14:31:49 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	count_digits(size_t value, unsigned int base);
int	count_digits_str(const char *str);

int	count_digits(size_t value, unsigned int base)
{
	int	count;

	count = 0;
	while (value)
	{
		value /= base;
		count++;
	}
	return (count);
}

int	count_digits_str(const char *str)
{
	int	count;

	count = 0;
	while (ft_isdigit(*str++))
		count++;
	return (count);
}
