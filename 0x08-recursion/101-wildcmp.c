/**
 * wildcmp_helper - helper to compares two strings
 * @s1: a pointer to the first string
 * @s2: a pointer to the second string
 *
 * Return: 1 0r 0
 */
int wildcmp_helper(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
{
return (1);
}

if (*s1 == *s2 || *s2 == '*')
{
return (wildcmp_helper(s1 + 1, s2 + 1));
}

if (*s2 == '*')
{
if (wildcmp_helper(s1, s2 + 1) == 1)
{
return (1);
}

if (*s1 != '\0' && wildcmp_helper(s1 + 1, s2) == 1)
{
return (1);
}
}

return (0);
}

/**
 * wildcmp - compares two strings
 * @s1: a pointer to the first string
 * @s2: a pointer to the second string
 *
 * Return: 1 0r 0
 */
int wildcmp(char *s1, char *s2)
{
return (wildcmp_helper(s1, s2));
}
