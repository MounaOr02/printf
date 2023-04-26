#include "main.h"
/**
 * print_hex_width - prints a number in hexadecimal format
 * @n: the number to print
 * @width: the minimum width to print
 * Return: number of characters printed
 */
int print_hex_width(unsigned int n, int width)
{
	unsigned int num = n;
	char hex[100];
	int i, count = 0;

	for (i = 0; num > 0; i++)
	{
		if (num % 16 < 10)
			hex[i] = (num % 16) + '0';
		else
			hex[i] = (num % 16) - 10 + 'A';

		num /= 16;
	}

	if (i < width)
	{
		while (width > i)
		{
			count += _putchar('0');
			width--;
		}
	}

	for (i--; i >= 0; i--)
		count += _putchar(hex[i]);

	return (count);
}

/**
 * print_non_printable - prints non-printable characters
 * @str: pointer to string
 * Return: number of characters printed
 */
int print_non_printable(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += print("\\x");
			count += print_hex_width(str[i], 2);
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}

/**
 * print_string_S - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are printed this way: \x,
 * followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_string_S(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	count += print_non_printable(str);

	return (count);
}
