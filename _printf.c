#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: Character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Custom implementation of printf
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;

            if (!format[i]) // إذا كانت نهاية السلسلة بعد %
            {
                va_end(args);
                return -1;
            }

            switch (format[i])
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    int j = 0;
                    if (!str)
                        str = "(null)";
                    while (str[j])
                        count += _putchar(str[j++]);
                    break;
                }
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    count += _putchar('%');
                    count += _putchar(format[i]);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }

        i++;
    }

    va_end(args);
    return count;
}
