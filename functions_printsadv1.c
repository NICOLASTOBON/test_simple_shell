#include "holberton.h"
/**
 * print_r - prints the reversed string
 * @formato: is a parameter
 * Return: length of string
 */
int print_r(va_list formato)
{
	char *ptr = va_arg(formato, char *);

	int len = _strlen(ptr);

	if (ptr == NULL)
	{
		ptr = "(null)";
		return (1);
	}
	if (*ptr == '\0')
		return (-1);

	print_rev(ptr);

	return (len);
}
/**
 *print_R - funtion that prints in rot 13
 *@formato: string to print
 * Return: lenght
 */
int print_R(va_list formato)
{
	return (rot13(va_arg(formato, char *)));
}
