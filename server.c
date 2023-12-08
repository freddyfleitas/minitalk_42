/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:35:30 by ffleitas          #+#    #+#             */
/*   Updated: 2023/12/08 19:57:29 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

// Mostrar PID, handle signal.

void	signalhandler(int signal)
{
	static int				bit;
	static unsigned char	letter;
	int						number;

	if (signal == SIGUSR1)
		number = 1;
	else
		number = 0;
	letter = (letter << 1) + number;
	bit ++;
	if (bit == 8)
	{
		write (1, &letter, 1);
		letter = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf ("Let's have a minitalk ;)\n");
	ft_printf ("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, &signalhandler);
		signal(SIGUSR2, &signalhandler);
		pause();
	}
	return (0);
}

/* void	signalhandler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
		ft_printf("Recibí un 1\n");
	if (signal == SIGUSR2)
		ft_printf("Recibí un 0\n");
	info = NULL;
	context = NULL;
} */

/* 	struct sigaction sa;
	sa.sa_sigaction = &signalhandler;
	sa.sa_flags = SA_SIGINFO; */

	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);