
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    FILE *fd;

    fd = fopen("file.txt", "r");
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    return (0);
}