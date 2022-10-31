
#include "./philo.h"

void *thread_run(void *data)
{
    sleep(2);
    printf("[TH_1:%ld]: Hello from the thread \n", pthread_self());
    sleep(1);
    (*(int *)data)++;
    printf("[TH_1: %ld]: To exit...............\n", pthread_self());
    pthread_exit(data);
}

/**
 * Recivir argumentos del programa y guardarlos en una estructura
*/
t_params    recive_args(char **argv)
{
    t_params    params;

    params.n_philo = ft_atoi(argv[1]);
    params.t_die = ft_atoi(argv[2]);
    params.t_eat = ft_atoi(argv[3]);
    params.t_sleep = ft_atoi(argv[4]);
    if (argv[5])
        params.time_eats = ft_atoi(argv[5]);
    return (params);
}

int main(int argc, char **argv)
{
    pthread_t thread;
    int data = 0;
    int thread_rc;
    t_params    params;

    if (argc < 4)
        return (0);
    params = recive_args(argv);
    printf("[MAIN:%ld]: Starting............ \n", pthread_self());
    if ((thread_rc = pthread_create(&thread, NULL, thread_run, &data)) != 0)
    {
        printf("Error creating the thread. Code %i", thread_rc);
        return -1;
    }
    sleep(1);
    printf("[MAIN:%ld]: Thread allocated \n", pthread_self());
    int *ptr_output_data;
    pthread_join(thread, (void **)&ptr_output_data);
    printf("[MAIN:%ld]: Thread returns %d \n", pthread_self(), *ptr_output_data);
    return 0;
}