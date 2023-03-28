#include "main.h"


/**
 * calc_flags - function calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter
 * Return: flags
 */
int calc_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cur_z;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_z = *i + 1; format[cur_z] != '\0'; cur_z++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cur_z] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = cur_z - 1;

	return (flags);
}
