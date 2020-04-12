#include "holberton.h"
/**
 * print_c - function print caracter
 * @formato: is a parameter to print
 * Return: length of string
 */
int print_c(va_list formato)
{
	char c;

	c = (char)va_arg(formato, int);
	_putchar(c);
	return (1);
}
/**
 * print_s - function print string
 * @formato: is a parameter to print
 * Return: length of string
 */
int print_s(va_list formato)
{
	char *ptr = va_arg(formato, char *);
	int j;

	if (ptr == NULL)
		ptr = "(null)";

	for (j = 0; ptr[j]; j++)
		_putchar(ptr[j]);

	return (j);
}
/**
 * print_p - function porcent
 * Return: 1
 */
int print_p(void)
{
	_putchar('%');
	return (1);
}
