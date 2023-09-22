#ifndef MAIN_H
#define MAIN_H

/* Standard library headers used */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * struct _link - Links the format specifiers to their respective functions
 * @specifier: The format specifier.
 * @fun: The format specifier's function.
 */
struct _link
{
	int (*fun)(va_list);
	char *specifier;
};
typedef struct _link link;

/* Prototype for custom _printf function */

int _printf(const char *format, ...);

/* Prototype for other supporting functions for _printf function */

int _putchar(char c);

#endif