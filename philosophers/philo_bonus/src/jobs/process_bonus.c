/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:25:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/08 16:45:33 by aramirez         ###   ########.fr       */
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
	static bool	eat = false;

	data = (t_data *)info;
	while (true)
	{
		if (get_timestamp() - data->philo.last_food > data->params.t_die
			&& data->philo.status != EAT)
		{
			philo_die(data, data->philo.id);
			sem_post(data->sems.sem_die);
			close_program(data);
		}
		if (data->philo.n_eat > -1
			&& data->philo.n_eat >= data->params.time_eats && !eat)
		{
			sem_post(data->sems.sem_eat);
			eat = true;
		}
		usleep(10);
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
	pthread_create(&data->threads.life, NULL, &is_game_finish, data);
	while (true)
	{
		if (data->philo.status == THINK)
			take_fork(data, i);
		else if (data->philo.status == EAT
			&& get_timestamp() - data->philo.last_food > data->params.t_eat)
			finish_eat(data, i);
		else if (data->philo.status == SLEEP && get_timestamp()
			- data->philo.last_sleep > data->params.t_sleep)
			finish_sleep(data, i);
		usleep(10);
	}
}
