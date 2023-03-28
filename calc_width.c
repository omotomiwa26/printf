#include "main.h"

/**
 * calc_width - function calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int calc_width(const char *format, int *i, va_list list)
{
	int cur_z;
	int width = 0;

	for (cur_z = *i + 1; format[cur_z] != '\0'; cur_z++)
	{
		if (is_digit(format[cur_z]))
		{
			width *= 10;
			width += format[cur_z] - '0';
		}
		else if (format[cur_z] == '*')
		{
			cur_z++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_z - 1;

	return (width);
}
