#include "main.h"
/**
 * _strlen - a function that returns the lenght of a string
 * @s: a pointer to string
 * Return: the lenght of the string
 */
int _strlen(char *s)
{
	int i = 0, len = 0;

	while (s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}
