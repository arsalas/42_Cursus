/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:24 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/08 16:39:06 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * El filosofo empieza a comer 
*/
void	start_eat(t_data *data, int philo_id)
{
	data->philo.last_food = get_timestamp();
	data->philo.status = EAT;
	print_log(data, philo_id + 1, EAT);
}

/**
 * El filosofo deja de comer 
*/
void	finish_eat(t_data *data, int philo_id)
{
	leave_fork(data);
	data->philo.n_eat++;
	start_sleep(data, philo_id);
}
