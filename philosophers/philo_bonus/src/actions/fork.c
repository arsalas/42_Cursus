/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/12 14:29:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * Coge los tenedores para empezar a comer  
*/
void	take_fork(t_data *data, int philo_id)
{
	sem_wait(data->semaphore);
	sem_wait(data->semaphore);
	if (!is_game_over(data))
	{
		print_log(philo_id + 1, FORK);
		data->forks -= 2;
	}
	sem_post(data->semaphore);
}

/**
 * Deja los tenedores  
*/
void	leave_fork(t_data *data)
{
	sem_post(data->semaphore);
	sem_post(data->semaphore);
}
