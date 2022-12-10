/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:26:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 11:00:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	program_error(int error)
{
	if (error == 0)
		printf("Missing arguments\n");
	else
		printf("Incorrect format\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5)
		return (program_error(0));
	data.finish = 0;
	data.params = recive_args(argv);
	if (!data.params.correct_format)
		return (program_error(1));
	data.timestamp = get_timestamp();
	pthread_mutex_init(&data.fork_mutex, NULL);
	pthread_mutex_init(&data.log, NULL);
	if (create_data_forks(&data) == 0 || create_data_philos(&data) == 0)
	{
		return (0);
	}
	i = 0;
	while (i < data.params.n_philo)
	{
		if (pthread_join(data.philos[i].thread, NULL) == -1)
			return (-1);
		i++;
	}
	destroy_data(&data);
	return (0);
}
