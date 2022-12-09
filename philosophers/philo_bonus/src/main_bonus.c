/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:58:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 14:34:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

	if (argc < 4)
		return (0);
	close_semaphores(&data);
	unlink_semaphores();
	data.params = recive_args(argv);
	if (!data.params.correct_format)
		return (program_error(1));
	if (data.params.n_philo == 0 || data.params.time_eats == 0)
		return (0);
	data.timestamp = get_timestamp();
	create_semaphores(&data);
	create_process(&data);
	while (true)
		usleep(10);
	return (0);
}
