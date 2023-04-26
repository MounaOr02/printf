int percent_handler(const char *str, va_list list, int *i)
{
	int size, j, number_formats, flags = 0;
	format formats[] = {
			{'s', print_string}, {'c', print_char},
			{'d', print_integer}, {'i', print_integer},
			{'b', print_binary}, {'u', print_unsigned},
			{'o', print_octal}, {'x', print_hexadecimal_low},
			{'X', print_hexadecimal_upp}, {'p', print_pointer},
			{'r', print_rev_string}, {'R', print_rot}
	};
	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	// Handle flags
	while (str[*i] == '+' || str[*i] == ' ' || str[*i] == '#')
	{
		if (str[*i] == '+')
			flags |= FLAG_PLUS;
		else if (str[*i] == ' ')
			flags |= FLAG_SPACE;
		else if (str[*i] == '#')
			flags |= FLAG_HASH;

		*i += 1;
	}

	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(list, flags);
			return (size);
		}
	}
	_putchar('%');
	if (flags != 0)
	{
		if (flags & FLAG_PLUS)
			_putchar('+');
		else if (flags & FLAG_SPACE)
			_putchar(' ');
		if (flags & FLAG_HASH)
			_putchar('#');
	}
	_putchar(str[*i]);
	return (flags == 0 ? 1 : 2);
}

