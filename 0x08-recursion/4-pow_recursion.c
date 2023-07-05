#include <stdio.h>

/**
 * _pow_recursion - determines the value of x raised to the power of y
 * @x: the base
 * @y: the exponent
 *
 * Return: x raised to the power of y, or Error
 */
int _pow_recursion(int x, int y)
{
if (y < 0)
{
return (-1);
}

if (y == 0)
{
return (1);
}
return (x * _pow_recursion(x, y - 1));
}
