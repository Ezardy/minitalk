/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:03:05 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/12 14:54:35 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	ft_putchar(char c);
void	ft_putnchar(char c, size_t n);
void	ft_putstrn(char *str, size_t n);

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_putnchar(char c, size_t n)
{
	while (n--)
		ft_putchar(c);
}

void	ft_putstrn(char *str, size_t n)
{
	while (n--)
		ft_putchar(*str++);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
