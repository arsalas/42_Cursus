/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:19:47 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/13 13:00:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * Crea los procesos de los filosofos
*/
void	create_process(t_data *data)
{
	int		i;
	t_philo	philo;

	data->philos = malloc(sizeof(t_philo) * data->params.n_philo);
	if (data->philos == NULL)
		return ;
	i = 0;
	while (i < data->params.n_philo)
	{
		philo.id = i + 1;
		philo.is_alive = true;
		philo.last_food = get_timestamp();
		philo.last_sleep = 0;
		philo.n_eat = 0;
		philo.status = THINK;
		data->philos[i] = philo;
		if (i == data->params.n_philo - 1)
			data->start = true;
		data->philos[i].c_pid = fork();
		if (data->philos[i].c_pid == -1)
			exit(EXIT_FAILURE);
		if (data->philos[i].c_pid == 0)
		{
			process_start(data, i);
			break ;
		}
		usleep(10);
		i++;
	}
	int status;
	for(int j = 0; j < data->params.n_philo; j++)
		waitpid(data->philos[j].c_pid, &status, 0);

}
