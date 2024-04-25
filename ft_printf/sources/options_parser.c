/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:13:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/16 16:25:08 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	parse_flags(const char *format, t_opt *opt);
static int	parse_width(const char *format, t_opt *opt);
static int	parse_precision(const char *format, t_opt *opt);
static int	parse_specifier(const char *format, t_opt *opt);

int	parse_opt(const char *format, t_opt *opt)
{
	int	offset;

	offset = 1;
	if (*format == '%')
	{
		offset += parse_flags(format + offset, opt);
		if (opt->ens_sign)
			opt->space = 0;
		offset += parse_width(format + offset, opt);
		offset += parse_precision(format + offset, opt);
		offset += parse_specifier(format + offset, opt);
		if (!opt->error)
		{
			if (opt->left || (ft_strchr("diuxX", opt->format)
					&& opt->precision > -1))
				opt->pad = ' ';
			if (ft_strchr("cdipsu", opt->format))
				opt->alt = 0;
		}
	}
	return (offset);
}

static int	parse_flags(const char *format, t_opt *opt)
{
	int	offset;
	int	flag_exists;

	offset = 0;
	flag_exists = 1;
	while (flag_exists)
	{
		if (format[offset] == '#')
			opt->alt = 1;
		else if (format[offset] == '0')
			opt->pad = '0';
		else if (format[offset] == '-')
			opt->left = 1;
		else if (format[offset] == ' ')
			opt->space = 1;
		else if (format[offset] == '+')
			opt->ens_sign = 1;
		else
		{
			flag_exists = 0;
			offset--;
		}
		offset++;
	}
	return (offset);
}

static int	parse_width(const char *format, t_opt *opt)
{
	int	offset;

	if (ft_isdigit(*format))
	{
		opt->width = ft_atoi(format);
		offset = count_digits_str(format);
	}
	else
		offset = 0;
	return (offset);
}

static int	parse_precision(const char *format, t_opt *opt)
{
	int	offset;

	if (*format++ == '.')
	{
		opt->precision = ft_atoi(format);
		offset = count_digits_str(format) + 1;
	}
	else
		offset = 0;
	return (offset);
}

static int	parse_specifier(const char *format, t_opt *opt)
{
	int	offset;

	if (*format && ft_strchr("cspdiuxX%", *format))
	{
		offset = 1;
		opt->format = *format;
	}
	else
	{
		offset = 0;
		opt->error = 1;
	}
	return (offset);
}
