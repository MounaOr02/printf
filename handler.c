#include "main.h"
/**
 * handler - a function that handle and control format
 * @str: a pointer to the format string
 * @list: list of arguments
 * Return: the number of printed arguments
 */
int handler(const char *str, va_list list)
{
	int i, a, size = 0;

	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			a = percent_handler(str, list, &i);
			if (a == -1)
				return (-1);

			size += a;
			continue;
		}

		_putchar(str[i]);
		size++;
	}

	return (size);
}

/**
 * percent_handler - Controller for percent format
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 *
 * Return: Size of the numbers of elements printed
 **/
int percent_handler(const char *str, va_list list, int *i)
{
	int size, j, number_formats;
	format formats[] = {
			{'s', print_string}, {'c', print_char},
			{'d', print_integer}, {'i', print_integer},
			{'b', print_binary}, {'u', print_unsigned},
			{'o', print_octal}, {'x', print_hexadecimal_low},
			{'X', print_hexadecimal_upp}, {'p', print_pointer},
			{'r', print_rev_string}, {'R', print_rot},
			{'S', print_string_S}
	};
	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}
	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(list);
			return (size);
		}
	}
	_putchar('%'), _putchar(str[*i]);
	return (2);
}
