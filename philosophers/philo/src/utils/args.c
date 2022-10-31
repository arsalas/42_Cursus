/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/06 14:33:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * Recivir argumentos del programa y guardarlos en una estructura
 */
t_params	recive_args(char **argv)
{
	t_params	params;

	params.correct_format = true;
	params.n_philo = ft_atoi(argv[1]);
	params.t_die = ft_atoi(argv[2]);
	params.t_eat = ft_atoi(argv[3]);
	params.t_sleep = ft_atoi(argv[4]);
	if (params.n_philo < 0 || params.t_die < 0
		|| params.t_eat < 0 || params.t_sleep < 0)
		params.correct_format = false;
	if (argv[5])
	{
		params.time_eats = ft_atoi(argv[5]);
		if (params.n_philo < 0 || params.t_die < 0
			|| params.t_eat < 0 || params.t_sleep < 0)
			params.correct_format = false;
	}
	else
		params.time_eats = -1;
	return (params);
}
