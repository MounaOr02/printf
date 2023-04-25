#include "main.h"
#include <unistd.h>
/**
 * _puts - print string to stdin
 * @str: string
 * Return: int number of chars printed
 */
int _puts(char *str)
{
	int printed = _strlen(str);

	write(1, str, printed);
	return (printed);
}
