/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/08 16:44:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief El filosofo empieza a dormir 
 * 
 * @param data estructura de datos del programa
 * @param philo_id id del filosofo
 */
void	start_sleep(t_data *data, int philo_id)
{
	data->philo.last_sleep = get_timestamp();
	data->philo.status = SLEEP;
	print_log(data, philo_id + 1, SLEEP);
}

/**
 * @brief El filosofo termina de dormir 
 * 
 * @param data estructura de datos del programa
 * @param philo_id id del filosofo
 */
void	finish_sleep(t_data *data, int philo_id)
{
	data->philo.last_sleep = get_timestamp();
	data->philo.status = THINK;
	print_log(data, philo_id + 1, THINK);
}
