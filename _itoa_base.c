#include "main.h"
/**
  * itoa - integer to ascii
  * @number: the number to convert
  * @base: the number's base
  *
  * Return: a pointer to char
  */
char *itoa(long int number, int base)
{
	static char *arr = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n;

	n = number;
	if (number < 0)
	{
		n = -number;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
