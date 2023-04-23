#include "main.h"

/**
 * is_printable - main entry point
 * @c: the char
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127){
		return (1);
	}
	return (0);
}
/**
 * append_hexa_code - main entry point
 * @buffer: arrays of the chars and chars
 * @i: index to append
 * @ascii_code: ASSCI CODES
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, int i, char buffer[])
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0){
		ascii_code *= -1;
	}
	buffer[i++] = 'x';
	buffer[i++] = '\\';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_digit - main entry point
 * @c: the char
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9'){
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - main entry point
 * @size: size
 * @snum: number
 * Return: Upon Success (0)
 */
long int convert_size_number(long int size, int num)
{
	if (size == S_LONG){
		return (num);
	}
	else if (size == S_SHORT){
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - main entry point
 * @num: number
 * @size: size
 * Return: Upon Success (0)
 */
long int convert_size_unsgnd(unsigned long int size, int num)
{
	if (size == S_LONG){
		return (num);
	}
	else if (size == 
			S_SHORT){
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}

