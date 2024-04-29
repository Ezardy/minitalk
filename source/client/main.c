/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:12:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/27 19:39:35 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	send_char(char c, pid_t pid);
static void	report(int error);

int	main(int argc, char **argv)
{
	int		error;
	pid_t	pid;
	size_t	i;

	error = 1;
	if (argc == 3)
	{
		error = (ft_atoi_safe(argv[1], &pid) || pid < 0) * 2;
		if (!error)
		{
			i = 0;
			error = (argv[2][0] == 0) * 3;
			if (!error)
			{
				while (!error && argv[2][i])
					error = send_char(argv[2][i++], pid) * 4;
				if (!error)
					error = send_char(0, pid) * 4;
			}
		}
	}
	report(error);
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
