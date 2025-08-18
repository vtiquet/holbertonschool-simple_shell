#include "shell.h"

/**
* count_tokens - a function that counts the number of tokens in a string.
* @str: the string to tokenize.
* @delim: the delimiter string.
* Return: the number of tokens.
*/
static int count_tokens(char *str, const char *delim)
{
	int count = 0;
	char *str_copy;
	char *token;

	if (str == NULL || *str == '\0')
		return (0);

	str_copy = strdup(str);
	if (!str_copy)
		return (0);

	token = strtok(str_copy, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(str_copy);
	return (count);
}

/**
* parse_command - a function tha splits a string into a command_t struct.
* @line: the string to parse.
* Return: a pointer to the command_t struct, or NULL on failure.
*/
command_t *parse_command(char *line)
{
	command_t *cmd;
	char *token;
	int num_tokens, i = 0;

	if (line == NULL || *line == '\0')
		return (NULL);

	num_tokens = count_tokens(line, " \t");
	if (num_tokens == 0)
		return (NULL);

	cmd = malloc(sizeof(command_t));
	if (!cmd)
		return (NULL);

	(*cmd).args = malloc(sizeof(char *) * (num_tokens + 1));
	if (!(*cmd).args)
	{
		free(cmd);
		return (NULL);
	}

	token = strtok(line, " \t");
	(*cmd).cmd = token;

	while (token)
	{
		(*cmd).args[i] = token;
		token = strtok(NULL, " \t");
		i++;
	}
	(*cmd).args[i] = NULL;
	return (cmd);
}

/**
* free_command - a function that frees
* a dynamically allocated command_t struct.
* @cmd: The command_t struct to free.
*/
void free_command(command_t *cmd)
{
	if (cmd != NULL)
	{
		if ((*cmd).args != NULL)
		{
			free((*cmd).args);
		}
		free(cmd);
	}
}
