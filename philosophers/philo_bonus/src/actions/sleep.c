/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/05 15:56:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * El filosofo empieza a dormir 
*/
void	start_sleep(t_data *data, int philo_id)
{
	data->philos[philo_id].last_sleep = get_timestamp();
	data->philos[philo_id].status = SLEEP;
	if (!is_game_over(data))
		print_log(philo_id + 1, SLEEP);
}

/**
 * El filosofo termina de dormir 
*/
void	finish_sleep(t_data *data, int philo_id)
{
	data->philos[philo_id].last_sleep = get_timestamp();
	data->philos[philo_id].status = THINK;
	if (!is_game_over(data))
		print_log(philo_id + 1, THINK);
}
