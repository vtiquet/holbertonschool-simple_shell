#include "shell.h"

extern char **environ;

/**
 * print_env_global - Prints the environment using the global variable environ.
 */
void print_env_global(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * print_env_addresses - Prints the addresses of env and environ.
 * @env: The environment array passed to main.
 */
void print_env_addresses(char **env)
{
	printf("Address of env: %p\n", (void *)env);
	printf("Address of environ: %p\n", (void *)environ);
}

/**
 * _getenv - Gets an environment variable without using getenv().
 * @name: The name of the variable to find.
 * Return: The value, or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	if (!name || !environ)
		return (NULL);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}
