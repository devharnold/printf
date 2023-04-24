#include "main.h"

/*** PRINT POINTER ***/
/**
 * print_pointer - main entry point
 * @types: list of arguments
 * @buffer: buffer array
 * Return: Upon Success (0).
 */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	char map_to[] = "0123456789abcdef";
	unsigned long num_addrs;
	void *addrs = va_arg(types, void *);
	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if (flags & F_PLUS)
	{
		extra_c = '+', length++;
	}

	if ((flags & F_ZERO) && 
			!(flags & F_MINUS))
		{
		padd = '0';
		}
	else if (flags & F_SPACE)
	{
		extra_c = ' ', length++;
	}
	ind++;
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/*** PRINT A STRING IN ROT13 ***/
/**
 * print_rot13string - main entry point
 * @flags: flags init
 * @width: get width
 * @precision: precision
 * @size: size
 * @types: list of arguments
 * @buffer: buffer array
 * Return: chars that are printed 
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char x;
	char *str;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	unsigned int i, z;
	int count = 0;
	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(AHYY)";
	}
	for (i = 0; str[i]; i++)
	{
		for (z = 0; in[z]; z++)
		{
			if (in[z] == str[i])
			{
				x = out[z];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[z])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}


/*** PRINT NON PRINTABLE ***/
/**
 * print_non_printable - prints codes in hexxa
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: flags init
 * @width: width
 * @precision: precision
 * @size: get the size mehn 
 * Return: Upon Success (0)
 */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	Offset = 0; int i;
	char *str = va_arg(types, char *);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size)
	UNUSED(width);
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
	{
			buffer[off_t +i] = str[i];
	}
		else
	{
			off_t += append_hexa_code(str[i], buffer, i + offset);
	}
		i++;
	}
	buffer[i + off_t] = '\0';
	return (write(1, buffer, i + off_t));
}

/*** PRINT REVERSE ***/
/**
 * print_reverse - main entry point
 * @types: list of arguments
 * @width: width
 * @size: the specific size
 * @buffer: buffer array
 * @flags: flags init
 * Return: Upon Success (0)
 */

int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];
		write(1, &z, 1);
		count++;
	}
	return (count);
}

