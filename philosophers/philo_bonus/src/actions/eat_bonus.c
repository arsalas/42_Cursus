/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:24 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/07 00:16:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief El filosofo empieza a comer 
 * 
 * @param data estructura de datos del programa
 * @param philo_id id del filosofo
 */
void	start_eat(t_data *data, int philo_id)
{
	data->philo.last_food = get_timestamp();
	data->philo.status = EAT;
	print_log(data, philo_id + 1, EAT);
	data->philo.n_eat++;
}

/**
 * @brief El filosofo deja de comer 
 * 
 * @param data estructura de datos del programa
 * @param philo_id id del filosofo
 */
void	finish_eat(t_data *data, int philo_id)
{
	leave_fork(data);
	start_sleep(data, philo_id);
}
