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
int cents;
int numCoinTypes;
int numCoins;
int i;
int numCurrentCoins;
int coinValues[5] = {25, 10, 5, 2, 1};

if (argc != 2)
{
printf("Error\n");
return (1);
}

cents = atoi(argv[1]);

if (cents < 0)
{
printf("0\n");
return (0);
}

numCoins = 0;
numCoinTypes = sizeof(coinValues) / sizeof(coinValues[0]);

i = 0;
while (i < numCoinTypes)
{
numCurrentCoins = cents / coinValues[i];
numCoins += numCurrentCoins;
cents -= multiply(numCurrentCoins, coinValues[i]);
i++;
}

printf("%d\n", numCoins);

return (0);
}

