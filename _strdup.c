#include "shell.h"
/**
* _strdup - a function that returns a pointer
* to a newly allocated space in memory
* @str: the string given.
* Return: a pointer, or NULL if it fails.
*/
char *_strdup(const char *str)
{
	char *a;
	unsigned int i;

	if (str == NULL)
	{
		return (NULL);
	}
	a = malloc(_strlen(str) * sizeof(char) + 1);
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		a[i] = str[i];
	}
	return (a);
}
