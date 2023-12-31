#include "main.h"
/**
 * get_flags - calculate active flags
 * @format: formatted string where arguments are to be printed
 * @i: take a parameter
 * Return: flags
 */
int get_flags(const char *format, int i)
{
	/* - + 0 # '' */
	/* 1 2 4 8 16 */

	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#','', '\0'};
	const char FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i =*i +1; format[curr_i] != '\0'; curr_++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if(format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_CH[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = curr_i - 1;

	return (flags);
}
