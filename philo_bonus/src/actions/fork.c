/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/05 16:22:43 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * Obtiene la posicion en el array del siguiente tenedor al filosofo 
*/
int	next_fork(int pos, int max)
{
	if (pos == max - 1)
		return (0);
	else
		return (pos + 1);
}

/**
 * Inica si el filosofo pueded coger los tenedores
*/
bool	can_take_fork(t_data *data)
{
	bool	can;

	printf("ENTRO FORK\n");
	can = false;
	sem_wait(data->semaphore);
	if (data->forks >= 2)
		can = true;
	sem_close(data->semaphore);
	printf("FIN FORK\n");
	return (can);
}

/**
 * Coge los tenedores para empezar a comer  
*/
void	take_fork(t_data *data, int philo_id)
{
	sem_wait(data->semaphore);
	if (!is_game_over(data))
	{
		print_log(philo_id + 1, FORK);
		data->forks -= 2;
	}
	sem_close(data->semaphore);
}

/**
 * Deja los tenedores  
*/
void	leave_fork(t_data *data)
{
	sem_wait(data->semaphore);
	data->forks += 2;
	sem_close(data->semaphore);
}
