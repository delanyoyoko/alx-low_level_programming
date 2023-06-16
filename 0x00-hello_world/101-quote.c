#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 1 (Error)
 */
int main(void)
{
const char var[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
write(2, var, sizeof(var) - 1);
return (1);
}
