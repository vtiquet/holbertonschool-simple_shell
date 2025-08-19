/* exec_and_wait.c */
#include "shell.h"

/**
* main - Creates 5 child processes to run a command.
* Return: Always 0.
*/
int main(void)
{
	int i;
	pid_t child_pid;
	int status;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 1; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: fork failed");
			exit(1);
		}
		if (child_pid == 0) /* Child process */
		{
			execve(argv[0], argv, NULL);
			perror("Error: execve failed");
			exit(1);
		}
		else /* Parent process */
		{
			wait(&status);
		}
	}
	return (0);
}
