/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/08 00:15:39 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	is_arg_valid(char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
	{
		if (!is_num(argv[count]))
			return (false);
		count++;
	}
	return (true);
}

/**
 * @brief Recibir argumentos del programa y guardarlos en una estructura
 * 
 * @param argv argumentos del prgrama
 * @return t_params estructura de datos
 */
t_params	recive_args(char **argv)
{
	t_params	params;

	if (is_arg_valid(&argv[1]))
		params.correct_format = true;
	else
		params.correct_format = false;
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
