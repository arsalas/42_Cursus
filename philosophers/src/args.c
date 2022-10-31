#include "../includes/philo.h"

/**
 * Recivir argumentos del programa y guardarlos en una estructura
 */
t_params recive_args(char **argv)
{
    t_params params;

    params.n_philo = ft_atoi(argv[1]);
    params.t_die = ft_atoi(argv[2]);
    params.t_eat = ft_atoi(argv[3]);
    params.t_sleep = ft_atoi(argv[4]);
    if (argv[5])
        params.time_eats = ft_atoi(argv[5]);
    return (params);
}
