/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/03 13:38:31 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * Coge los tenedores para empezar a comer
 * Utiliza dos semafaros para esperar a comer
*/
void	take_fork(t_data *data, int philo_id)
{
	if (data->params.n_philo == 1)
		return ;
	data->philos[philo_id].status = WAITNG_FORK;
	sem_wait(data->semaphore);
	sem_wait(data->semaphore);
	if (!data->philos[philo_id].is_alive)
	{
		leave_fork(data);
		close_program(data);
	}
	data->philos[philo_id].status = FORK;
	print_log(data, philo_id + 1, FORK);
	data->forks -= 2;
}

/**
 * Deja los tenedores
*/
void	leave_fork(t_data *data)
{
	sem_post(data->semaphore);
	sem_post(data->semaphore);
}
