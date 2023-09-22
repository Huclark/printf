#include "main.h"

/**
 * char_type - Handles %c format specifier
 * @argument: Character argument to print
 * Return: 1 as the number of printed characters
 */

int char_type(va_list argument)
{
	/* Get the character argument to print */

	char char_to_print = va_arg(argument, int);

	_putchar(char_to_print);
	return (1);
}

/**
 * percent_type - Handles % format input
 * @argument: Character argument to print
 * Return: 1 as the number of printed characters
 */

int percent_type(va_list argument __attribute__((unused)))
{
	_putchar('%');
	return (1);
}

/**
 * string_type - Handles %s format specifier
 * @argument: Character argument to print
 * Return: The total number of characters printed (charcount)
 */

int string_type(va_list argument)
{
	/* Retrieve string argument and print using a loop */

	char *string = va_arg(argument, char *);
	int charcount = 0;

	if (string == NULL)
	{
		while ("(null)"[charcount] != '\0')
		{
			_putchar("(null)"[charcount]);
			charcount++;
		}
		return (charcount);
	}

	charcount = 0;

	while (string[charcount] != '\0')
	{
		_putchar(string[charcount]);
		charcount++;
	}
	return (charcount);
}

/**
 * int_type - Handles %d and %i format specifiers
 * @argument: Character argument to print
 * Return: The total number of characters printed (charcount)
 */

int int_type(va_list argument)
{
	/* Retrieve the integer argument */
	int num = va_arg(argument, int);
	/* Convert the integer to a string representation */
	/* Assuming a maximum of 11 digits for a 32-bit int */
	char buffer[12];
	int charcount = sprintf(buffer, "%d", num);
	int i = 0;

	while (buffer[i] != '\0')
	{
		_putchar(buffer[i]);
		i++;
	}
	return (charcount);
}

/**
 * binary_type - Handles %b format specifier (unsigned int to binary)
 * @argument: Argument to print (unsigned int)
 * Return: The total number of characters printed (charcount)
 */

int binary_type(va_list argument)
{
	unsigned int num = va_arg(argument, unsigned int);
	int charcount = 0;
	int width = 0;
	int i;
	char binary[32];  /* Assuming a 32-bit integer */

	if (num == 0)
	{
		binary[0] = '0';
		width = 1;
	}
	else
	{
		int temp = num;

		while (temp > 0)
		{
			temp >>= 1;
			width++;
		}

		for (i = 0; i < width; i++)
		{
			binary[i] = ((num >> (width - 1 - i)) & 1) + '0';
		}
	}

	binary[width] = '\0';

	while (binary[charcount] != '\0')
	{
		_putchar(binary[charcount]);
		charcount++;
	}

	return (charcount);
}
