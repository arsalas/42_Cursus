/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/31 18:36:49 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Accion de muerte del filosofo
 * 
 * @param data estructura de datos
 * @param philo_id id del filosofo
 */
void	philo_die(t_data *data, int philo_id)
{
	print_log(data, philo_id + 1, DIE);
	data->finish = 1;
	data->philos[philo_id].is_alive = false;
}
