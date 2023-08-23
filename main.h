#ifndef _MAIN_H
#define _MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * Flags
 */

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * Sizes
 */
#define S_LONG 2
#define S_SHORT 1


/**
 * struct format -structure opereator
 * 
 * @format: the format
 * @function: the function associate
 */
strct format
{
	char format;;
	int (*function)(va_list, char[],int, int, int,int);
};

/**
 * typedef stuct format fomart_t-Sruct op
 * @formart : the format
 * @format_t: function associated
 */

typedef strcuct format format_t;
int_printf(const char *format, ...);
int handle_print(const char *format, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);
int _putchar(char c);
int _printf(const char *format,...);
int _puts(char *c);

/**
 * Functions to print numbers
 */

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

/**
 * Functions to print characters and strings
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int preciosion, int size);
int print_hexa(va_list types, char buffer[], int flags, int width, int prcision, int size);


/**
 * Functions to print non printable characters
 */

int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);


/**
 * Functions to handle other specifiers
 */

int get_get flags(const char *format, int *);
int get_width(const char *format,int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/**
 * Function that prints memory address
 */

int print-pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/**
 * Functions that prints string in reverse
 */

int print_reverse(va_list types,char buffer[], int flags, int width, int precision, int size);


/**
 * Function that prints a string in rot 13
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int pecision, int size);

/**
 * Width handlers
 */

int handle _write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int int width, int precision, int size);
int write_num(int ind, char buffer[],int flags, int width, precision, int length, char paddd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width,int precision, int size);

/**
 * UTILS
 */

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int covert_size_number(long int num, int size);
long int covert_size_unsignd(unsigned long int num, int size)

#endif
