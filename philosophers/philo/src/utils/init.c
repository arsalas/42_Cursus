/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/07 23:58:06 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Completa la informacion inicial del filosofo 
 * 
 * @param i posicion del filosofo
 * @return t_philo estructura de datos del filosofo
 */
static t_philo	init_philo_data(int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.is_alive = true;
	philo.last_food = get_timestamp();
	philo.last_sleep = 0;
	philo.n_eat = 0;
	philo.status = THINK;
	return (philo);
}

/**
 * @brief Crea los datos de los filosofos para completar la array 
 * y lanza los hilos
 * 
 * @param data estructura de datos
 * @return 0 si ha habido algun problema 
 */
int	create_data_philos(t_data *data)
{
	int		i;

	data->philos = malloc(sizeof(t_philo) * data->params.n_philo);
	if (data->philos == NULL)
		return (0);
	i = 0;
	while (i < data->params.n_philo)
	{
		data->philos[i] = init_philo_data(i);
		i++;
	}
	i = 0;
	while (i < data->params.n_philo)
	{
		if (i == data->params.n_philo - 1)
			data->start = true;
		if (pthread_create(&data->philos[i].thread,
				NULL, &philo_life, data) == -1)
			return (-1);
		i++;
	}
	return (1);
}

/**
 * @brief Crea los datos de los tenedores y las inicializa a 1
 * 
 * @param data estructura de datos
 * @return 0 si ha habido algun problema 
 */
int	create_data_forks(t_data *data)
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

/**
 * @brief Libera la memoria alocada
 * 
 * @param data estructura de datos
 */
void	destroy_data(t_data *data)
{
	free(data->philos);
	free(data->forks);
}
