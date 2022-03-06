
#include <unistd.h>
#include <ctype.h>

void    print_char(char c)
{
    write(1, &c, 1);
}

void    print_void(void)
{
    write(1, "* LOUD AND UNBEARABLE FEEDBACK NOISE *", 38);
}

void    megaphone(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (isupper(str[i]) == 0 && isalpha(str[i]) != 0)
            print_char(toupper(str[i]));
        else
            print_char(str[i]);
        i++;
    }
    
}

int main(int argc, char *argv[])
{
    int i;

    i = 1;
    if (argc == 1)
    {
        print_void();
    }
    else
    {
        while (argv[i])
        {
            megaphone(argv[i]);
            i++;
        }
    }
    print_char('\n');
    return (0);
}