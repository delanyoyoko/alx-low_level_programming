#include <stddef.h>
#include <string.h>

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string
 * @accept: the predicate to accept
 *
 * Return: The number of bytes in the initial segment of s.
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int length = 0;

while (*s != '\0' && strchr(accept, *s) != NULL)
{
length++;
s++;
}
return (length);
}
