/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:05:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/02 18:00:22 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
// compile with $ gcc -Wall -g *.c -pthread -o program
// run with ./program
// check with valgrind --tool=helgrind ./program
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_params
{
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int time_eats;
}	t_params;

int	ft_atoi(const char *str)

int	main(void)
{
	newZombie("Zomb1");
	randomChump("Zomb2");
	return (0);
}