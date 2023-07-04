#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * set_string - sets the value of a pointer to a char
 * @s: a double pointer of string
 * @to: a pointer of string
 *
 * Return: Nothing
 */
void set_string(char **s, char *to)
{
size_t len = strlen(to) + 1;
char *temp = realloc(*s, len);

if (temp == NULL)
{
printf("Memory allocation failed.\n");
return;
}

*s = temp;
strcpy(*s, to);
}
