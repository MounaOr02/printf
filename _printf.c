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
	int i = 0, printed = 0;

	if(!format)
		return (-1);
	va_start(parameter, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '%':
					_putchar('%');
					printed++;
					break;
				case 'c':
					cc = (char) va_arg(parameter, int);
					_putchar(cc);
					printed++;
					break;
				case 's':
					str = va_arg(parameter, char *);
					printed += _puts(str);
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					printed += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			printed++;
		}
		i++;
	}
	va_end(parameter);
	return (printed);
}
