
#include "minishell.h"

int main(void)
{
    char    *str;     while (1)
    {
        str = readline("Myshell $ ");
        printf("%s", str);
    }
    return (0);
}