#include "shell.h"

/**
 * find_in_path - Finds command in PATH
 * @cmd: Command to find
 * Return: Full path or NULL
 */
char *find_in_path(char *cmd)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
			return (strdup(cmd));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (full_path)
		{
			printf(full_path, "%s/%s", dir, cmd);
			if (stat(full_path, &st) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

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
			status = shell_execute(args, argv[0]);
	}

	cleanup(&line, &args);
	return (EXIT_SUCCESS);
}
