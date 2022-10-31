
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int print_str(char *str)
{
	int	i;

	if (!str)
	 return (print_str("(null)"));
	i = 0;
	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
	return (i);
}
int print_base(unsigned int n, int bs)
{
	long	num;
	int		count;
	char	*base = "0123456789abcdef";

	num = n;
	count = 0;
	if (num >= bs)
	{
		count += print_base(num / bs, bs);
		num %= bs; 
	}
	count += print_char(base[num]);
	return (count);
}

int print_base_long(unsigned long num, int bs)
{
	int		count;
	char	*base = "0123456789abcdef";

	count = 0;
	if (num >= bs)
	{
		count += print_base_long(num / bs, bs);
		num %= bs; 
	}
	count += print_char(base[num]);
	return (count);
}

int print_hexa(unsigned int num)
{
	return (print_base(num, 16));
}

int print_pointer(unsigned long long num)
{
	return (print_str("0x") + print_base_long(num, 16));
}

/**
 * @author aramirez
 * @param int numero a poner por pantalla
 * @return El numero de caracteres imprimidos
 * @details description
 * */
int print_num(int num)
{
	int count;

	count = 0;
	if (num < 0)
	{
		num = -num;
		count += print_char('-');
	}
	return (count + print_base(num, 10));
}

int selec_type(va_list args, char type)
{
	if (type == 's')
		return (print_str(va_arg(args, char *)));
	if (type == 'd')
		return (print_num(va_arg(args, int)));
	if (type == 'x')
		return (print_hexa(va_arg(args, unsigned int)));
	if (type == 'p')
		return (print_pointer(va_arg(args, unsigned long long)));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		numchars;
	int		i;

	numchars = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			numchars += selec_type(args, str[i]);
		}
		else
			numchars += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (numchars);
}

int main(void)
{
	char	p;
	char	*str;

	p = 10;
	str = NULL;
	printf(" | len: %i\n", ft_printf("Str: Hola %s", "Mundo"));
	printf(" | len: %i\n", printf("Str: Hola %s", "Mundo"));
	printf(" | len: %i\n", ft_printf("Str: %s", str));
	printf(" | len: %i\n", printf("Str: %s", str));
	printf(" | len: %i\n", ft_printf("Num: %d", INT_MIN));
	printf(" | len: %i\n", printf("Num: %d", INT_MIN));
	printf(" | len: %i\n", ft_printf("Num: %d", INT_MAX));
	printf(" | len: %i\n", printf("Num: %d", INT_MAX));
	printf(" | len: %i\n", ft_printf("Hexa: %x",INT_MIN));
	printf(" | len: %i\n", printf("Hexa: %x",INT_MIN));
	printf(" | len: %i\n", ft_printf("Pointer: %p", &p));
	printf(" | len: %i\n", printf("Pointer: %p", &p));
	return (0);
}
