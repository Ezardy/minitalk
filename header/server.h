/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:47:02 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/26 18:45:29 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define TIMEOUT 1u

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_server
{
	int				bits_received;
	unsigned int	sec;
	char			byte;
	pid_t			pid;
}	t_server;
#endif
