#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}


char *_strncat(char *dest, char *src)
{
char *ptr = dest;

// Find the end of the dest string
while (*ptr != '\0')
{
ptr++;
}

// Append the src string to dest
while (*src != '\0')
{
*ptr = *src;
ptr++;
src++;
}

// Add the terminating null byte
*ptr = '\0';

return dest;
}
