#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @char_to_print: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char char_to_print)
{
	return (write(1, &char_to_print, 1));
}
