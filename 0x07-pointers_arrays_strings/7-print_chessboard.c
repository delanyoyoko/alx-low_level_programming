#include <stdio.h>
#include "main.h"

/**
 * print_chessboard - prints a chessboard
 * @a: array of characters.
 *
 * Return: Notthing.
 */
void print_chessboard(char (*a)[8])
{
int i = 0;

while (i < 8)
{
int j = 0;

while (j < 8)
{
_putchar("%c ", a[i][j]);
j++;
}
_putchar("\n");
i++;
}
}
