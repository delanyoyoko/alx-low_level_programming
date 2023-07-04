/**
 * _strchr - locates a character in a string
 * @s - the string.
 * @c - the character to search.
 *
 * Return: A pointer to the first occurrence of the char in the string, or NULL.
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}

if (*s == c)
{
return (s);
}
return (NULL);
}
