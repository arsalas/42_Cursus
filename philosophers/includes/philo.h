/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:47:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/29 16:18:12 by aramirez         ###   ########.fr       */
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
# include <sys/time.h>    

typedef enum e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_actions;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			n_eat;
	long long	last_food;
	long long	last_sleep;
	t_actions	action;
}	t_philo;

typedef struct s_params
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	time_eats;
}	t_params;

typedef struct s_data
{
	t_params	params;
	t_philo		*philos;
	int			finish;
}	t_data;

int			ft_atoi(const char *str);
long long	get_timestamp(void);
t_params	recive_args(char **argv);
void		print_log(int philo, t_actions action);
void		create_data_philos(t_data *data, int n);
void		*philo_life(void *d);

#endif