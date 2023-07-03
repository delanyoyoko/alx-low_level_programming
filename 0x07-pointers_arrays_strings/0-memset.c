#include "main.h"

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
char* _memset(char* s, char b, unsigned int n) {
    char* p = s; // Assign the pointer s to p

    for (unsigned int i = 0; i < n; i++) {
        p[i] = b; // Assign the constant byte b to each element of the memory area
    }

    return s; // Return a pointer to the memory area
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char c;

c = 'A';
printf("%c: %d\n", c, _isupper(c));

c = 'a';
printf("%c: %d\n", c, _isupper(c));
return (0);
}
