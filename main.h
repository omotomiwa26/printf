#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


/**
 * struct convert - defines a structure for symbols and function
 * @sym: The operator
 * @f: The function involved
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
}
typedef struct convert conver_t;


/* main functions */
int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _writechar(char c);
int print_char(va_list);
int print_string(va_list);


#endif
