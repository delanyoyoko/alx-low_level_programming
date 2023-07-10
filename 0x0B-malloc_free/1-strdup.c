#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * _strdup - make a pointer to a newly allocated
 * space in memory
 * @str: the input string
 *
 * Return: A pointer to a newly allocated space in memory.
 */

char *_strdup(char *str)
{
size_t length = strlen(str) + 1;
char *duplicate = (char *) malloc(length * sizeof(char));

if (str == NULL)
{
return (NULL);
}

if (duplicate == NULL)
{
return (NULL);
}

strcpy(duplicate, str);

return (duplicate);
}
