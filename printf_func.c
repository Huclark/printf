#include "main.h"

/**
 * _printf - This function replicates the standard printf function.
 * @format: This represents the string input.
 * @...: This is the variadic function
 *	representing the number of arguments passed.
 * Return: The total number of printed characters (charcount)
 *	 Or -1 if string input is NULL.
 */

int _printf(const char *format, ...)
{
	/* Link format specifiers to their respective handling functions */

	link symb_link[] = {
		{"c", char_type},
		{"s", string_type},
		{"%", percent_type},
		{"d", int_type},
		{"i", int_type},
		{"b", binary_type},
	};

	int charcount;
	va_list argument;

	/* Return -1 to indicate an error for a NULL string */

	if (format == NULL)
		return (-1);

	va_start(argument, format);

	charcount = specifier_processor(format, symb_link, argument);

	va_end(argument);
	return (charcount);
}
