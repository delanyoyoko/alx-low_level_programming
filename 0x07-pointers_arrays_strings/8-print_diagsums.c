#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: a pointer to the first element of the matrix
 * @size: the size of the matrix
 *
 * Return: Always 0.
 */
void print_diagsums(int *a, int size)
{
int sum1 = 0;
int sum2 = 0;

int i = 0;
while (i < size)
{
sum1 += a[i * size + i];
sum2 += a[i * size + (size - 1 - i)];
i++;
}

printf("Sum of the main diagonal: %d\n", sum1);
printf("Sum of the secondary diagonal: %d\n", sum2);
}
