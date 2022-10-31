/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:58:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/08 13:45:39 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 4)
		return (0);
	data.params = recive_args(argv);
	data.timestamp = get_timestamp();
	create_semaphores(&data);
	create_process(&data);
	while (true)
		usleep(10);
	return (0);
}
