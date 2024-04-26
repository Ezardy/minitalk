/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:12:33 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/26 18:47:11 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static t_server	g_servd = {0, 0, 0, -1};

static void	handler(int signum, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	struct sigaction	ra;

	sigemptyset(&ra.sa_mask);
	ra.sa_flags = SA_RESTART | SA_SIGINFO;
	ra.sa_handler = handler;
	sigaction(SIGUSR1, &ra, NULL);
	while (1)
		g_servd.sec = sleep(TIMEOUT);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_servd.pid < 0)
		g_servd.pid = info->si_pid;
	if (g_servd.pid == info->si_pid)
	{
		g_servd.byte << 1;
		if (signum == SIGUSR2)
			g_servd.byte |= 1;
		if (g_servd.bits_received < 8)
			g_servd.bits_received++;
		else
		{
			g_servd.bits_received = 0;
			if (g_servd.byte)
				ft_putchar_fd(g_servd.byte, 1);
			else
				g_servd.pid = -1;
		}
	}
}
