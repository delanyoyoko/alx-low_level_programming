#include <stdlib.h>
#include <stddef.h>

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char
 * @size: the size of the memory to print
 * @c: the address of memory to print
 *
 * Return: A pointer to the array, or NULL if it fails.
 */
char *create_array(unsigned int size, char c)
{
char *array = (char *) malloc(size * sizeof(char));
unsigned int i;

if (size == 0)
{
return (NULL);
}

if (array == NULL)
{
return (NULL);
}

i = 0;

while (i < size)
{
array[i] = c;
i++;
}

return (array);
}
