/* simple_shell.c */
#include "shell.h"

/**
 * main - A super simple shell that can run commands with their full path.
 * @ac: The argument count.
 * @av: The argument vector.
 * @env: The environment variables.
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	pid_t child_pid;
	int status;
	char *argv[2];

	(void)ac;
	(void)av;
	(void)env;

	while (1)
	{
		printf("#cisfun$ ");
		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
		{
			printf("\n");
			break;
		}
		if (read_bytes > 0 && line[read_bytes - 1] == '\n')
			line[read_bytes - 1] = '\0';

		argv[0] = line;
		argv[1] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, environ);
			perror("Error");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	free (line);
	return (0);
}
