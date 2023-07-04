#include "main.h"
#include <stdio.h>

/**
 * _memset - fills memory with a constant byte.
 * @s: the size of the memory to print
 * @b: the address of memory to print
 * @n: the given length
 *
 * Return: s.
 */
char *_memset(char *s, char b, unsigned int n)
{
char *p = s;
unsigned int i = 0;

while (i < n)
{
p[i] = b;
i++;
}
return (s);
}
