/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:32:09 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/08 16:39:35 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_threads(t_data *data)
{
	pthread_create(&data->threads.die, NULL, &th_philo_die, data);
	if (data->params.time_eats > -1)
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
	sem_wait(data->sems.sem_die);
	exit_program(data);
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
	exit_program(data);
	return (NULL);
}

void	exit_program(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->params.n_philo)
	{
		kill(data->id_forks[i], SIGSEGV);
		i++;
	}
	unlink_semaphores();
	exit(0);
}
