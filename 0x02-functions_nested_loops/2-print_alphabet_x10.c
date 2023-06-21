#include <stdio.h>

int print_alpha_x10(void)
{
char letter = 'a';

for (int i = 0; i < 10; i++)
{
for (int j = 0; j < 26; j++)
{
putchar(letter);
letter++;
}
letter = 'a';
}

putchar('\n');
return (0);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
print_alpha_x10();
return (0);
}
