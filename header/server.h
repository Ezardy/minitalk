/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:47:02 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/26 15:38:54 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "libft.h"

typedef struct s_server
{
	int		running;
	int		bits_received;
	int		timeouted;
	char	byte;
	pid_t	pid;
}	t_server;
#endif
