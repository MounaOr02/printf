#include "main.h"
/**
 * print_hexadecimal_low - Print a number in hexadecimal format
 * @list: Number to print
 * Return: Length of the number
 **/
int print_hexadecimal_low(va_list list)
{
	char *ptr;
	int size;

	ptr = itoa(va_arg(list, unsigned int), 16);
	size = print((ptr != NULL) ? ptr : "NULL");
	return (size);
}
