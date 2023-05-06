/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:11:20 by mmita             #+#    #+#             */
/*   Updated: 2023/05/03 00:33:58 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_signal_ready;

void	send_signal(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		g_signal_ready = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_signal_ready == 0)
			usleep(1);
		i--;
	}
}

void	signal_control(int signal)
{
	if (signal == SIGUSR2)
	{
		g_signal_ready = 1;
	}
	else
		exit(ft_printf("Mensaje Recibido. \n"));
}

int	main(int argnum, char **arg)
{
	size_t	i;
	char	*str;

	if (argnum != 3 || !ft_strlen(arg[2]))
		return (ft_printf("Te faltan o sobran argumentos."));
	signal(SIGUSR1, signal_control);
	signal(SIGUSR2, signal_control);
	i = 0;
	str = arg[2];
	while (ft_strlen(str) >= i)
	{
		send_signal(arg[2][i], ft_atoi(arg[1]));
		i++;
	}
	while (1)
		pause();
}
