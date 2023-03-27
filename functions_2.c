#include "main.h"

/************************* PRINT REVERSE *************************/
/**
 * print_rev - function prints string in reverse.
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int x, cnt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

x -= 1;
while (x >= 0)
{
x--;
		char a = str[x];

		write(1, &a, 1);
		cnt++;
	}
	return (cnt);
}


/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot_13_string - function prints a string in rot13.
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rot_13_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int a, b;
	int cnt = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(EUREKA)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; input[b]; b++)
		{
			if (input[b] == str[a])
			{
				x = output[b];
				write(1, &x, 1);
				cnt++;
				break;
			}
		}
		if (!input[b])
		{
			x = str[a];
			write(1, &x, 1);
			cnt++;
		}
	}
	return (cnt);
}