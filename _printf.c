#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - receives the main string and all parameters to print a f
 * ormatted string
 * @format: character of strings
 * Return: total count of the character printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = calc_flags(format, &i);
			width = calc_width(format, &i, list);
			precision = calc_precision(format, &i, list);
			size = calc_size(format, &i);
			i++;
<<<<<<< HEAD
			printed = handle_print_args(format, &i, list, buffer, flags, width, precision, size);
=======
			printed = handle_print(format, &i, list, buffer, flags,
width, precision, size);
>>>>>>> 0d7caf9fc4e0035dfbf1445eb51823706801a375
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}


/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 * Return: void
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}
