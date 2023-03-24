#include "main.h"


/**
 * parser - receives the main string & all necessary parameters to pr
 * int a formatted string
 * @format: a character string
 * @f_list: a list of all functions
 * @arg_list: a list containing all arguments passed to the program
 * Return: The total numbers of all characters printed
 */
int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	/* iterates through the main string */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') /* checks for format specifiers*/
			/* iterates through struct to find the right function */
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_writechar(format[i]);
					_writechar(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /* updating i to skip format symbols */
		}
		else
		{
			_writechar(format[i]); /* call the write function */
			printed_chars++;
		}
	}
	return (printed_chars);
}
