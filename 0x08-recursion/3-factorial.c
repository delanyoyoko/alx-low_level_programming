#include <stdio.h>

/**
 * factorial - determines the factorial of a given number
 * @n: an integer
 *
 * Return: Factorial of a given number or Error
 */
int factorial(int n)
{
if (n < 0)
{
return (-1);
}

if (n == 0)
{
return (1);
}
return (n * factorial(n - 1));
}
