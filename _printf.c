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
 * print_int - prints an integer
 * @args: va_list containing the integer
 * buffer - stores each digit in number in reverse
 * Return: number of integers
 */

int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	char buffer[10];
	int i = 0;
	int count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;

	if (num == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
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
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				va_end(args);
				return (-1);
			}
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'd' || *format == 'i')
				count += print_int(args);
			else if (*format == 'b')
				count += print_binary(va_arg(args, unsigned int));

			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
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
