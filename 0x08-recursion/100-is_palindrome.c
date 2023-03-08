#include "main.h"
#include <stdio.h>
/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);
	
	if (len <= 1)
		return (1);

	if (*s == *(s + len - 1))
		return (is_palindrome(s + 1) && 1);

	return (0);
}
