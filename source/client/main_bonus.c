/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:45:53 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/27 19:52:18 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

static t_client	g_clnt = {0, 0, 0};

static int	send_msg(char *str);
static int	send_char(char c, pid_t pid);
static void	report(int error);
static void	handler(int signum, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	int					error;
	struct sigaction	ra;

	sigemptyset(&ra.sa_mask);
	ra.sa_flags = SA_RESTART | SA_SIGINFO;
	ra.sa_sigaction = handler;
	sigaction(SIGUSR1, &ra, NULL);
	sigaction(SIGUSR2, &ra, NULL);
	error = 1;
	if (argc == 3)
	{
		error = (ft_atoi_safe(argv[1], &g_clnt.pid) || g_clnt.pid < 0) * 2;
		if (!error)
		{
			error = (argv[2][0] == 0) * 3;
			if (!error)
				error = send_msg(argv[2]);
		}
	}
	report(error);
	return (error);
}

static int	send_msg(char *str)
{
	int		error;
	size_t	i;

	i = 0;
	error = 0;
	while (!error && str[i])
		error = send_char(str[i++], g_clnt.pid) * 4;
	if (!error)
		error = send_char(0, g_clnt.pid) * 4;
	if (!error)
	{
		while (!g_clnt.ended)
			error = (usleep(TIMEOUT) == 0) * 5;
		if (g_clnt.ended && ft_strlen(str) != g_clnt.sent)
			error = 5;
	}
	return (error);
}

static void	report(int error)
{
	if (error == 1)
		ft_putstr_fd("Wrong parameters count\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("Wrong pid format\n", STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("Sending string is empty\n", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("Failed to send byte on given pid\n", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("Server didn't confirm full message receiving\n",
			STDERR_FILENO);
	else
		ft_putstr_fd("The message has been transmitted\n", STDOUT_FILENO);
}

static int	send_char(char c, pid_t pid)
{
	int	s;
	int	error;

	s = 8;
	error = 0;
	while (!error && s--)
	{
		if (c & 1)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		c >>= 1;
		usleep(100);
	}
	return (error * -1);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid == g_clnt.pid && !g_clnt.ended)
	{
		if (signum == SIGUSR1)
			g_clnt.sent++;
		else
			g_clnt.ended = 1;
	}
}
