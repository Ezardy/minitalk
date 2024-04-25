/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:18:17 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/14 22:21:14 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int			print_string(char *str, t_opt *opt);
int			print_char(char c, t_opt *opt);
static void	print_string_pipe(char *str, int len, int pad_len, t_opt *opt);

int	print_char(char c, t_opt *opt)
{
	char	buf[2];
	int		pad_len;

	buf[0] = c;
	buf[1] = '\0';
	if (opt->width > 1)
		pad_len = opt->width - 1;
	else
		pad_len = 0;
	print_string_pipe((char *)buf, 1, pad_len, opt);
	return (pad_len + 1);
}

int	print_string(char *str, t_opt *opt)
{
	int	len;
	int	pad_len;

	if (!str)
	{
		len = 6;
		str = "(null)";
	}
	else
		len = ft_strlen(str);
	if (opt->precision > -1 && len > opt->precision)
		len = opt->precision;
	if (opt->width > len)
		pad_len = opt->width - len;
	else
		pad_len = 0;
	print_string_pipe(str, len, pad_len, opt);
	return (len + pad_len);
}

static void	print_string_pipe(char *str, int len, int pad_len, t_opt *opt)
{
	if (opt->left)
		ft_putstrn(str, len);
	ft_putnchar(opt->pad, pad_len);
	if (!opt->left)
		ft_putstrn(str, len);
}
