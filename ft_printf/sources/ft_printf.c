/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:38:09 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/16 14:38:28 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utilities.h"

static void	clear_opt(t_opt *opt);
static int	print_value(va_list args, char cur_char, t_opt *opt);

int	ft_printf(const char *format, ...)
{
	va_list	format_args;
	t_opt	opt;
	int		printed;
	int		offset;

	printed = 0;
	if (format)
	{
		clear_opt(&opt);
		va_start(format_args, format);
		while (*format)
		{
			offset = parse_opt(format, &opt);
			if (!opt.error)
				printed += print_value(format_args, *format, &opt);
			format += offset;
			clear_opt(&opt);
		}
	}
	va_end(format_args);
	return (printed);
}

static int	print_value(va_list args, char cur_char, t_opt *opt)
{
	int	printed;

	if (opt->format == 'c')
		printed = print_char(va_arg(args, int), opt);
	else if (opt->format == 's')
		printed = print_string(va_arg(args, char *), opt);
	else if (opt->format == 'p')
		printed = print_pointer(va_arg(args, void *), opt);
	else if (opt->format == 'd' || opt->format == 'i')
		printed = print_int_10(va_arg(args, int), opt);
	else if (opt->format == 'u')
		printed = print_uint(va_arg(args, unsigned int), opt);
	else if (opt->format == 'x' || opt->format == 'X')
		printed = print_int_16(va_arg(args, unsigned int), opt,
				opt->format == 'x');
	else if (opt->format == '%')
		printed = print_char(opt->format, opt);
	else
		printed = print_char(cur_char, opt);
	return (printed);
}

static void	clear_opt(t_opt *opt)
{
	opt->alt = 0;
	opt->error = 0;
	opt->format = 0;
	opt->left = 0;
	opt->precision = -1;
	opt->ens_sign = 0;
	opt->space = 0;
	opt->width = 0;
	opt->pad = ' ';
}
