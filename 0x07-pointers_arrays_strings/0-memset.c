#include "main.h"

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
char* _memset(char* s, char b, unsigned int n)
{
char* p = s;

for (unsigned int i = 0; i < n; i++)
{
p[i] = b;
}

return s;
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char c;

c = 'A';
printf("%c: %d\n", c, _isupper(c));

c = 'a';
printf("%c: %d\n", c, _isupper(c));
return (0);
}
