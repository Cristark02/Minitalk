/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:43:35 by mmita             #+#    #+#             */
/*   Updated: 2023/05/06 19:45:13 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


void	signal_control(int signal, siginfo_t *info, void *param)
/*
signal: Es el número de la señal que fue recibida. Por ejemplo, si la señal es SIGUSR1, signal será igual a SIGUSR1.
info: Es un puntero a una estructura siginfo_t, que contiene información adicional sobre la señal que fue recibida.
Por ejemplo, la identificación del proceso que envió la señal.
param: Es un puntero a una estructura ucontext_t, que contiene información sobre el estado actual del proceso.
*/

{
	static char	c = 0;
	static int	bit = 7;
	static int	pid = 0;

	(void)param;
	if (signal == SIGUSR2)
	{
		c = c | (1 << bit);
	}
/*
Este `if` comprueba si la señal que ha sido recibida es un 1 se desplaza el uno Bit veces
La operación OR bitwise (|) se utiliza para establecer un bit específico en el valor de una variable
"<<"" es el operador desplazamiento izquierda
*/
	if (pid == 0)
		pid = info -> si_pid;
/*
se obtiene el PID del cliente para mandarle una señal
-> es el operador de acceso a miembros de estructura a través de punteros.
*/
	kill(pid, SIGUSR2);
	//manda la señal a SIGUSR2
	bit--;
	//deja de leer y vuelve al cliente despues de mandar SIGUSR2
	if (bit < 0)
	{
		bit = 7;
		if (c == '\0')
		{
			c = 0;
			kill (pid, SIGUSR1);
			ft_printf("\n");
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	dato;

	pid = getpid();
	ft_printf("Ejecuta el cliente en otra ventana con el comando ./client");
	ft_printf(" seguido del PID: %d y el mensaje entre comillas", pid);
	ft_printf(" que quieras que muestre el servidor\n");
	ft_printf("Ejemplo: ./client %d \"hola\"\n", pid);
	dato.sa_flags = SA_SIGINFO;
	//obtiene quien ha mandado la señal
	dato.sa_sigaction = signal_control;
	//ejecuta la respuesta a esta señal con la función signal_control
	sigaction(SIGUSR1, &dato, NULL);
	sigaction(SIGUSR2, &dato, NULL);
	//espera a recibir SIGUSR
	while (1)
		pause();
	//bucle infinito hasta que el cliente le pare
}
