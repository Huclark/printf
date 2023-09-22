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

			/* switch between each case and call the appropriate handling functon*/
			switch (format[i])
			{
				case 'c':
					charcount += symb_link[0].fun(argument);
					break;

				case 's':
					charcount += symb_link[1].fun(argument);
					break;

				case '%':
					charcount += symb_link[2].fun(argument);
					break;
				default:
					charcount += _putchar('%');
					charcount += _putchar(format[i]);
					break;
			}
		}
		else
			charcount += _putchar(format[i]);
		i++;
	}
	return (charcount);
}
