/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:58:34 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 16:27:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Obtiene el timestamp
 * 
 * @return timestamp
 */
long long	get_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	my_usleep(int num)
{
	long long int	time;

	time = get_timestamp();
	while ((get_timestamp() - time < num))
	{
		usleep(200);
	}
}
