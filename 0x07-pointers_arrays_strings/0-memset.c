#include "main.h"
#include <stdio.h>

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
char buffer[10];
char constant = 'A';

_memset(buffer, constant, sizeof(buffer));
printf("Buffer: %s\n", buffer);
return 0;
}
