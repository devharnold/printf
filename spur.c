#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    count += printf("%c", va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    count += printf("%%");
                    break;
            }
        } else {
            count += printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    return count;
}

