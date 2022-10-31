/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:24 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/05 16:04:31 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * El filosofo empieza a comer 
*/
void	start_eat(t_data *data, int philo_id)
{
	take_fork(data, philo_id);
	data->philos[philo_id].last_food = get_timestamp();
	data->philos[philo_id].status = EAT;
	if (!is_game_over(data))
		print_log(philo_id + 1, EAT);
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

