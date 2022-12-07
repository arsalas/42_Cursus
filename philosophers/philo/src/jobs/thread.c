/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/08 00:53:32 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Comprueba si ha terminado la partida
 * 
 * @param data estructura de datos
 * @return true si la partida ha terminado
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
	if (eats >= data->params.n_philo)
		return (true);
	return (false);
}

void	ft_action_one(t_data *data, int i)
{
	start_eat(data, i);
	my_usleep(data->params.t_eat);
}

void	ft_action_two(t_data *data, int i)
{
	if (get_timestamp() - data->philos[i].last_sleep > data->params.t_sleep)
		finish_sleep(data, i);
}

/**
 * @brief Logica de las acciones de los filosofos 
 * 
 * @param data estructura de datos
 * @param i posicion del filosofo
 */
static void	philo_actions(t_data *data, int i)
{
	if (get_timestamp() - data->philos[i].last_food > data->params.t_die
		&& data->philos[i].status != EAT)
		philo_die(data, i);
	ft_action_one(data, i);
	ft_action_two(data, i);
}

/**
 * @brief Inicia el proceso de vida de cada filosofo
 * 
 * @param d estructura de datos
 * @return void* 
 */
void	*philo_life(void *d)
{
	t_data		*data;
	static int	n = 0;
	int			i;

	i = n;
	n++;
	data = (t_data *)d;
	if (i % 2 != 0)
		my_usleep(10);
	while (!is_game_over(data))
	{
		philo_actions(data, i);
	}
	return (NULL);
}
