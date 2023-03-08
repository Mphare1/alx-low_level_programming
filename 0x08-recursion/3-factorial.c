#include "main.h"
#include <stdio.h>
/**
 * factorial - computes the factorial of a given number
 * @n: the number to compute the factorial of
 *
 * Return: the factorial of n, or -1 if n is negative
 */
int factorial(int n)
{
    if (n < 0) {
        return -1;  // error: factorial is undefined for negative numbers
    }
    if (n == 0) {
        return 1;   // base case: factorial of 0 is 1
    }
    return n * factorial(n - 1); // recursive case: n! = n * (n-1)!
}
