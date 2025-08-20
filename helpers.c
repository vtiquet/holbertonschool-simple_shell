#include "shell.h"

/**
 * shell_read_line - Reads input line
 * Return: Pointer to the line
 */
char *shell_read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

/**
 * shell_split_line - Splits line into tokens
 * @line: Input line
 * Return: Array of tokens
 */
char **shell_split_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * shell_execute - Execute a command with args
 * @args: Array of args
 * @shell_name: Name for error messages
 * @cmd_count: Command counter for error messages
 * Return: 1 to continue, 0 to exit
 */
int shell_execute(char **args, char *shell_name, int cmd_count)
{
	pid_t pid;
	int status;
	char *full_path;
	int builtin_status;

	if (!args[0])
		return (1);

	builtin_status = shell_execute_builtin(args);
	if (builtin_status != -1)
		return (builtin_status);

	full_path = get_path(args[0]);
	if (!full_path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", shell_name, cmd_count, args[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror(shell_name);
			free(full_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		free(full_path);
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(full_path);
	}
	return (1);
}
