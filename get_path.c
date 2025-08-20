#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * get_path_linux - Retrieves the PATH environment variable.
 *
 * Return: PATH value, or NULL if not found.
 */

char *get_path_linux(void)
{
	FILE *fp = fopen("/proc/self/environ", "r");

	if (!fp)
	{
		perror("Erreur d'ouverture /proc/self/environ");
		return (NULL);
	}

	char buffer[4096];
	size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, fp);

	buffer[bytes_read] = '\0';


	fclose(fp);

	char *current = buffer;

	while (current < buffer + bytes_read)
	{
		if (strncmp(current, "PATH=", 5) == 0)
		{
			return (strdup(current + 5));
		}
		current += strlen(current) + 1;
	}

	return (NULL);
}
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("Récupération du PATH...\n");

	char *path = get_path_linux();

	if (path != NULL)
	{
		printf("PATH trouvé : %s\n", path);
		free(path);
	}
	else
	{
		printf("PATH non trouvé\n");
	}
	return (0);
}
