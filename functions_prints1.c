#include "holberton.h"
/**
 * print_i - functions that prints digits
 * @formato: parameter to print
 * Return: counter
 */
int print_i(va_list formato)
{
	int arr[10];
	int i, value, num, sum, j;

	num = va_arg(formato, int);
	j = 0;
	value = 1000000000;
	arr[0] = num / value;
	for (i = 1; i < 10; i++)
	{
		value /= 10;
		arr[i] = (num / value) % 10;
	}
	if (num < 0)
	{
		_putchar('-');
		j++;
		for (i = 0; i < 10; i++)
			arr[i] *= -1;
	}
	for (i = 0, sum = 0; i < 10; i++)
	{
		sum += arr[i];
		if (sum != 0 || i == 9)
		{
			_putchar('0' + arr[i]);
			j++;
		}
	}
	return (j);
}

/**
 * print_d - prints a decimal
 * @formato: decimal to print
 * Return: number of digits printed and if negative adds the sign printed
 */
int print_d(va_list formato)
{
	int a[10];
	int i, value, num, sum, j;

	num = va_arg(formato, int);
	j = 0;
	value = 1000000000;
	a[0] = num / value;
	for (i = 1; i < 10; i++)
	{
		value /= 10;
		a[i] = (num / value) % 10;
	}
	if (num < 0)
	{
		_putchar('-');
		j++;
		for (i = 0; i < 10; i++)
			a[i] *= -1;
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
