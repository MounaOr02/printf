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
	char *str;
	char cc;
	int i = 0, size = 0;

	va_start(parameter, format);
	if (format[0] == '%')
	{
		if (format[1] == 'c')
		{
			cc = va_arg(parameter, int);
			write(1, &cc, 1);
			return (1);
		}
		if (format[1] == 's')
		{
			str = va_arg(parameter, char *);
			while(str[i])
			{
				i++;
				size++;
			}
			write(1, str, size);
			return (size);
		}
	}
}
