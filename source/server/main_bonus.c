/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:48:24 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/27 18:15:58 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static t_server	g_servd = {0, 0, 0, -1};

static void	handler(int signum, siginfo_t *info, void *context);
static void	reset(void);
static void	loop(void);

int	main(int argc, char **argv)
{
	struct sigaction	ra;

	(void)argv;
	if (argc > 1)
		ft_putstr_fd("\tError: server need no parameters to launch\n", 2);
	else
	{
		ft_printf("Server started with pid: %i\n", getpid());
		sigemptyset(&ra.sa_mask);
		ra.sa_flags = SA_RESTART | SA_SIGINFO;
		ra.sa_sigaction = handler;
		sigaction(SIGUSR1, &ra, NULL);
		sigaction(SIGUSR2, &ra, NULL);
		loop();
	}
	return (1);
}

static void	loop(void)
{
	while (1)
	{
		if (g_servd.pid >= 0 && g_servd.inter)
		{
			g_servd.inter = usleep(TIMEOUT);
			if (g_servd.inter == 0)
			{
				ft_putstr_fd("\n\tError: Failed to await end of message\n", 2);
				g_servd.byte = 0;
				g_servd.shifted = 0;
				g_servd.pid = -1;
			}
		}
		else
			g_servd.inter = pause();
	}
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_servd.inter || g_servd.pid < 0)
	{
		if (g_servd.pid < 0)
		{
			g_servd.pid = info->si_pid;
			ft_printf("\t%i: ", info->si_pid);
		}
		if (g_servd.pid == info->si_pid)
		{
			if (signum == SIGUSR2)
				g_servd.byte |= 128;
			if (g_servd.shifted < 7)
			{
				g_servd.shifted++;
				g_servd.byte >>= 1;
			}
			else
				reset();
		}
	}
}

static void	reset(void)
{
	if (g_servd.byte)
	{
		ft_putchar_fd(g_servd.byte, 1);
		kill(g_servd.pid, SIGUSR1);
	}
	else
	{
		kill(g_servd.pid, SIGUSR2);
		g_servd.pid = -1;
		ft_putchar_fd('\n', 1);
	}
	g_servd.shifted = 0;
	g_servd.byte = 0;
}
