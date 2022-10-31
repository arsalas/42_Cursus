/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:20:57 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/27 14:06:32 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/**
 * @brief Convierte un char a binario
 * 
 * @param n numero 
 * @return n convertido a binario
 */
char	*str_to_bin(unsigned int n)
{
	char	*num;
	int		i;

	num = ft_calloc(sizeof(char), BYTES_S + 1);
	i = 0;
	while (n > 0)
	{
		num[BYTES_S - 1 - i] = n % 2 + '0';
		i++;
		n /= 2;
	}
	while (i < BYTES_S)
	{
		num[BYTES_S - 1 - i] = '0';
		i++;
	}
	return (num);
}

/**
 * @brief Envia una señal al cliente
 * 
 * @param pid PID del programa al que enviar la señal 
 * @param signal Signal que se va a enviar
 */
void	send_signal(int pid, int signal)
{
	kill(pid, signal);
	usleep(TIME_SLP);
}

/**
 * @brief Envia una string convertida al binario a otro programa
 * 
 * @param num numero en string que queremos enviar
 * @param pid PID del programa al que queremos enviar el numero
 */
void	send_char(char *num, int pid)
{
	int	len;
	int	dif;
	int	i;

	len = 0;
	while (num[len])
		len++;
	dif = BYTES_S - len;
	i = 0;
	while (i < dif)
	{
		send_signal(pid, SIGUSR1);
		i++;
	}
	i = 0;
	while (num[i])
	{
		if (num[i] == '0')
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		i++;
	}
	free(num);
}

/**
 * @brief Gestiona las señales recividas por el servidor.
 * Al recibir la confirmacio de recepcion del mensaje el programa se cierra
 * 
 * @param signum señal recibida
 */
void	msg_recived(int signum)
{
	static int	count = 0;

	count++;
	if (signum == SIGUSR1)
	{
		ft_printf(CYN"%i Signals received\n"RESET, count);
		ft_printf(GRN"Message received!\n"RESET);
		exit(0);
	}
}

/**
 * @brief Inicia al programa, recibe los argumetos del programa y
 * envia el string recivido a otro programa. 
 * Recive el PID del programa al que se quiere enviar el segundo
 * argumento del programa
 * 
 * @param argc Total de argumentos recividos
 * @param argv Contenido de los argumentos recibidos
 * @return int 0 si todo ha ido correctamente
 */
int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	char	*str;

	signal(SIGUSR1, msg_recived);
	signal(SIGUSR2, msg_recived);
	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_printf(MAG"Sending message...\n"RESET);
	i = 0;
	str = argv[2];
	while (str[i])
	{
		send_char(str_to_bin(str[i]), pid);
		i++;
	}
	send_char(str_to_bin('\n'), pid);
	send_char(str_to_bin('\0'), pid);
	while (1)
		sleep(1);
	return (0);
}
