/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:58:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/20 14:33:41 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 4)
		return (0);
	data.finish = 0;
	data.params = recive_args(argv);
	data.forks = data.params.n_philo;
	data.timestamp = get_timestamp();
	data.semaphore = sem_open("forks_sem", O_CREAT, S_IRWXU,
			data.params.n_philo - 1);
	data.sem_log = sem_open("print_log2", O_CREAT, S_IRWXU, 0);
	create_process(&data);
	sem_close(data.semaphore);
	sem_close(data.sem_log);
	sem_unlink("forks_sem");
	sem_unlink("print_log2");
	return (0);
}
