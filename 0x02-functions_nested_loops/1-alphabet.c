#include <stdio.h>

int print_alpha(void)
{
char letter;

for (letter = 'a'; letter <= 'z'; letter++)
{
putchar(letter);
}
return (0)
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
print_alpha()
putchar('\n');
return (0);
}
