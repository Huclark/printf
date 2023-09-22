#include "main.h"

/**
 * specifier_processor - Takes the format string as an input and processes it
 * @format: Format string input
 * @symb_link: A struct array containing the format specifiers
 *		and their respective functions.
 * @argument: Character argument to print
 * Return: The number of characters printed
 */

int specifier_processor(const char *format, link symb_link[], va_list argument)
{
	int charcount = 0, i = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;

			/* Handle the case of a lone '%' character */

			if (format[i] == '\0')
			{
				charcount += _putchar('%');
				break;
			}
			if (format[i] == 'b')
				charcount += binary_type(argument);
			else
				charcount += process_format_specifier(format[i], symb_link, argument);
		}
		else
			charcount += _putchar(format[i]);
		i++;
	}
	return (charcount);
}

int process_format_specifier(char specifier, link symb_link[],
		va_list argument)
{
	int index = 0;

	while (symb_link[index].specifier != NULL)
	{
		if (specifier == *symb_link[index].specifier)
			return (symb_link[index].fun(argument));
		index++;
	}
	return (_putchar('%') + _putchar(specifier));
}
