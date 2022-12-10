/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:25:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 17:37:07 by aramirez         ###   ########.fr       */
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
	while (get_timestamp() - data->philo.last_food < data->params.t_die)
		my_usleep(1);
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
	while (data->timestamp > get_timestamp())
		usleep(100);
	if (i % 2 != 0)
		my_usleep(data->params.t_eat);
	while (true)
	{
		sem_wait(data->sems.sem_fork);
		print_log_fork(data, i + 1);
		sem_wait(data->sems.sem_fork);
		print_log_fork(data, i + 1);
		data->philo.last_food = get_timestamp();
		print_log_eat(data, i + 1);
		sem_post(data->sems.sem_eat);
		my_usleep(data->params.t_eat);
		sem_post(data->sems.sem_fork);
		sem_post(data->sems.sem_fork);
		print_log_sleep(data, i + 1);
		my_usleep(data->params.t_sleep);
		print_log_think(data, i + 1);
	}
}
