/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:32:09 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/07 16:53:41 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_threads(t_data *data)
{
	pthread_create(&data->threads.die, NULL, &th_philo_die, data);
	pthread_create(&data->threads.eat, NULL, &th_philos_eat, data);
}

/**
 * @brief Comprueba si algun filosofo ha  muerto
 * 
 * @param info estructura del programa
 */
void	*th_philo_die(void *info)
{
	t_data	*data;

	data = (t_data *)info;
	printf("1\n");
	sem_wait(data->sems.sem_die);
	printf("2\n");
	close_semaphores(data);
	return (NULL);
}

/**
 * @brief Comprueba si todos los filosofos han comido
 * 
 * @param info estructura del programa
 */
void	*th_philos_eat(void *info)
{
	t_data	*data;
	int		i;

	data = (t_data *)info;
	i = 0;
	while (i < data->params.n_philo)
	{
		sem_wait(data->sems.sem_eat);
		i++;
	}
	//printf("EAT\n");
	exit(0);
	return (NULL);
}
