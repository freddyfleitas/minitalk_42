/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:35:28 by ffleitas          #+#    #+#             */
/*   Updated: 2023/12/08 20:03:18 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	sendbits(int pid, char *str, int len)
{
	int	i;
	int	shift;

	i = 0;
	if (pid == 0)
		return ;
	if (*str == 0)
	{
		ft_printf ("ERROR: Invalid message (empty)\n");
		return ;
	}
	while (i < len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift --;
			usleep (100);
		}
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi (argv[1]);
		sendbits (pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_printf("ERROR: Invalid argument's number\n");
	return (0);
}

/* sigaction (sig, &act, &oldact) - 
define la acción a  realizar cuando se recibe una
señal, es la versión POSIX de signal. */

/* sigaction (int signum, const struct sigaction *act, 
struct sigaction *oldact);
signum, es la señal a recibir.
act y oldact son las estructuras que definen el nuevo 
y viejo comportamiento para
tratar la señal.  */

/* Ejecutar servidor, que debe mostrar su PID
El cliente, toma la String que debe comunicarse */

/* BITWISE:

& -> and. a & b
| -> or.  a | b
^ -> xor.  a ^ b */

// Write es una función segura, para imprimir señales:

/* void sendbits(int pid, const char *str, int len) //ChatGPT UNICODE 
{
    for (int i = 0; i < len; ++i)
    {
        unsigned char byte = str[i];
        for (int shift = 0; shift < 8; ++shift)
        {
            if ((byte >> shift) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100000);  // Ajusta según sea necesario
        }
    }
} */