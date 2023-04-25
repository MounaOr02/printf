#include "main.h"
/**
 * _strlen - Calculate the length of a string
 * @str: a pointer to the string
 * Return: the lenght
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len])
	{
		len++;
	}
	return (len);
}
