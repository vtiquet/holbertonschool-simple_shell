#include "shell.h"

static char *str_token;

/**
* _strtok - a function that tokenizes a string based on a delimiter.
* @str: the string to tokenize.
* @delim: the delimiter characters.
* Return: the next token, or NULL if there are no more tokens.
*/
char *_strtok(char *str, const char *delim)
{
	char *token_start;
	const char *d;

	if (str != NULL)
		str_token = str;

	if (str_token == NULL || *str_token == '\0')
		return (NULL);

	while (*str_token != '\0')
	{
		d = delim;
		while (*d != '\0' && *str_token != *d)
			d++;
		if (*d == '\0')
			break;
		str_token++;
	}

	if (*str_token == '\0')
		return (NULL);

	token_start = str_token;
	while (*str_token != '\0')
	{
		d = delim;
		while (*d != '\0' && *str_token != *d)
			d++;
		if (*d != '\0')
		{
			*str_token = '\0';
			str_token++;
			return (token_start);
		}
		str_token++;
	}
	return (token_start);
}
