/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:29:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 01:01:01 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log_fork(t_data *data, int philo)
{
	pthread_mutex_lock(&data->log);
	print_log(data, philo, BMAG " has taken a fork" RESET);
	pthread_mutex_unlock(&data->log);
}

void	print_log_eat(t_data *data, int philo)
{
	pthread_mutex_lock(&data->log);
	print_log(data, philo, BYEL " is eating" RESET);
	pthread_mutex_unlock(&data->log);
}

void	print_log_sleep(t_data *data, int philo)
{
	pthread_mutex_lock(&data->log);
	print_log(data, philo, BBLU " is sleeping" RESET);
	pthread_mutex_unlock(&data->log);
}

void	print_log_think(t_data *data, int philo)
{
	pthread_mutex_lock(&data->log);
	print_log(data, philo, BCYN " is thiking" RESET);
	pthread_mutex_unlock(&data->log);
}

void	print_log_die(t_data *data, int philo)
{
	pthread_mutex_lock(&data->log);
	print_log(data, philo, BRED " died" RESET);
}
