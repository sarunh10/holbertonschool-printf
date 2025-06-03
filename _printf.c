#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function that handles %c, %s, and %%
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format) /* % at the end without specifier */
			{
				va_end(args);
				return (-1);
			}
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				int i = 0;

				if (!s)
					s = "(null)";
				while (s[i])
				{
					write(1, &s[i], 1);
					count++;
					i++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			/* if the specifier is not supported, do nothing */
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
