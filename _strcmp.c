#include "shell.h"
/**
* _strcmp - a function that compares two strings
* @s1: the 1st string.
* @s2: the 2nd string.
* Return: "0" if s2 = s1, "-" if s2 > s1, "+" if s2 < s1.
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
