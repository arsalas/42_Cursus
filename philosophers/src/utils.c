/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:58 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/29 13:10:20 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	is_atoi_delimiter(unsigned char d)
{
	if (d == ' ' || d == '\t' || d == '\n'
		|| d == '\f' || d == '\r' || d == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	while (is_atoi_delimiter(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

long long	get_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_log(int philo, t_actions action)
{
	char	*desc;

	if (action == FORK)
		desc = "has taken a fork";
	else if (action == EAT)
		desc = "is eating";
	else if (action == SLEEP)
		desc = "is sleeping";
	else if (action == THINK)
		desc = "is thiking";
	else if (action == DIE)
		desc = "died";
	else
		return ;
	printf("%lli %i %s\n", get_timestamp(), philo, desc);
}
