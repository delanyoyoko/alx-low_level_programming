#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int number;

for (number = 1; number <= 9; number++)
{
putchar(number + '0');
putchar(',');
putchar(' ');
}

putchar('\n');
return (0);
}
