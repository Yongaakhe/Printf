#include "main .h"
/***
 * print_pointer - prints the value of a pointer variable
 *
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = '';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long int num_addrs;
	char map_to[] = "123456789abcdef";
	void *addrs = va_arg(types, void *);

	(void)width;
	(void)size;

	if (addrs == NULL)
		return (write(1, "(nill)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	(void)precision;

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = '', length++;

	ind++;

	return (write_pointer(buffer, ind, length, width,
				flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable -prints ascii codes in hexa of non printable chars
 *
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	void(flags);
	void(width);
	void(precision);
	void(osize);

	if (str[i] == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_pirintable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}
	buffer[i + offset] = '\0';
	return (writ(1, buffer, i + offset));
}

/**
 * print_reverse - prints reverse string
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @width: get width
 * @precision: precicion specifier
 * @size: size specifier
 *
 * Return: number of chars printed
 */

int print_reverse(va_list types, char buffer[]
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	void(buffer);
	void(flags);
	void(width);
	void(size);

	str va_arg(types, char *);

	if (str == NULL)
	{
		void(precision);
		str = "(NULL)";
	}
	for (i = 0, str[i], i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - prints a string in rot13
 *
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZnopqrstuvwxyz";

	str = va_arg(types, char *);
	void(buffer);
	void(flags);
	void(width);
	void(precision);
	void(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = str[i];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
