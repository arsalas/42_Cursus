#include "./get_next_line.h"
int have_line(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int str_line(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i + 1);
}

int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *get_line(char *str)
{
    int len;
    int i;
    char *new;

    len = str_line(str);
    new = malloc(sizeof(char) * (len + 1));
    if (new == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

void mem_move(char *str)
{
    int n;
    int i;
    int len;

    n = str_line(str);
    len = str_len(str);
    i = 0;
    while (i < len - n)
    {
        str[i] = str[i + n];
        str[i + n] = '\0';
        i++;
    }
    str[i] = '\0';
}

char *get_last_line(char *str)
{
    int len;
    int i;
    char *new;

    len = str_len(str);
    new = malloc(sizeof(char) * (len + 1));
    if (new == NULL)
        return (NULL);
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char *str_join(char *str, char *storage)
{
    int len;
    int len_s;
    char *new;
    int i;
    int i2;

    if (storage == NULL)
        len_s = 0;
    else
        len_s = str_len(storage);
    len = str_len(str);
    new = malloc(sizeof(char) * (len + len_s + 1));
    if (new == NULL)
    {
        free(storage);
        return (NULL);
    }
    i = 0;
    while (storage && storage[i])
    {
        new[i] = storage[i];
        i++;
    }
    i = 0;
    while (str[i])
    {
        new[i + len_s] = str[i];
        i++;
    }
    new[i + len_s] = '\0';
    free(storage);
    return (new);
}

char *get_next_line(int fd)
{
    static char *storage;
    char buffer[BUFFER_SIZE + 1];
    char *str;
    int nb;

    if (fd == -1 || fd > FOPEN_MAX)
        return (NULL);
    if (storage != NULL && have_line(storage) == 1)
    {
        str = get_line(storage);
        if (str == NULL)
        {
            free(storage);
            return (NULL);
        }
        mem_move(storage);
        return (str);
    }
    nb = read(fd, buffer, BUFFER_SIZE);
    if (nb == -1)
    {
        free(storage);
        return (NULL);
    }
    if (nb == 0)
    {
        if (storage != NULL)
        {
            str = get_last_line(storage);
            free(storage);
            storage = NULL;
            return (str);
        }
        return (NULL);
    }
    buffer[nb] = '\0';
    storage = str_join(buffer, storage);
    if (storage == NULL)
        return (NULL);
    return (get_next_line(fd));
}


