#include "holberton.h"
/**
 * _printf - function print string
 * @format: is a parameter
 * Return: Always success
 */
int _printf(const char *format, ...)
{
	int cont = 0;
	argum fm[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_p},
		{'d', print_d},
		{'i', print_d},
		{'u', print_u},
		{'r', print_r},
		{'b', print_b},
		{'R', print_R},
		{'o', print_o},
		{'x', print_hexLower},
		{'X', print_hexUpper},
		{'\0', NULL}
	};

	va_list formato;

	va_start(formato, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	cont += print_func(format, fm, formato);
	va_end(formato);
	return (cont);
}
