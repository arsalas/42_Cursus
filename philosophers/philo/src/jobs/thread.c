/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 17:05:09 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	finish_philo(t_data *data)
{
	int	n;

	data->finish = true;
	n = 0;
	while (n < data->params.n_philo)
	{
		pthread_mutex_unlock(&data->philos[n].fork_mutex);
		pthread_mutex_unlock(&data->log);
		n++;
	}
}

void	*check_death(void *d)
{
	t_data	*data;
	int		n;

	data = (t_data *)d;
	while (get_timestamp() < data->timestamp)
	{
		usleep(100);
	}
	while (!data->finish)
	{
		n = 0;
		while (n < data->params.n_philo)
		{
			if (get_timestamp() - data->philos[n].last_food
				> data->params.t_die)
			{
				print_log_die(data, n + 1);
				finish_philo(data);
				return (NULL);
			}
			n++;
		}
	}
	return (NULL);
}

void	*check_eats(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (data->params.time_eats > 0)
	{
		while (!data->finish)
		{
			if (data->eats == 0)
			{
				finish_philo(data);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	philo_routine(t_data *data, int i)
{
	int	next;

	next = next_fork(i, data->params.n_philo);
	pthread_mutex_lock(&data->philos[i].fork_mutex);
	print_log_fork(data, i + 1);
	pthread_mutex_lock(&data->philos[next].fork_mutex);
	print_log_fork(data, i + 1);
	print_log_eat(data, i + 1);
	data->eats--;
	data->philos[i].last_food = get_timestamp();
	my_usleep(data->params.t_eat);
	pthread_mutex_unlock(&data->philos[i].fork_mutex);
	pthread_mutex_unlock(&data->philos[next].fork_mutex);
	print_log_sleep(data, i + 1);
	my_usleep(data->params.t_sleep);
	print_log_think(data, i + 1);
}

/**
 * @brief Inicia el proceso de vida de cada filosofo
 * 
 * @param d estructura de datos
 */
void	*philo_life(void *d)
{
	t_data		*data;
	static int	n = 0;
	int			i;

	i = n;
	n++;
	data = (t_data *)d;
	while (get_timestamp() < data->timestamp)
	{
		usleep(100);
	}
	if (i % 2 != 0)
		my_usleep(data->params.t_eat / 2);
	while (!data->finish)
		philo_routine(data, i);
	return (NULL);
}
