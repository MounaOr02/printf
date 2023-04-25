#include <unistd.h>
#include "main.h"
/**
 * _putchar - print a char to stdin
 * @c: int ascii value of char to be printed
 * Return: int number of byte printed
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
