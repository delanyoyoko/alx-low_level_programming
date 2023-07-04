#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: the string.
 * @needle: the substring.
 *
 * Return: A pointer to the beginning of the located substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
while (*haystack != '\0')
{
char *h = haystack;
char *n = needle;

while (*n != '\0' && *h == *n)
{
h++;
n++;
}

if (*n == '\0')
{
return (haystack);
}
haystack++;
}
return (NULL);
}
