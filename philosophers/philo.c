/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:26:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/29 16:52:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"
// TODO PONER MUTEX A LAS VARIABLES PARA ESCRIBIR
int	main(int argc, char **argv)
{
	t_data		data;

	if (argc < 4)
		return (0);
	data.finish = 0;
	data.params = recive_args(argv);
	data.philos = malloc(sizeof(t_philo) * data.params.n_philo);
	if (data.philos == NULL)
		return (0);
	create_data_philos(&data, data.params.n_philo);
	print_log(1, FORK);
	print_log(3, DIE);
	while (data.finish == 0)
		usleep(1);
	print_log(3, EAT);
	return (0);
}
