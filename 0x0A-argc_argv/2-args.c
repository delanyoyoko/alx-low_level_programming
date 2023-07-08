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
int count;

count = 0;
while (count < argc)
{
printf("%s\n", argv[count]);
count++;
}

return (0);
}
