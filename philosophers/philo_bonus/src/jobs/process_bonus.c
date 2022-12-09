/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:25:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 01:23:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Comprueba si ha terminado la partida
 * 
 * @param info estructura de datos del programa
 * @return void* NULL
 */
void	*is_game_finish(void *info)
{
	t_data		*data;

	data = (t_data *)info;
	while (true)
	{
		if (get_timestamp() - data->philo.last_food > data->params.t_die)
		{
			philo_die(data, data->philo.id);
			sem_post(data->sems.sem_die);
			close_program(data);
		}
	}
	return (NULL);
}

/**
 * @brief Inicia el proceso del filosofo 
 * 
 * @param data estructura de datos de la partida
 * @param i 
 */
void	process_start(t_data *data, int i)
{
	sem_wait(data->sems.sem_start);
	data->timestamp = get_timestamp();
	data->philo = start_philo(i);
	if (i % 2 != 0)
		my_usleep(10);
	pthread_create(&data->threads.life, NULL, &is_game_finish, data);
	while (data->philo.is_alive)
	{
		take_fork(data, i);
		my_usleep(data->params.t_eat);
		finish_eat(data, i);
		my_usleep(data->params.t_sleep);
		finish_sleep(data, i);
	}
}
