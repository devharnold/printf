#include "main.h"

/**
 * handle_print - main entry point
 * @list: list of arguments 
 * @ind: index
 * @buffer: buffer array
 * @flags: flags init
 * @fmt: string formatted
 * Return: Upon Success (0)
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int a, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'a', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (a = 0; fmt_types[a].fmt != '\0'; a++)
		if (fmt[*ind] == fmt_types[a].fmt)
		{
			return (fmt_types[a].fn(list, buffer, flags, width, precision, size));
		}
	if (fmt_types[a].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
	{
			return (-1);
	}
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
		{
			unknow_len += 
				write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

