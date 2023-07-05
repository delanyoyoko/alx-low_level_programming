#include <string.h>

/**
 * is_palindrome_helper - performs the actual
 * recursive calculation
 * @s: a pointer to a string
 * @start: the start of the string
 * @end: the end of the string
 *
 * Return: 1 0r 0
 */
int is_palindrome_helper(char *s, int start, int end)
{
if (start >= end)
{
return (1);
}

if (s[start] != s[end])
{
return (0);
}

return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_prime_number_helper - determines whether a string is
 * a palindrome
 * @s: the string
 *
 * Return: 1 0r 0
 */
int is_palindrome(char *s)
{
int length;
length = strlen(s);

if (length <= 1)
{
return (1);
}

return (is_palindrome_helper(s, 0, length - 1));
}
