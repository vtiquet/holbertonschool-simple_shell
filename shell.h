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
	int command_count = 0;
	(void)argc;

	while (status)
	{
		command_count++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

		cleanup(&line, &args);
		line = shell_read_line();
		if (!line)
			break;

		args = shell_split_line(line);
		if (!args || !args[0])
			continue;

		status = shell_execute(args, argv[0], command_count);
		if (status == 0)
		break;
	}

	cleanup(&line, &args);
	return (0);
}
