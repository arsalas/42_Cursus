/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:58:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/05 16:25:38 by aramirez         ###   ########.fr       */
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
	data.forks = data.params.n_philo * 2;
	data.semaphore = sem_open(SEM_NAME, O_CREAT, 0666, 5);
	create_process(&data);
	while (1)
		sleep(1);
	sem_unlink(SEM_NAME);
	return (0);
}
