/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/05 14:15:53 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * Recivir argumentos del programa y guardarlos en una estructura
 */
t_params	recive_args(char **argv)
{
	t_params	params;

	params.n_philo = ft_atoi(argv[1]);
	params.t_die = ft_atoi(argv[2]);
	params.t_eat = ft_atoi(argv[3]);
	params.t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params.time_eats = ft_atoi(argv[5]);
	else
		params.time_eats = -1;
	return (params);
}
