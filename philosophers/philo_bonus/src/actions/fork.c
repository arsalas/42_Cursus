/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/06 17:22:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * Coge los tenedores para empezar a comer  
*/
void	take_fork(t_data *data, int philo_id)
{
	if (data->forks == 0)
		//sem_wait(data->semaphore);
		printf("Sem: %i\n", sem_wait(data->semaphore));
	if (!is_game_over(data))
	{
		print_log(philo_id + 1, FORK);
		data->forks -= 2;
	}
}

/**
 * Deja los tenedores  
*/
void	leave_fork(t_data *data)
{
	data->forks += 2;
	if (data->forks == 2)
		sem_post(data->semaphore);
}
