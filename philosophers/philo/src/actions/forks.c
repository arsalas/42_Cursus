/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/30 13:39:52 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Obtiene la posicion en el array del siguiente tenedor al filosofo 
*/
int	next_fork(int pos, int max)
{
	if (pos == max - 1)
		return (0);
	else
		return (pos + 1);
}

/**
 * Inica si el filosofo pueded coger los tenedores
*/
bool	can_take_fork(t_data *data, int philo_id)
{
	bool	can;

	if (data->params.n_philo == 1)
		return (false);
	can = false;
	pthread_mutex_lock(&data->fork_mutex);
	if (data->forks[philo_id] == 1
		&& data->forks[next_fork(philo_id, data->params.n_philo)] == 1)
		can = true;
	pthread_mutex_unlock(&data->fork_mutex);
	return (can);
}

/**
 * Coge los tenedores para empezar a comer  
*/
void	take_fork(t_data *data, int philo_id)
{
	pthread_mutex_lock(&data->fork_mutex);
	data->forks[philo_id] = 0;
	data->forks[next_fork(philo_id, data->params.n_philo)] = 0;
	if (!is_game_over(data))
		print_log(data, philo_id + 1, FORK);
	pthread_mutex_unlock(&data->fork_mutex);
}

/**
 * Deja los tenedores  
*/
void	leave_fork(t_data *data, int philo_id)
{
	pthread_mutex_lock(&data->fork_mutex);
	data->forks[philo_id] = 1;
	data->forks[next_fork(philo_id, data->params.n_philo)] = 1;
	pthread_mutex_unlock(&data->fork_mutex);
}
