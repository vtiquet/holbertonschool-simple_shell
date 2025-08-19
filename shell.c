#include "shell.h"

/**
 * cleanup - Free resources and reset pointers
 * @line: Pointer to input line
 * @args: Pointer to arguments array
 */
static void cleanup(char **line, char ***args)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (*args)
	{
		free(*args);
		*args = NULL;
	}
}

/**
 * main - Entry point of simple shell
 * @argc: Argument count (unused)
 * @argv: Argument vector
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;
	int command_count = 1;
	(void)argc;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf(PROMPT);

		cleanup(&line, &args);
		line = shell_read_line();
		if (!line)
			break;

		args = shell_split_line(line);
		if (args)
			status = shell_execute(args, argv[0], command_count++);
	}

	cleanup(&line, &args);
	return (EXIT_SUCCESS);
}
