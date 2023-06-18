#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{

for (int i = 1; i <= 9; i++)
{
putchar(',');
putchar(' ');
putchar(i + '0');
}

putchar('\n');
return (0);
}
