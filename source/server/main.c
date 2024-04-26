/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:12:33 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/26 15:57:13 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(int argc, char **argv)
{
	struct sigaction	ka;
	struct sigaction	ra;

	sigemptyset(&ka.sa_mask);
	sigemptyset(&ra.sa_mask);
}