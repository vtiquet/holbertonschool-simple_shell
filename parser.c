#include "shell.h"

/**
* parse_command - a function tha splits a string into a command_t struct.
* @line: the string to parse.
* Return: a pointer to the command_t struct, or NULL on failure.
*/
command_t *parse_command(char *line)
{
	command_t *cmd;
	char *token;
	int i = 0, count = 0;
	char **args;
	char *line_copy;

	if (!line || *line == '\0')
		return (NULL);

	line_copy = _strdup(line);
	if (!line_copy)
		return (NULL);

	token = _strtok(line_copy, " \t\n");
	while (token)
	{
		count++;
		token = _strtok(NULL, " \t\n");
	}
	free(line_copy);

	if (count == 0)
		return (NULL);

	cmd = malloc(sizeof(command_t));
	if (!cmd)
		return (NULL);

	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
	{
		free(cmd);
		return (NULL);
	}

	token = _strtok(line, " \t\n");
	if (token)
	{
		args[i] = _strdup(token);
		if (!args[i])
		{
			free(args);
			free(cmd);
			return (NULL);
		}
		i++;
	}

	while ((token = _strtok(NULL, " \t\n")))
	{
		args[i] = _strdup(token);
		if (!args[i])
		{
			while (i > 0)
				free(args[--i]);
			free(args);
			free(cmd);
			return (NULL);
		}
		i++;
	}

	(*cmd).cmd = args[0];
	(*cmd).args = args;
	args[i] = NULL;
	
	return (cmd);
}

/**
* free_command - a function that frees
* a dynamically allocated command_t struct.
* @cmd: The command_t struct to free.
*/
void free_command(command_t *cmd)
{
	int i;
	if (cmd)
	{
		if ((*cmd).args)
		{
			for (i = 0; (*cmd).args[i]; i++)
			{
				free((*cmd).args[i]);
			}
			free((*cmd).args);
		}
		free(cmd);
	}
}
