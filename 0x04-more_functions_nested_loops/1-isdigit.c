#include "main.h"

/**
 * isdigit - Check if is a digit
 * @i: The number to be checked
 * Return: 1 for a character that will be a digit or 0 for any else
 */

int _isdigit(int i)

{

	if (i >= 48 && i <= 57)
	{
	return (1);
	}
	else
	return (0);
}
