#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "./get_next_line.h"

int main(void)
{
    int fd = open("./text.txt", O_RDONLY);
    // printf("START: \n");
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("FIN: \n");
    return (0);
}