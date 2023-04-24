#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: char
 * Return: 1 if c is printable, else (0)
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127){
		return (1);
	}

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: arrays of chars
 * @i: the index
 * @ascii_code: ASSCI CODE.
 * Return: Always 3 - otherwise else
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii_code < 0){
		ascii_code *= -1;
	}

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - main entry point - if char's a digit
 * @c: Char
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
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: indicator
 * Return: the other value of num
 */
long int convert_size_number(long int num, int size)
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
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: indicator
 * Return: the other value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG){
		return (num);
	}
	else if (size == S_SHORT){
		return ((unsigned short)num);
	}

	return ((unsigned int)num);
}

