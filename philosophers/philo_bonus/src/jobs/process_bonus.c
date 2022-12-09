/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:25:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 14:30:51 by aramirez         ###   ########.fr       */
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
	while (data->timestamp - get_timestamp() > 0)
		my_usleep(5);
	data->philo.last_food = get_timestamp();
	while (get_timestamp() - data->philo.last_food <= data->params.t_die + 2)
		my_usleep(4);
	philo_die(data, data->philo.id);
	sem_post(data->sems.sem_die);
	close_program(data);
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
	while (data->timestamp - get_timestamp() > 0)
		my_usleep(5);
	data->philo.last_food = get_timestamp();
	if (i % 2 != 0)
		my_usleep(10);
	while (data->philo.is_alive)
	{
		sem_wait(data->sems.sem_fork);
		print_log(data, i + 1, FORK);
		data->philo.last_food = get_timestamp();
		sem_post(data->sems.sem_eat);
		my_usleep(data->params.t_eat);
		print_log(data, i + 1, SLEEP);
		sem_post(data->sems.sem_fork);
		my_usleep(data->params.t_sleep);
		print_log(data, i + 1, THINK);
	}
}
