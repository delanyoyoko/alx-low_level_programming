/**
 * _strchr - locates a character in a string
 * @s - the string.
 * @c - the character to search.
 *
 * Return: A pointer to the first occurrence of the character in the string, or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return s;
}
s++;
}

if (*s == c)
{
return s;
}
return NULL;
}
