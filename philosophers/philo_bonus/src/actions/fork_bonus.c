/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/08 16:44:06 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Coge los tenedores para empezar a comer
 * Utiliza dos semafaros para esperar a comer
 * @param data estructura de datos de la partida
 * @param philo_id id del filosofo
 */
void	take_fork(t_data *data, int philo_id)
{
	if (data->params.n_philo == 1)
		return ;
	data->philo.status = WAITNG_FORK;
	sem_wait(data->sems.sem_fork);
	data->philo.status = FORK;
	print_log(data, philo_id + 1, FORK);
	start_eat(data, philo_id);
}

/**
 * @brief Deja los tenedores
 * 
 * @param data estructura de datos de la partida
 */
void	leave_fork(t_data *data)
{
	sem_post(data->sems.sem_fork);
}
