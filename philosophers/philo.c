
#include "./includes/philo.h"


int main(int argc, char **argv)
{
    t_params params;

    printf("timestamp: %lli\n", get_timestamp());
    if (argc < 4)
        return (0);
    params = recive_args(argv);
    printf("%i\n", params.t_die);

    return (0);
}