#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STD_OUT 0
#define STD_IN 1
#define STD_ERR 2

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putstr(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

int print_error(char *str)
{
	ft_putstr(STD_ERR, str);
	return (EXIT_FAILURE);
}

int exec_cd(char *path)
{
	return (chdir(path));
}

int exec_pipe()
{
	int fd[2];
	int pid;

	// Comprobamos si el pipe ha salido bien
	if (pipe(fd) == -1)
	{
		print_error("error: fatal\n");
		exit(1);
	}
	pid = fork();
	// Comprobamos si ha salido bien
	if (pid == -1)
	{
		print_error("error: fatal\n");
		exit(1);
	}
	// Ejecutamos en el hijo
	if (pipe == 0)
	{
	}
	// esperamos a que termine el hijo
	waitpid(pid);
}

int read_tokens(int quantity, char **tokens, char **env)
{
	// Recorremos los tokens
	for (int i = 0; i < quantity; i++)
	{
		// Comprobamos si el token actual es un cd
		if (strcmp(tokens[i], "cd") == 0)
		{
			i++;
			// Comprobamos si hay un path
			if (!tokens[i] || strcmp(tokens[i], "|") == 0 || strcmp(tokens[i], ";") == 0)
				return (print_error("error: cd: bad arguments\n"));
			// Comprobamos si hay algo mas despues del path
			if (tokens[i + 1] && (strcmp(tokens[i + 1], "|") || strcmp(tokens[i + 1], ";")))
				return (print_error("error: cd: bad arguments\n"));
			if (exec_cd(tokens[i]) == -1)
			{
				print_error("error: cd: cannot change directory to ");
				print_error(tokens[i]);
				print_error("\n");
				return (1);
			}
			continue;
		}
		if (strcmp(tokens[i], ";") == 0)
			continue;
		if (exec_pipe() == -1)
			return (-1);
	}
	return (0);
}

int main(int argc, char *argv[], char *env[])
{

	if (argc > 1)
		return (read_tokens(argc - 1, &argv[1], env));
	return (0);
}
