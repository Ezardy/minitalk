/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:47:34 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/27 19:45:31 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# define TIMEOUT 800

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "libft.h"

typedef struct s_client
{
	size_t	sent;
	int		ended;
	pid_t	pid;
}	t_client;

int	ft_atoi_safe(const char *str, int *num);
#endif
