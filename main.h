#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/* printf.c*/
int _printf(const char *, ...);

/* handler.c */
int handler(const char *, va_list);
int percent_handler(const char *, va_list, int *);

/* utils */
int _strlen(const char *);       /* _strlen.c */
int print(char *);               /* print.c */
char *itoa(long int, int); /* _itoa_base.c */
int _putchar(char);              /* putchar.c */
int buffer(char);                /* putchar.c */

/* printers */
int print_string(va_list);
int print_char(va_list);
int print_integer(va_list);
int print_binary(va_list);
int print_unsigned(va_list);
int print_octal(va_list);
int print_hexadecimal_low(va_list);
int print_hexadecimal_upp(va_list);
int print_pointer(va_list);
int print_rev_string(va_list);
int print_rot(va_list);
int print_non_printable(char *str);
int print_string_S(va_list args);
int print_hex_width(unsigned int n, int width);
/**
 * struct _format - Typedef struct
 * @type: Format
 * @f: The function associated
 **/
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;

#endif
