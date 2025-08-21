#include "shell.h"
#include "path_utils.h"

/**
 * _getenv - Get environment variable value
 * @name: Name of the environment variable
 * Return: Value of the environment variable or NULL
 */
char *_getenv(const char *name)
{
	int i;
	char **env = environ;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], name, strlen(name)) == 0 && env[i][strlen(name)] == '=')
			return (env[i] + strlen(name) + 1);
	}
	return (NULL);
}

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
		if (stat(cmd, &st) == 0 && (st.st_mode & S_IXUSR))
			return (strdup(cmd));
		return (NULL);
	}

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, cmd);
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

/**
 * is_builtin - checks if a command is a builtin
 * @cmd: The command to check
 * Return: 1 if builtin, 0 otherwise
 */
int is_builtin(char *cmd)
{
	if (strcmp(cmd, "exit") == 0 ||
		strcmp(cmd, "env") == 0 ||
		strcmp(cmd, "cd") == 0 ||
		strcmp(cmd, "help") == 0)
	{
		return 1;
	}
	return 0;
}
