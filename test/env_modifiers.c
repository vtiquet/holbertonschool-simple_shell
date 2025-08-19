#include "shell.h"

extern char **environ;

/**
 * main - Demonstrates custom setenv and unsetenv.
 * Return: Always 0.
 */
int main(void)
{
	printf("--- Testing _setenv ---\n");
	_setenv("MY_VAR", "hello_world", 1);
	printf("MY_VAR = %s\n", _getenv("MY_VAR"));

	printf("\n--- Testing _unsetenv ---\n");
	_unsetenv("MY_VAR");
	if (!_getenv("MY_VAR"))
		printf("MY_VAR successfully unset.\n");

	return (0);
}

/**
 * _setenv - Changes or adds an environment variable.
 * @name: Name of the variable.
 * @value: Value to set.
 * @overwrite: 1 to overwrite, 0 to not.
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, new_size;
	char *new_var_str;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
			environ[i][strlen(name)] == '=')
		{
			if (overwrite)
			{
				free(environ[i]);
				new_var_str = malloc(strlen(name) + strlen(value) + 2);
				if (!new_var_str)
					return (-1);
				sprintf(new_var_str, "%s=%s", name, value);
				environ[i] = new_var_str;
				return (0);
			}
			return (0);
		}
	}
	for (i = 0; environ[i]; i++)
		;
	new_size = i + 2;
	environ = realloc(environ, sizeof(char *) * new_size);
	if (!environ)
		return (-1);
	new_var_str = malloc(strlen(name) + strlen(value) + 2);
	if (!new_var_str)
		return (-1);
	sprintf(new_var_str, "%s=%s", name, value);
	environ[i] = new_var_str;
	environ[i + 1] = NULL;
	return (0);
}

/**
 * _unsetenv - Deletes a variable from the environment.
 * @name: Name of the variable to delete.
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	int i = 0, j, found = 0;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
			environ[i][strlen(name)] == '=')
		{
			free(environ[i]);
			found = 1;
			break;
		}
	}
	if (found)
	{
		for (j = i; environ[j]; j++)
		{
			environ[j] = environ[j + 1];
		}
	}
	return (found ? 0 : -1);
}
