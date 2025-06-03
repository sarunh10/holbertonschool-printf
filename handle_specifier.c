#include "main.h"

/**
 * handle_specifier - handles format specifiers
 * @specifier: character representing format
 * @args: argument list
 * Return: number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
	char *str;
	int count = 0;
	char c;

	switch (specifier)
	{
	case 'c':
		c = va_arg(args, int);
		write(1, &c, 1);
		count = 1;
		break;
	case 's':
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		while (*str)
		{
			write(1, str++, 1);
			count++;
		}
		break;
	case '%':
		write(1, "%", 1);
		count = 1;
		break;
	default:
		// If unknown specifier, print % and the char as is
		write(1, "%", 1);
		write(1, &specifier, 1);
		count = 2;
		break;
	}
	return (count);
}
