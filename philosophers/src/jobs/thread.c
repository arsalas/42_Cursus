/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/29 16:18:19 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * Inicia el proceso de vida de cada filosofo 
*/
void	*philo_life(void *d)
{
	static int	i = 0;
	t_data		*data;

	data = (t_data *)d;
	usleep(2000000);
	printf("TEST: %i\n", data->philos[i].id);
	usleep(2000000);
	i++;
	return (NULL);

	return (NULL);
}
