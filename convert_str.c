#include "main.h"
/**
 * convert_s - converts an argument to a string and 
 * 		stores it to the buffer contained in a strut
 * @args: a va_list pointing to  the argument to be converted
 * @flags: flag modifiers
 * @len: length modifiers
 * @wid: width modifiers
 * @prec: precision modifiers
 * @output: buffer_t struct containing a character array
 *
 * Return: the number of bytes stored in the buffer
 */
unsigned int convert_s(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size;
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	str + va_arg(arg, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6);

	for (size = 0; *(str + size);)
		size++;

	ret
