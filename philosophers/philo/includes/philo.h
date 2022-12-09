/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:47:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 20:46:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# include "colors.h"

# define SEC 1000000
# define MS 100000

typedef enum e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_status;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				n_eat;
	bool			is_alive;
	long long		last_food;
	long long		last_sleep;
	t_status		status;
	pthread_mutex_t	fork_mutex;
}	t_philo;

typedef struct s_params
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		time_eats;
	bool	correct_format;
}	t_params;

typedef struct s_data
{
	t_params		params;
	t_philo			*philos;
	int				*forks;
	int				finish;
	long			timestamp;
	int				eats;
	int				death;
	pthread_t		thread_die;
	bool			start;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	log;
}	t_data;

int			ft_atoi(const char *str);
long long	get_timestamp(void);
t_params	recive_args(char **argv);
void		print_log(t_data *data, int philo, t_status action);
int			create_data_philos(t_data *data);
int			create_data_forks(t_data *data);
void		*philo_life(void *d);
void		start_eat(t_data *data, int philo_id);
void		finish_eat(t_data *data, int philo_id);
void		start_sleep(t_data *data, int philo_id);
void		finish_sleep(t_data *data, int philo_id);

void		take_fork(t_data *data, int philo_id);
void		leave_fork(t_data *data, int philo_id);
int			next_fork(int pos, int max);
bool		can_take_fork(t_data *data, int philo_id, int type);
void		philo_die(t_data *data, int philo_id);
bool		is_game_over(t_data *data);
void		destroy_data(t_data *data);
void		my_usleep(int num);

#endif