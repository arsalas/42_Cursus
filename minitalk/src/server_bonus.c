/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:07:06 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/27 15:00:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/**
 * @brief Conversion numero binario a decimal
 * 
 * @param n struct con el numero en binario
 * @return int numero en decimal
 */
int	binary_to_num(struct s_bin n)
{
	int	num;
	int	decimal_num;
	int	base;
	int	res;

	decimal_num = 0;
	base = 1;
	num = ft_atoi(n.bit);
	while (num > 0)
	{
		res = num % 10;
		decimal_num = decimal_num + res * base;
		num /= 10;
		base *= 2;
	}
	return (decimal_num);
}

/**
 * @brief Evento que se activa al recivir una señal
 * interpreta las señales recividas y asigna a cada byte
 * un 1 si la señal recivida es un SIGUSR1
 * y un 0 si es un SIGUSR2
 * Cuando se ha recibido el ultimo byte se pinta por pantalla el numero decimal
 * 
 * @param signum señal recivida
 * @param c_pid PID del cliente
 */
void	sighandler(int signum, int c_pid)
{
	static struct s_bin	num;
	int					print;

	if (num.started != 1)
	{
		num.started = 1;
		num.current = 0;
	}
	if (signum == SIGUSR1)
		num.bit[num.current] = '0';
	else if (signum == SIGUSR2)
		num.bit[num.current] = '1';
	num.current++;
	if (num.current == BYTES_S)
	{
		print = binary_to_num(num);
		write(1, &print, 1);
		num.current = 0;
		if (print == '\0')
			kill(c_pid, SIGUSR1);
		else
			kill(c_pid, SIGUSR2);
	}
}

/**
 * @brief Gestiona la recepcion de señales
 * 
 * @param signum señal recivida
 * @param info struct con la informacion del emisor de la señal
 * @param oldact guarda la accion anterior
 */
void	manage_signals(int signum, siginfo_t *info, void *oldact)
{
	(void)oldact;
	sighandler(signum, info->si_pid);
}

/**
 * @brief Inicia el programa, printa el PID del programa
 * y activa la recepcion de señales
 * 
 * @return int 0 si todo ha ido bien
 */
int	main(void)
{
	struct sigaction	sa;

	ft_printf(YEL"PID: "WHT"%i\n"RESET, getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = manage_signals;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
