#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int contain_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int strlenline(char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i + 1);
}

char *extract_line(char *str)
{
    int len;
    char *n_str;
    int i;

    len = strlenline(str);
    n_str = malloc(sizeof(char) * (len + 1));
    if (!n_str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        n_str[i] = str[i];
        i++;
    }
    n_str[i] = '\0';
    return (n_str);
}

void str_join(char *storage, char *str)
{
    long long len;
    int i;

    len = strlen(storage);
    while (str[i])
    {
        storage[len + i] = str[i];
        i++;
    }
}

void store_extraline(char *storage, char *buf)
{
    long long len;

    len = strlen(buf) - strlenline(buf);
    if (len > 10000)
        return;
    str_join(storage, &buf[strlenline(buf)]);
}

void    mem_move(char *str, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        str[i] = str[len + i];
        i++;
    }
    str[i] = '\0';
}

char *gnl(int fd)
{
    char *buf;
    static char *storage;
    size_t br;
    char *str;

    if (!storage)
        storage = malloc(sizeof(char) * 10000);
    else if (contain_line(storage) == 1)
    {
        str = extract_line(storage);
        if (strlen(str) < strlen(storage))
            mem_move(storage, strlen(str));
        return (str);
    }
    buf = malloc(sizeof(char) * (52 + 1));
    if (!buf)
        return (buf);
    br = read(fd, buf, 52);
    if (br == -1)
        return (NULL);
    buf[br] = '\0';
    if (contain_line(buf) == 1)
    {
        if (storage && strlen(storage) > 0)
        {
            str_join(storage, buf);
            str = extract_line(buf);
            if (strlen(str) < strlen(buf))
                store_extraline(storage, buf);
            free(buf);
            return (str);        }
        else
        {
            str = extract_line(buf);
            if (strlen(str) < strlen(buf))
                store_extraline(storage, buf);
            free(buf);
            return (str);
        }
    }
    else
    {
        return (NULL);
    }
    return (NULL);
}

/* *
1-Comprobar si el storage tiene una linea
2a-Si hay linea imprimirla
2b-Si no hay leer hasta encontrar el final de la linea o del documento
3-Crear la str con la line
4-Mirar si queda mas texto despues del final de linea
5-Guardar lo que ha sobrado haciendo un join con el storage

*/
