#include "main.h"
#include <stdio.h>
int main(void)
{
    int len1, len2;
    len1 = _printf("Hello %% Holberton! Char: %c, String: %s\n", 'H', "School");
    len2 = printf("Hello %% Holberton! Char: %c, String: %s\n", 'H', "School");
    _printf("Len1 = [%d], Len2 = [%d]\n", len1, len2);
    return (0);
}
