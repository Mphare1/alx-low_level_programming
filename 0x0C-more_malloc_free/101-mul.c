#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
 int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * print_error - prints an error message and exits with status 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - multiplies two numbers represented as strings
 * @num1: the first number
 * @num2: the second number
 * Return: a pointer to the result string
 */
char *multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry = 0;
	char *result;

	while (num1[len1])
	{
	if (!_isdigit(num1[len1]))
			print_error();
		len1++;
	}
	while (num2[len2])
	{
		if (!_isdigit(num2[len2]))
			print_error();
		len2++;
	}
	result = calloc(len1 + len2 + 1, sizeof(char));
	if (result == NULL)
			print_error();
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i] += carry;
	}
	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;
	if (i == len1 + len2)
	{
		free(result);
		return ("0");
	}
	for (j = 0; j < len1 + len2 - i; j++)
		result[j] += '0';
	return (result + i);
}
