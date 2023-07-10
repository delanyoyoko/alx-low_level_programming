#include <stdlib.h>
#include <string.h>

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
