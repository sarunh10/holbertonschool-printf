#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @args: argument list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: argument list
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (!s)
		s = "(null)";

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}

	return (i);
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);

			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
