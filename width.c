#include "main.h"
/**
 * get_width - calculates width for printing
 * @format: formatted string in which to print the argument
 * @i: list of arguments to be printed
 * @list: list of arguments
 *
 * Return: number of characters printed
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width;

	for (curr_i = *i + 1; formart[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_1;

	return (width);
}
