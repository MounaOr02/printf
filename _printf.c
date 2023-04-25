#include "main.h"
/**
 * _printf -  a function that produces output according to a format
 * @format: the output format
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list parameter;
	char *str, cc;
	int printed = 0;

	if (format == NULL)
		return (-1);
	va_start(parameter, format);
	
	if (format[0] == '%')
	{
		if (format[1] == 'c')
		{
			cc = (char) va_arg(parameter, int);
			_putchar(cc);
			printed++;
		}
		if (format[1] == 's')
		{
			str = va_arg(parameter, char *);
			printed += _puts(str);
		}
	}
	va_end(parameter);
	return (printed);
}
