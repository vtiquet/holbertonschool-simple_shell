#include "shell.h"

/**
* _strncmp - a function that compares up to n characters of two strings.
* @s1: the first string.
* @s2: the second string.
* @n: the maximum number of characters to compare.
* Return: an integer less than, equal to, or greater than zero if the first n
* characters of s1 are found, respectively, to be less than, to match, or be
* greater than the first n characters of s2.
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		if (*s1 == '\0')
		{
			break;
		}
		s1++;
		s2++;
	}
	return (0);
}
