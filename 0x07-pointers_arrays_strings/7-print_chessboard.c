#include <stdio.h>

/**
 * print_chessboard - prints a chessboard
 * @a: array of characters.
 *
 * Return: Always 0.
 */
void print_chessboard(char (*a)[8])
{
int i = 0;

while (i < 8)
{
int j = 0;

while (j < 8)
{
printf("%c ", a[i][j]);
j++;
}
printf("\n");
i++;
}
return (0)
}
