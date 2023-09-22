#include "main.h"

/**
 * binary_type - Handles %b format specifier
 * @argument: The argument to be printed in binary
 * Return: The number of characters printed
 */
int binary_type(va_list argument)
{
	unsigned int num = va_arg(argument, unsigned int);
	int charcount = 0;

	if (num == 0)
	{
		charcount += _putchar('0');
	}
	else
	{
		charcount += convert_binary(num);
	}

	return (charcount);
}

/**
 * convert_binary - Convert and print number in binary format
 * @num: The number to be converted
 * Return: Number of printed characters
 */
int convert_binary(unsigned int num)
{
	int charcount = 0;
	int length = 0;
	char *binary_str;
	unsigned int temp = num;
	int i, j = 0;

	while (temp > 0)
	{
		temp /= 2;
		length++;
	}

	binary_str = malloc((length + 1) * sizeof(char));

	if (binary_str == NULL)
	{
		return (-1);
	}

	i = length - 1;
	while (i >= 0)
	{
		binary_str[i] = num % 2 + '0';
		num /= 2;
		i--;
	}

	binary_str[length] = '\0';

	while (binary_str[j] != '\0')
	{
		_putchar(binary_str[j]);
		charcount++;
		j++;
	}

	free(binary_str);

	return (charcount);
}
