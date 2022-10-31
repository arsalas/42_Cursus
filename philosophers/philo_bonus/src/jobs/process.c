/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:25:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/11 12:49:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * Comprueba si ha terminado la partida
*/
bool	is_game_over(t_data *data)
{
	int	i;
	int	eats;

	i = 0;
	eats = 0;
	while (i < data->params.n_philo)
	{
		if (data->philos[i].is_alive == false && data->start)
			return (true);
		if (data->philos[i].n_eat >= data->params.time_eats)
			eats++;
		i++;
	}
	if (data->params.time_eats == -1)
		return (false);
	if (eats == data->params.n_philo)
		return (true);
	return (false);
}

/**
 * Inicia el proceso del filosofo 
*/
void	process_start(t_data *data, int i)
{
	while (!is_game_over(data))
	{
		if (i >= data->params.n_philo)
			continue ;
		if (get_timestamp() - data->philos[i].last_food > data->params.t_die
			&& data->philos[i].status != EAT)
			philo_die(data, i);
		else if (data->philos[i].status == THINK)
			start_eat(data, i);
		else if (data->philos[i].status == EAT)
		{
			if (get_timestamp() - data->philos[i].last_food > data->params.t_eat)
				finish_eat(data, i);
		}
		else if (data->philos[i].status == SLEEP)
		{
			if (get_timestamp() - data->philos[i].last_sleep > data->params.t_sleep)
				finish_sleep(data, i);
		}
		usleep(10);
	}
	//exit(0);
}
