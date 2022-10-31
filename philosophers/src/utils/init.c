/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/29 16:13:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * Crea los datos de los filosofos para completar la array y lanza los hilos
 * Devuelve 0 si ha habido algun problema
 */
int create_data_philos(t_data *data)
{
	int 	i;
	t_philo philo;
	t_info	info;

	data->philos = malloc(sizeof(t_philo) * data->params.n_philo);
	if (data->philos == NULL)
		return (0);
	i = 0;
	while (i < data->params.n_philo)
	{
		philo.id = i + 1;
		philo.is_alive = true;
		philo.last_food = get_timestamp();
		philo.last_sleep = 0;
		philo.n_eat = 0;
		philo.status = THINK;
		data->philos[i] = philo;
		info.data = data;
		info.i = i;
		pthread_create(&data->philos[i].thread, NULL, &philo_life, &info);
		usleep(1);
		i++;
	}
	return (1);
}

/**
 * Crea los datos de los tenedores y las inicializa a 1
 * Devuelve 0 si ha habido algun problema
 */
int create_data_forks(t_data *data)
{
	int	i;
	
	data->forks = malloc(sizeof(int) * data->params.n_philo);
	if (data->forks == NULL)
		return (0);
	i = 0;
	while (i < data->params.n_philo)
	{
		data->forks[i] = 1;
		i++;
	}
	return (1);
}