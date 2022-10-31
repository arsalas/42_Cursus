#include <unistd.h>
#include <stdbool.h>

bool is_delimiter(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

unsigned int str_len(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int get_first_index(char *str, unsigned int l)
{
	while (!is_delimiter(str[l]))
		l--;
	return (l + 1);
}

unsigned int get_last_index(char *str)
{
	unsigned int l;

	l = str_len(str) - 1;
	while (is_delimiter(str[l]))
		l--;
	return (l);
}

void get_last_word(char *str)
{
	unsigned int first;
	unsigned int last;

	last = get_last_index(str);
	first = get_first_index(str, last);
	write(1, &str[first], last - first);
}

int main(int argc, char **argv)
{
	if (argc == 2){
		get_last_word(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
