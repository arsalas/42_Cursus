/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/05 15:57:13 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	philo_die(t_data *data, int philo_id)
{
	print_log(philo_id + 1, DIE);
	data->philos[philo_id].is_alive = false;
	exit(0);
}
