#include "shell.h"

/**
 * shell_env - Prints environment
 * @args: Unused
 * Return: Always 1
 */
int shell_env(char **args)
{
	int i;
	(void)args;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (1);
}

/**
 * shell_cd - Change directory
 * @args: Array of arguments (args[1] = target dir)
 * Return: 1 on success, -1 on failure
 */
int shell_cd(char **args)
{
	char cwd[1024];

	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
		return (1);
	}

	if (chdir(args[1]) != 0)
	{
		perror("hsh");
		return (1);
	}

	if (getcwd(cwd, sizeof(cwd)))
		setenv("PWD", cwd, 1);

	return (1);
}

/**
 * shell_help - Display help
 * @args: Arguments (unused)
 * Return: Always 1
 */
int shell_help(char **args)
{
	(void)args;
	printf("Simple Shell Help\n");
	printf("Built-in commands:\n");
	printf("  cd          Change directory\n");
	printf("  exit        Exit the shell\n");
	printf("  help        Display this help\n");
	printf("  env         Print environment\n");
	return (1);
}

/**
 * shell_exit - Exit the shell
 * @args: Arguments
 * Return: 0 to terminate shell, or 1 to stay in shell
 */
int shell_exit(char **args)
{
	if (args[1] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (1);
	}
	exit(0);
}

/**
 * shell_execute_builtin - Executes builtin
 * @args: Arguments
 * Return: Status or -1 if not builtin
 */
int shell_execute_builtin(char **args)
{
	builtin_t builtins[] = {
		{"env", shell_env},
		{"cd", shell_cd},
		{"help", shell_help},
		{"exit", shell_exit},
		{NULL, NULL}
	};
	int i;

	for (i = 0; builtins[i].name; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
			return (builtins[i].func(args));
	}
	return (-1);
}
