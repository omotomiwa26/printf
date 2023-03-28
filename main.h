#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1


/**
 * struct fmt - defines a structure for symbols and function
 *
 * @fmt: The format
 * @fn: The function involved
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated
 */

typedef struct fmt fmt_t;


int _printf(const char *format, ...);
int handle_print_args(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);


/*************************************** FUNCTIONS ********************************************/

			/* Functions To Print Char And Strings */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

			/* Functions To Print Numbers */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);


				/* Function To Print Non Printable Characters */
int print_non_printable_cha(va_list types, char buffer[], int flags, int width, int precision, int size);

				/* Funcion To Print Memory Address */
int print_point(va_list types, char buffer[], int flags, int width, int precision, int size);

		/* Funciotns To Handle Other Specifiers */
int calc_precision(const char *format, int *i, va_list list);
int calc_width(const char *format, int *i, va_list list);
int calc_size(const char *format, int *i);
int calc_flags(const char *format, int *i);


			/* Function To Print String In Reverse */
int print_rev(va_list types, char buffer[], int flags, int width, int precision, int size);

			/* Function To Print A String In Rot13 */
int print_rot_13_string(va_list types, char buffer[], int flags, int width, int precision, int size);

					/* Write Handlers */
int write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_numb(int ind, char buffer[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_mem_addr(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

	/* Utils */
int is_printable(char c);
int append_hexa_code(char, char[], int);
int is_digit(char c);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


#endif
