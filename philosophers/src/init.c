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

#include "../includes/philo.h"

/**
 * Crea los datos de los filosofos para completar la array
 * y lanza los hilos
*/
void	create_data_philos(t_data *data, int n)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < n)
	{
		philo.id = i + 1;
		philo.last_food = 0;
		philo.last_sleep = 0;
		philo.n_eat = 0;
		data->philos[i] = philo;
		pthread_create(&data->philos[i].thread, NULL, &philo_life, data);
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}
 