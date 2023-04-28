#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
  * ****************************************
  * @**************************
  **************************************
  * ************************************
  */
unsigned int binary_to_uint(const char *b)
{
	unsigned int lt = 0;
	unsigned int counter = 0;
	unsigned int _sum = 0;

	if (b == NULL)
		return (0);

	lt = _strlen(b);
	while (lt--)
	{
		if (b[lt] != 48 && b[lt] != 49)
		return (0);

		if (b[lt] == 49)
		_sum += 1 << counter;

	counter++;
	}

	return (_sum);
}

/**
  * _strlen - /////////////*
  * @s: *******************
  ********************
  * **************
  */
int _strlen(const char *s)
{
	int a = 0;

	while (s[a])
		a++;

	return (a);
}
