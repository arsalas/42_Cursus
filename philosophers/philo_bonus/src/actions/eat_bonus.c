/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:24 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/20 12:36:02 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * El filosofo empieza a comer 
*/
void	*start_eat(void *p_data)
{
	t_data	*data;

	data = (t_data *)p_data;
	take_fork(data, data->i);
	data->philos[data->i].last_food = get_timestamp();
	data->philos[data->i].status = EAT;
	print_log(data, data->i + 1, EAT);
	return (NULL);
}

/**
 * El filosofo deja de comer 
*/
void	finish_eat(t_data *data, int philo_id)
{
	leave_fork(data);
	data->philos[philo_id].last_food = get_timestamp();
	data->philos[philo_id].n_eat++;
	start_sleep(data, philo_id);
}
