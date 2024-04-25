/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:52:05 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/15 15:08:09 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int			print_int(t_render *render, t_opt *opt);
static void	print_int_pipe(t_render *render, t_opt *opt, int prec_len,
				int pad_len);

int	print_int(t_render *render, t_opt *opt)
{
	int	pad_len;
	int	prec_len;
	int	len;

	if (opt->precision == -1)
		opt->precision = 1;
	len = count_digits(render->value, render->base);
	prec_len = opt->precision - len;
	if (prec_len < 0)
		prec_len = 0;
	pad_len = opt->width - len - render->sign_len - prec_len
		- render->prefix_len;
	if (pad_len < 0)
		pad_len = 0;
	print_int_pipe(render, opt, prec_len, pad_len);
	return (len + pad_len + prec_len + render->sign_len + render->prefix_len);
}

static void	print_int_pipe(t_render *render, t_opt *opt, int prec_len,
	int pad_len)
{
	if (opt->pad == '0')
		ft_putstr(render->sign);
	if (!opt->left)
		ft_putnchar(opt->pad, pad_len);
	if (opt->pad == ' ' && prec_len)
		ft_putstr(render->sign);
	ft_putstr(render->prefix);
	ft_putnchar('0', prec_len);
	if (opt->pad == ' ' && !prec_len)
		ft_putstr(render->sign);
	if (render->value)
		ft_putnbr_base(render->value, render->base_signs, 1);
	if (opt->left)
		ft_putnchar(opt->pad, pad_len);
}
