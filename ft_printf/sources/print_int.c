/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:47:44 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/14 21:02:24 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	print_pointer(void *p, t_opt *opt)
{
	opt->alt = 1;
	return (print_int_16((long)p, opt, 1));
}

int	print_int_10(long value, t_opt *opt)
{
	t_render	render;

	render.sign_len = 1;
	if (value < 0)
		render.sign = "-";
	else if (opt->ens_sign)
		render.sign = "+";
	else if (opt->space)
		render.sign = " ";
	else
	{
		render.sign = "";
		render.sign_len = 0;
	}
	if (value < 0)
		render.value = -value;
	else
		render.value = value;
	render.prefix = "";
	render.prefix_len = 0;
	render.base = 10;
	render.base_signs = "0123456789";
	return (print_int(&render, opt));
}

int	print_uint(long value, t_opt *opt)
{
	t_render	render;

	render.sign = "";
	render.sign_len = 0;
	render.value = value;
	render.prefix = "";
	render.prefix_len = 0;
	render.base = 10;
	render.base_signs = "0123456789";
	return (print_int(&render, opt));
}

int	print_int_16(long value, t_opt *opt, int lowercase)
{
	t_render	render;

	if (opt->alt && (value || opt->format == 'p'))
	{
		render.prefix_len = 2;
		if (lowercase)
			render.prefix = "0x";
		else
			render.prefix = "0X";
	}
	else
	{
		render.prefix = "";
		render.prefix_len = 0;
	}
	if (lowercase)
		render.base_signs = "0123456789abcdef";
	else
		render.base_signs = "0123456789ABCDEF";
	render.sign = "";
	render.sign_len = 0;
	render.base = 16;
	render.value = value;
	return (print_int(&render, opt));
}
