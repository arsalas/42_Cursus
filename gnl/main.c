#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *gnl(int fd);

int main(void)
{
    int fd = open("./text.txt", O_RDONLY);
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
    return (0);
}