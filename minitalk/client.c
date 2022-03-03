/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:20:57 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/02 17:28:56 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*int_to_bin(int n)
{
	char	*num;
	int		i;

	num = ft_calloc(sizeof(char), 9);
	i = 0;
	while (n > 0)
	{
		num[7 - i] = n % 2 + '0';
		i++;
		n /= 2;
	}
	while (i < 8)
	{
		num[7 - i] = '0';
		i++;
	}
	return (num);
}

void	send_signal(char *num, int pid)
{
	int	len;
	int	dif;
	int	i;

	len = 0;
	while (num[len])
		len++;
	dif = 8 - len;
	i = 0;
	while (i < dif)
	{
		kill(pid, SIGUSR1);
		usleep(200);
		i++;
	}
	i = 0;
	while (num[i])
	{
		if (num[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	char	*str;

	if (argc < 3)
		return (0);
	pid = atoi(argv[1]);
	i = 0;
	str = argv[2];
	while (str[i])
	{
		send_signal(int_to_bin(str[i]), pid);
		i++;
	}
	send_signal(int_to_bin('\n'), pid);
	return (0);
}
