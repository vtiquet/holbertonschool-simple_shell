#include "shell.h"
/**
* _strncpy - function that copies the string to the buffer for n bytes.
* @dest: the buffer.
* @src: the string.
* @n: the number of bytes to copy.
* Return: the pointer to dest.
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
