/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:58 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/07 15:46:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * Comprueba si el el valor pasado es un digito
 */
static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * Comprueba si el caracter pasado es un delimitador de la funcion atoi
 */
static int	is_atoi_delimiter(unsigned char d)
{
	if (d == ' ' || d == '\t' || d == '\n'
		|| d == '\f' || d == '\r' || d == '\v')
		return (1);
	else
		return (0);
}

/**
 * Transforma un string en un int
 */
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

/**
 * Obtiene el timestamp
 */
long long	get_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 * Imprime por pantalla el log de la accion
 */
void	print_log(t_data *data, int philo, t_status action)
{
	char	*desc;

	sem_wait(data->sems.sem_log);
	if (action == FORK)
		desc = BMAG "has taken a fork" RESET;
	else if (action == EAT)
		desc = BYEL "is eating" RESET;
	else if (action == SLEEP)
		desc = BBLU "is sleeping" RESET;
	else if (action == THINK)
		desc = BCYN "is thiking" RESET;
	else if (action == DIE)
		desc = BRED "died" RESET;
	else
		return ;
	printf(UGRN "%lli" RESET BHWHT" %i " RESET "%s\n",
		get_timestamp() - data->timestamp, philo, desc);
	sem_post(data->sems.sem_log);
}
