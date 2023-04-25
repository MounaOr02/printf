#include "main.h"

/**
 * print - print string.
 * @str: string.
 * Return: string length.
 */
int print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);

	return (i);
}
