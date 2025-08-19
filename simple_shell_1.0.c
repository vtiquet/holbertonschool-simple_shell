#include "shell.h"

static int execute_shell_command(command_t *cmd, char **argv);
static void process_line(char *line, char **argv);

/**
* main - a function that implements a simple UNIX command line interpreter.
* @argc: the argument count.
* @argv: the argument vector.
* Return: always 0 on success.
*/
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (read_bytes > 1)
		{
			if (line[read_bytes - 1] == '\n')
				line[read_bytes - 1] = '\0';
			process_line(line, argv);
		}
	}
	free(line);
	return (0);
}

/**
* process_line - a function that parses and executes a single command line.
* @line: the command line string.
* @argv: the argument vector.
*/
static void process_line(char *line, char **argv)
{
	command_t *cmd = parse_command(line);
	int builtin_result;

	if (cmd == NULL)
	{
		return;
	}

	builtin_result = handle_builtin(cmd);
	if (builtin_result == 1)
	{
		free_command(cmd);
		return;
	}
	else if (builtin_result == 2)
	{
		free_command(cmd);
		free(line);
		exit(0);
	}

	execute_shell_command(cmd, argv);

	free_command(cmd);
}

/**
* execute_shell_command - a function that forks
* a child process and executes a command.
* @cmd: the command_t struct.
* @argv: the argument vector.
* Return: 0 on success, -1 on failure.
*/
static int execute_shell_command(command_t *cmd, char **argv)
{
	pid_t child_pid;
	int status;
	char *full_path = NULL;

	if (access((*cmd).cmd, X_OK) == 0)
	{
		full_path = _strdup((*cmd).cmd);
	}
	else
	{
		full_path = find_command_in_path((*cmd).cmd);
	}

	if (full_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], (*cmd).cmd);
		return (-1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: fork failed");
		free(full_path);
		return (-1);
	}

	if (child_pid == 0)
	{
		execve(full_path, (*cmd).args, environ);
		perror(argv[0]);
		free(full_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}

	free(full_path);
	return (0);
}

/**
* handle_builtin - a function that checks and handles built-in commands.
* @cmd: the command_t struct.
* Return: 1 if a built-in was handled, 2 if exit, 0 otherwise.
*/
int handle_builtin(command_t *cmd)
{
	if (_strcmp((*cmd).cmd, "exit") == 0)
	{
		return (2);
	}
	else if (_strcmp((*cmd).cmd, "env") == 0)
	{
		int i = 0;

		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (1);
	}
	else if (_strcmp((*cmd).cmd, "help") == 0)
	{
		print_help();
		return (1);
	}
	return (0);
}

/**
* print_help - a function that prints the help message for the shell.
*/
void print_help(void)
{
	printf("simple_shell, a simple UNIX command line interpreter.\n\n");
	printf("Usage:\n");
	printf("  simple_shell [FILE]\n\n");
	printf("Built-in Commands:\n");
	printf("  exit: Exits the shell.\n");
	printf("  env: Prints the current environment.\n");
	printf("  help: Displays this help message.\n\n");
}
