#include "main.h"
/**
 * _printf - prints to stdoutpt formatted text
 * @format: formart specifier
 * Return: no of bytes to be printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, str_count, count = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; i != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			i++;

		}
		else if (format[i + 1] == 's')
		{
			str_count = _puts(va_arg(args, char *));
			i++;
			count += (str_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
		}
		count += 1;
	}
	va_end(args);
	return (count);
}
