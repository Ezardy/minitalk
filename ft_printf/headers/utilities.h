/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:01:48 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/16 14:38:31 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_opt
{
	int		alt : 1;
	int		left : 1;
	int		ens_sign : 1;
	int		space : 1;
	int		pad : 8;
	int		format : 8;
	int		error : 12;
	int		width;
	int		precision;
}	t_opt;

typedef struct s_render
{
	size_t			value;
	char			*sign;
	char			*prefix;
	unsigned int	prefix_len;
	unsigned int	sign_len;
	char			*base_signs;
	unsigned int	base;
}	t_render;

// options_parser.c

int		parse_opt(const char *format, t_opt *opt);
// output.c

void	ft_putchar(char c);
void	ft_putnchar(char c, size_t n);
void	ft_putstrn(char *str, size_t n);
void	ft_putstr(char *str);
// ft_putnbr_base.c

void	ft_putnbr_base(long nbr, char *base, int omit_sign);
// print_string.c

int		print_string(char *str, t_opt *opt);
int		print_char(char c, t_opt *opt);
// print_int.c

int		print_pointer(void *p, t_opt *opt);
int		print_int_10(long value, t_opt *opt);
int		print_int_16(long value, t_opt *opt, int lowercase);
int		print_uint(long value, t_opt *opt);
// common.c

int		count_digits(size_t value, unsigned int base);
int		count_digits_str(const char *str);
// print_int_pipe.c

int		print_int(t_render *render, t_opt *opt);
#endif
