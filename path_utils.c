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
 * get_path - Trouve le chemin complet d'une commande
 * @command: Commande à chercher (ex: "ls")
 * Return: Chemin complet (ex: "/bin/ls") ou NULL si non trouvé
 */
char *get_path(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
			return (strdup(command));
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
