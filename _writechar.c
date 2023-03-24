#include "main.h"


/**
 * _writechar - writes the character c to stdout
 * @c: The character to print
 * Return: Success 1
 */
int _writechar(char c)
{
	return (write(1, &c, 1));
}
