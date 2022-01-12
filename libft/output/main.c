#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

int main()
{
    int num = 350;
    char path[MAX_BUF];
    char buffer[MAX_BUF];

    FILE *fptr;
    fptr = fopen("./src/js/data.js", "w");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    char *user = getenv("USERNAME"); 
    fprintf(fptr, "const user = '%s';\n", user);
    fprintf(fptr, "const data = [{name:'ft_atoi', result: true},{name:'ft_bzero', result: false},{name:'ft_calloc', result: false}]");
    fclose(fptr);
    getcwd(path, MAX_BUF);
    memccpy(memccpy(buffer, path, '\0', MAX_BUF) - 1, "/src/index.html", '\0', MAX_BUF);
    system(buffer);

    return (0);
}