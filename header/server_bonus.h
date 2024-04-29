/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:48:20 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/27 18:12:33 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# define TIMEOUT 500000

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_server
{
	int				shifted;
	int				inter;
	unsigned char	byte;
	pid_t			pid;
}	t_server;
#endif
