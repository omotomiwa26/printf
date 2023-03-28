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
	char a;

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
		 a = str[x];

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

/****************** PRINT POINTER ******************/
/**
 * print_point - Function prints the value of a pointer variable
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_point(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ext_c = 0, pad = ' ';

	/* len=2, for '0x' */
	int index = BUFF_SIZE - 2, len = 2, pad_start = 1;
	unsigned long num_ad;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_ad = (unsigned long)addrs;

	while (num_ad > 0)
	{
		buffer[index--] = map_to[num_ad % 16];
		num_ad /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		ext_c = '+', len++;
	else if (flags & F_SPACE)
		ext_c = ' ', len++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, index, len,
		width, flags, pad, ext_c, pad_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable_cha - Function prints ascii codes in hexa of non printable chars
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_non_printable_cha(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[y] != '\0')
	{
		if (is_printable(str[y]))
			buffer[y + offset] = str[y];
		else
			offset += append_hexa_code(str[y], buffer, y + offset);

		y++;
	}

	buffer[y + offset] = '\0';

	return (write(1, buffer, y + offset));
}
