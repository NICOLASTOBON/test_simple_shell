#include "holberton.h"

/**
 * print_u - unsigned number
 * @formato: is a parameter
 * Return: length of string
 */
int print_u(va_list formato)
{
	unsigned int a[10];
	unsigned int i, value, num, sum, j;

	num = va_arg(formato, int);
	j = 0;
	value = 1000000000;
	a[0] = num / value;
	for (i = 1; i < 10; i++)
	{
		value /= 10;
		a[i] = (num / value) % 10;
	}
	for (i = 0, sum = 0; i < 10; i++)
	{
		sum += a[i];
		if (sum != 0 || i == 9)
		{
			_putchar(a[i] + 48);
			j++;
		}
	}
	return (j);
}
/**
 * print_b - prints a binary
 * @formato: decimal number to print in binary
 * Return: number of digits printed
 */
int print_b(va_list formato)
{
	unsigned int a[32];
	unsigned int i, value, num, sum = 0;
	int j = 0;


	num = va_arg(formato, unsigned int);
	value = 2147483648;
	a[0] = num / value;

	for (i = 1; i < 32; i++)
	{
		value /= 2;
		a[i] = (num / value) % 2;
	}
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			_putchar(a[i] + 48);
			j++;
		}
	}
	return (j);
}
/**
 * print_o - prints a octal
 * @formato: is a parameter binary
 * Return: number of digits printed
 */
int print_o(va_list formato)
{
	unsigned int a[11];
	unsigned int i, value, num, sum = 0;
	int j = 0;


	num = va_arg(formato, unsigned int);
	value = 1073741824;
	a[0] = num / value;

	for (i = 1; i < 11; i++)
	{
		value /= 8;
		a[i] = (num / value) % 8;
	}
	for (i = 0; i < 11; i++)
	{
		sum += a[i];
		if (sum || i == 10)
		{
			_putchar(a[i] + '0');
			j++;
		}
	}
	return (j);
}
/**
 * print_hexLower - prints a hexacedimal in lowercase
 * @formato: is a parameter
 * Return: number of digits printed
 */
int print_hexLower(va_list formato)
{
	unsigned int num, value, i, sum;
	unsigned int a[8];
	int j = 0;

	num = va_arg(formato, unsigned int);
	value = 268435456;
	for (i = 0; i < 8; i++)
	{
		a[i] = (num / value) % 16;
		value /= 16;
	}
	for (i = 0, sum = 0, j = 0; i < 8; i++)
	{
		sum += a[i];
		if (sum || i == 7)
		{
			if (a[i] < 10)
				j += _putchar(a[i] + '0');
			else
				j += _putchar(39 + a[i] + '0');
		}
	}
	return (j);
}
/**
 * print_hexUpper - prints a hexacedimal in uppercase
 * @formato: is a parameter
 * Return: number of digits printed
 */
int print_hexUpper(va_list formato)
{
	unsigned int num, value, i, sum;
	unsigned int a[8];
	int j = 0;

	num = va_arg(formato, unsigned int);
	value = 268435456;
	for (i = 0; i < 8; i++)
	{
		a[i] = (num / value) % 16;
		value /= 16;
	}
	for (i = 0, sum = 0, j = 0; i < 8; i++)
	{
		sum += a[i];
		if (sum || i == 7)
		{
			if (a[i] < 10)
				j += _putchar(a[i] + '0');
			else
				j += _putchar(7 + a[i] + '0');
		}
	}
	return (j);
}
