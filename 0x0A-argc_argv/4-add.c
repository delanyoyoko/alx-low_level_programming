#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - prints its name
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
int sum;
int num;
int i;
int j;


if (argc == 1)
{
printf("0\n");
return (0);
}

sum = 0;
i = 1;
while (i < argc)
{
j = 0;

while (argv[i][j] != '\0')
{
if (!isdigit(argv[i][j]))
{
printf("Error\n");
return (1);
}
j++;
}

num = atoi(argv[i]);
sum += num;
i++;
}

printf("%d\n", sum);

return (0);
}
