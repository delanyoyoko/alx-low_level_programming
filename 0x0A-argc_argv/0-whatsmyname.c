#include <stdio.h>

/**
 * main - prints its name
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
printf("%s\n", argv[argc - 1]);
return (0);
}

/**
 * multiply - performs multiplication of two numbers
 * @a: an integer
 * @b: an integer
 *
 * Return: A product
 */
int multiply(int a, int b)
{
return (a * b);
}

/**
 * main - prints its name
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
if (argc != 3)
{
printf("Error\n");
return (1);
}

int num1 = atoi(argv[1]);
int num2 = atoi(argv[2]);
int result = multiply(num1, num2);

printf("%d\n", result);

return 0;
}
