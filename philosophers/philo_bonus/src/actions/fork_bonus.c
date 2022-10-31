/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/07 15:48:52 by aramirez         ###   ########.fr       */
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
	data->philo.status = WAITNG_FORK;
	sem_wait(data->sems.sem_eat);
	data->philo.status = FORK;
	print_log(data, philo_id + 1, FORK);
	start_eat(data, philo_id);
}

/**
 * Deja los tenedores
*/
void	leave_fork(t_data *data)
{
	sem_post(data->sems.sem_eat);
}
