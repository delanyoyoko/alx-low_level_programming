#include <stddef.h>
#include <string.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search.
 * @accept: the predicate.
 *
 * Return: Pointer to the byte in s matches one of the bytes in accept
 */
char *_strpbrk(char *s, char *accept)
{
while (*s != '\0')
{
if (strchr(accept, *s) != NULL)
{
return (s);
}
s++;
}
return (NULL);
}
