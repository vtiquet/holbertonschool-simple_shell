#include "shell.h"
/**
 * main - Prints command line arguments and then reads a line.
 * @ac: The argument count.
 * @av: The argument vector.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int i = 0;

	(void)ac;
	printf("--- Arguments ---\n");
	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}

	printf("\n--- Read Line ---\n");
	printf("$ ");
	read_bytes = getline(&line, &len, stdin);
	if (read_bytes != -1)
	{
		printf("%s", line);
	}
	free(line);
	return (0);
}
