#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* print_char - prints a character
* @args: va_list containing the character
* Return: number of characters printed
*/

int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
* print_string - prints a string
* @args: va_list containing the string
* Return: number of characters printed
*/

int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (s == NULL)
		s = "(null)";
		while (s[i])
			write(1, &s[i++], 1);
			return (i);
}

/**
* _printf - simplified printf function
* @format: format string
* Return: number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
		if (*format == '%')
			format++;
			if (!*format)
				va_end(args);
				return (-1);
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == '%')
				count += write(1, "%", 1);
			else
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
		else
			write(1, format, 1);
			count++;
		format++;
	va_end(args);
	return (count);
}
