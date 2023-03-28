#include "main.h"

/**
 * calc_precision - function Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int calc_precision(const char *format, int *i, va_list list)

{
	int cur_z = *i + 1;
	int prec = -1;

	if (format[cur_z] != '.')
		return (prec);

	prec = 0;

	for (cur_z += 1; format[cur_z] != '\0'; cur_z++)
	{
		if (is_digit(format[cur_z]))
		{
			prec *= 10;
			prec += format[cur_z] - '0';
		}
		else if (format[cur_z] == '*')
		{
			cur_z++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_z - 1;

	return (prec);
}
