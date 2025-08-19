#include "shell.h"
/**
* _strcpy - function that copies the string to the buffer.
* @dest: the buffer.
* @src: the string.
* Return: the pointer to dest.
*/
char *_strcpy(char *dest, char *src)
{
	int  i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
