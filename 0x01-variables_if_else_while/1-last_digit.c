#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/* more headers goes there */

/* betty style doc for function main goes there */
int main(void)
{
int n;
int last;

srand(time(0));
n = rand() - RAND_MAX / 2;
last = n % 10;

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
if (n == 0)
{
printf("Last digit of %d is %d and is 0\n", n, last);
}
else if (n < 6)
{
printf("Last digit of %d is %d and is less than and not 0\n", n, last);
}
else if (n > 5)
{
printf("Last digit of %d is %d and is greater than 5\n", n, last);
}
return (0);
}
