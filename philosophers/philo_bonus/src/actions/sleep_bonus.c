/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/07 14:19:40 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * El filosofo empieza a dormir 
*/
void	start_sleep(t_data *data, int philo_id)
{
	data->philo.last_sleep = get_timestamp();
	data->philo.status = SLEEP;
	print_log(data, philo_id + 1, SLEEP);
}

/**
 * El filosofo termina de dormir 
*/
void	finish_sleep(t_data *data, int philo_id)
{
	data->philo.last_sleep = get_timestamp();
	data->philo.status = THINK;
	print_log(data, philo_id + 1, THINK);
}
