/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:25:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/06 16:18:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//TODO: Crear un thread para comprobar si los filosofos mueren
//TODO: Crear un thread para comprobar si todos los filosofos han comido
//TODO: Crear un listado de acciones.







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
	data->i = i;
	while (!is_game_over(data))
	{
		if (i >= data->params.n_philo)
			continue ;
		if (get_timestamp() - data->philos[i].last_food > data->params.t_die
			&& data->philos[i].status != EAT)
		{
			philo_die(data, i);
			close_program(data);
		}
		else if (data->philos[i].status == THINK)
			//take_fork(data, i);
			pthread_create(&data->thread, NULL, &start_eat, data);
		else if (data->philos[i].status == EAT
			&& get_timestamp() - data->philos[i].last_food > data->params.t_eat)
			finish_eat(data, i);
		else if (data->philos[i].status == SLEEP && get_timestamp()
			- data->philos[i].last_sleep > data->params.t_sleep)
			finish_sleep(data, i);
		usleep(10);
	}
}
