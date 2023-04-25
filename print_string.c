#include "main.h"
/**
 * print_string - print string (s)
 * @list: va_list
 * Return: number of printed characters
 */
int print_string(va_list list)
{
	char *str;
	int len;

	str = va_arg(list, char*);
	len = print((str != NULL) ? str : "(null)");

	return (len);
}

