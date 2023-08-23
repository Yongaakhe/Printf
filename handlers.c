#include "main.h"

/**
 * handle_write_char -Prints a string
 *
 * @c: character types
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: number of char printed
 */

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = '';

	(void) precision;
	(void) size;

	if (flags  & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

		if (width > 1)
		{
			buffer[BUFF_SIZE - 1] = '\0';
			for (i = 0; i < width; i++)
				buffer[BUFF_SIZE - i - 2] = padd;

			if (flags & F_MINUS)
				return (write(1, &buffer[0], 1) +
						write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
			else
				return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
						write(1, &buffer[0], 1));
		}
		return (write(1, &buffer[0], 1));
}

/**
 * write_number - prints a string
 *
 * @is_negative : list of argurments
 * @ind: charater types
 * @width: get width
 * @size: size specifier
 * @buffer: buffer array to handle print
 * @precision: precision specifier
 * @flags: Calculates active flags
 *
 * Return: number of chars printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = (BUFF_SIZE - ind - 1);
	char padd = '', extra_ch = 0;

	(void)size;

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = '';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}

/**
 * write-num - write a number using a buffer
 *
 * @ind: index at which the number starts on the buffer
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @length: number length
 * @prec: precision
 * @padd: pading char
 * @extra_c: extra char
 *
 * Return: number of printed chars
 */

int write_num(int ind, char buffer[], int flags,
		int width, int prec, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec ==  0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = '';
	if (prec > 0 && prec < length)
		padd = '';
	while (prec > length)
		bufffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < (width - length + 1); i++)
			buffer[i] = paddd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == '')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == '')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], legth - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - writes unsigned number
 * @is_negative: number indicating if the num is negative
 * @ind: index at which the number starts in the buffer
 * @buffer: array of characters
 * @flags: flags specifiers
 * @precision: precision specifiers
 * @size: size specifiers
 * @width: width specifier
 *
 * Return: number of characters written
 */

int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd == '';

	(void) is_negative;
	(void) size;

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = '';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < (width - length); i++)
			buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length)p + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}


/**
 * write_pointer - write a memory address
 * @buffer: arrays of a character
 * @ind: index at which the number starts in the buffer
 * @padd: char representing the padding
 * @length: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @extra_c: char representing extra character
 * @padd_start: index at which padding should start
 *
 * Return: number of written chars
 */

int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width + 3; i++)
			buffer[i] = padd;
		buffer[i] '\0';
		if (flags & F_MINUS && padd == '')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (wriute(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == '')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1 - padd_start) - 2);
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
