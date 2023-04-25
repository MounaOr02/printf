#include "main.h"
/**
 * _printf -  a function that produces output according to a format
 * @format: the output format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list parameter;
	char *str;
	int i, printed = 0;

	if (!format)
		return (-1);
	va_start(parameter, format);
	for (i = 0; !format[i]; i++)
	{
		if (format[i++] == '%')
		{
			switch (format[i])
			{
				case '%':
					_putchar('%');
					printed++;
					break;
				case 'c':
					_putchar((char) va_arg(parameter, int));
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
	}
	va_end(parameter);
	return (printed);
}
