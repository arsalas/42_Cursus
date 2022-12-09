/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 20:44:07 by aramirez         ###   ########.fr       */
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

bool	ft_action_one(t_data *data, int i)
{
	int	forks;

	forks = 0;
	if (can_take_fork(data, i, 1))
		forks++;
	if (data->params.n_philo == 1)
	{
		my_usleep(data->params.t_die + 1);
		return (false);
	}
	if (can_take_fork(data, i, 2))
		forks++;
	// printf("THE FORKS ARE: %d\n", forks);
	if (forks == 2)
	{
		start_eat(data, i);
		my_usleep(data->params.t_eat);
		leave_fork(data, i);
		return (true);
	}
	return (false);
}

void	ft_action_two(t_data *data, int i)
{
	print_log(data, i + 1, SLEEP);
	my_usleep(data->params.t_sleep);
	finish_sleep(data, i);
}

/**
 * @brief Logica de las acciones de los filosofos 
 * 
 * @param data estructura de datos
 * @param i posicion del filosofo
 */
void	philo_actions(t_data *data, int i)
{
	if (get_timestamp() - data->philos[i].last_food > data->params.t_die)
		philo_die(data, i);
	if (!ft_action_one(data, i))
		return ;
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
	data->philos[i].last_food = get_timestamp();
	if (i % 2 != 0)
		my_usleep(data->params.t_eat -1);
	while (!data->finish)
	{
		pthread_mutex_lock(&data->philos[i].fork_mutex);
		print_log(data, i + 1, FORK);
		// if (data->params.n_philo == 1)
		// {
		// 	my_usleep(data->params.t_die);
		// 	printf("1\n");
		// 	pthread_mutex_unlock(&data->philos[i].fork_mutex);
		// 	return (NULL);
		// }
		pthread_mutex_lock(&data->philos[next_fork(i, data->params.n_philo)].fork_mutex);
		print_log(data, i + 1, FORK);
		print_log(data, i + 1, EAT);
		data->eats--;
		data->philos[i].last_food = get_timestamp();
		my_usleep(data->params.t_eat);
		pthread_mutex_unlock(&data->philos[i].fork_mutex);
		pthread_mutex_unlock(&data->philos[next_fork(i, data->params.n_philo)].fork_mutex);
		print_log(data, i + 1, SLEEP);
		my_usleep(data->params.t_sleep);
		print_log(data, i + 1, THINK);
	}
	n = 0;
	return (NULL);
}
