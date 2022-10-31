/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:58:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/19 13:30:32 by aramirez         ###   ########.fr       */
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
	data.semaphore = sem_open("forks", O_CREAT, S_IRWXU, data.params.n_philo - 1);
	//sem_post(data.semaphore);
	create_process(&data);
	sem_close(data.semaphore);
	sem_unlink("forks");
	return (0);
}
