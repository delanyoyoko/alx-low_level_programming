#include "main.h"
#include <stdio.h>


/**
 * main - check the code
 *
 * Return: Always 0.
 */
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char buffer[10];
char constant = 'A';

_memset(buffer, constant, sizeof(buffer));
printf("Buffer: %s\n", buffer);
return 0;
}
