/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:24 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/07 23:56:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief El filosofo empieza a comer 
 * 
 * @param data estructura de datos
 * @param philo_id id del filosofo
 */
void	start_eat(t_data *data, int philo_id)
{
	take_fork(data, philo_id);
	data->philos[philo_id].last_food = get_timestamp();
	data->philos[philo_id].status = EAT;
	print_log(data, philo_id + 1, EAT);
	data->philos[philo_id].n_eat++;
}

/**
 * @brief El filosofo deja de comer 
 * 
 * @param data estructura de datos
 * @param philo_id id del filosofo
 */
void	finish_eat(t_data *data, int philo_id)
{
	leave_fork(data, philo_id);
	start_sleep(data, philo_id);
}
