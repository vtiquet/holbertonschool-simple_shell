#include "shell.h"

/**
* _getenv - a function that gets an environment variable value.
* @name: the name of the environment variable.
* Return: the value of the variable, or NULL if not found.
*/
char *_getenv(const char *name)
{
	int i = 0;
	char *env_var;
	size_t name_len = _strlen(name);

	while (environ[i])
	{
		env_var = environ[i];

		if (_strncmp(env_var, (char *)name, name_len)
			== 0 && env_var[name_len] == '=')
		{
			return (&env_var[name_len + 1]);
		}
		i++;
	}
	return (NULL);
}

/**
* find_command_in_path - a function that finds a command in the PATH.
* @command: the command name.
* Return: the full path to the command, or NULL if not found.
*/
char *find_command_in_path(char *command)
{
	char *path_env = _getenv("PATH");
	char *path_copy, *dir, *full_path;
	struct stat st;

	if (path_env == NULL || command == NULL)
	{
		return (NULL);
	}

	path_copy = _strdup(path_env);
	if (path_copy == NULL)
	{
		return (NULL);
	}

	dir = _strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = _strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
