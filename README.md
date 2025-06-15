# C - printf

This project is part of the C programming curriculum at Holberton School.  
The goal is to recreate a simplified version of the C standard library `printf` function.

## Project Goal

The main goal of this project is to understand how formatted output works internally in C by building a custom `_printf` function.  
This helps in learning about variadic functions, parsing format strings, and low-level output formatting without relying on the standard library.

## Project Description

We implemented a custom `_printf` function that mimics the behavior of the standard `printf`.  
It processes format strings and prints the output to the standard output (stdout).

Supported format specifiers:
- `%c` : print a single character  
- `%s` : print a string  
- `%%` : print a percent sign  
- `%d`, `%i` : print signed decimal integers

## Requirements

Before running or compiling the project, make sure the following are installed and set up on your system:

- **Operating System:** Ubuntu 20.04 LTS (or any Linux-based OS)  
- **Compiler:** GCC (GNU Compiler Collection) with support for C89 standard  
- **Compilation Flags:** Use `-Wall -Werror -Wextra -pedantic -std=gnu89` to ensure code quality and compatibility  
- **Coding Style:** The code must follow the Betty style guidelines (for readability and consistency)  
- **Dependencies:** No external libraries are required; the project only uses standard C libraries (`stdarg.h`, `unistd.h`)  
- **Environment:** A terminal or shell environment to compile and run the program   

## Compilation

To compile the project, run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

Examples
Here are some example usages of the _printf function:
_printf("Character: %c\n", 'A');
_printf("String: %s\n", "Hello, Holberton!");
_printf("Percent sign: %%\n");
_printf("Decimal number: %d\n", 123);
_printf("Integer number: %i\n", -456);

## Installation

Clone the repository:

```bash
git clone https://github.com/sarunh10/holbertonschool-printf.git
cd holbertonschool-printf

## Examples

Here are some example usages of the `_printf` function and what they print:

```c
_printf("Hello, world!\n");
// Output: Hello, world!

_printf("Character: %c\n", 'A');
// Output: Character: A

_printf("String: %s\n", "Holberton");
// Output: String: Holberton

_printf("Percent: %%\n");
// Output: Percent: %

_printf("Number: %d\n", 123);
// Output: Number: 123

_printf("Negative number: %i\n", -45);
// Output: Negative number: -45

## Testing
To test the _printf function, you can use the provided main.c test file or write your own tests. The test file checks multiple format specifiers and compares output length with the standard printf.

Example test snippet from main.c:
#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Percent:[%%]\n");
    printf("Percent:[%%]\n");
    return (0);


Authors 
=======

Sultan Alsanie
Email: 10940@holbertonstudents.com

Sara Mareer
Email: 10942@holbertonstudents.com

Mohamed Alayda
Email: 10945@holbertonstudents.comi
