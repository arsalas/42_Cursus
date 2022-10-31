
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:47:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/28 16:59:42 by aramirez         ###   ########.fr       */
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

typedef struct s_params
{
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int time_eats;
}	t_params;

typedef struct s_philo
{
    int         id;
    int         n_eat;
    long long   last_food;
    long long   last_sleep;
}	t_philo;

int         ft_atoi(const char *str);
long long   get_timestamp(void);
t_params    recive_args(char **argv);


#endif