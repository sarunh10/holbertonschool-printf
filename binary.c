#include "main.h"

/**
* print_binary - Converts and prints an unsigned int in binary format
* @n: The number to convert and print
*
* Return: Number of characters printed
*/
int print_binary(unsigned int n)
{
int count = 0, i;
int started = 0;
unsigned int mask;
if (n == 0)
{
_putchar('0');
return (1);
}
/* Start checking from the highest bit (most significant bit) */
for (i = 31; i >= 0; i--)
{
mask = 1 << i;
if (n & mask)
{
_putchar('1');
count++;
started = 1;
}
else if (started)
{
_putchar('0');
count++;
}
}
return (count);
}
