#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int number;

putchar('0');

for (number = 1; number <= 9; number++)
{
putchar(',');
putchar(' ');
putchar(number + '0');
}

putchar('\n');
return (0);
}
