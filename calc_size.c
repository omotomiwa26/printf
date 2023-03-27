#include "main.h"

/**
 * calc_size - function calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int calc_size(const char *format, int *i)
{
	int cur_z = *i + 1;
	int size = 0;

	if (format[cur_z] == 'l')
		size = S_LONG;
	else if (format[cur_z] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur_z - 1;
	else
		*i = cur_z;

	return (size);
}
