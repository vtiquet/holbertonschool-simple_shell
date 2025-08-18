#include "shell.h"

static char *check_path_dirs(char *path_env, char *command);

/**
* _getenv - a function that gets an environment variable value.
* @name: the name of the environment variable.
* Return: the value of the variable, or NULL if not found.
*/
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	if (!name || !environ)
		return (NULL);

	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
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
	char *full_path;
	struct stat st;

	if (command == NULL)
		return (NULL);

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			return (strdup(command));
		}
		return (NULL);
	}

	if (!path_env)
		return (NULL);

	full_path = check_path_dirs(path_env, command);

	return (full_path);
}

/**
* check_path_dirs - a function that iterates
* through PATH directories to find a command.
* @path_env: the PATH environment variable string.
* @command: the command name.
* Return: the full path to the command, or NULL if not found.
*/
static char *check_path_dirs(char *path_env, char *command)
{
	char *path_copy = strdup(path_env);
	char *dir;
	char *full_path;
	struct stat st;

	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
