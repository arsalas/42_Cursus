/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:32:09 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 01:04:39 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Inicia los threats para comprobar si se ha de cerrar el programa
 * 
 * @param data estructura de datos del programa
 */
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
	while (i < data->params.n_philo * data->params.time_eats)
	{
		sem_wait(data->sems.sem_eat);
		i++;
		if (i < data->params.n_philo * data->params.time_eats)
			sem_post(data->sems.sem_log);
	}
	exit_program(data);
	return (NULL);
}

/**
 * @brief Cierra los programas hijos y los semaforos abiertos
 * 
 * @param data estructura del programa
 */
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
	free(data->id_forks);
	exit(0);
}
