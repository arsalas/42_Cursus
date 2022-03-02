/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:07:06 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/02 19:34:48 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	binary_to_num(struct s_bin n)
{
	int	num;
	int	decimal_num;
	int	base;
	int	rem;

	decimal_num = 0;
	base = 1;
	num = ft_atoi(n.bit);
	while (num > 0)
	{
		rem = num % 10;
		decimal_num = decimal_num + rem * base;
		num = num / 10;
		base = base * 2;
	}
	return (decimal_num);
}

void	sighandler(int signum)
{
	static struct s_bin	num;
	int					print;

	if (num.started != 1)
	{
		num.started = 1;
		num.current = 0;
	}
	if (signum == 30)
		num.bit[num.current] = '0';
	else if (signum == 31)
		num.bit[num.current] = '1';
	num.current++;
	if (num.current == 8)
	{
		print = binary_to_num(num);
		write(1, &print, 1);
		num.current = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		sleep(1);
	return (0);
}
